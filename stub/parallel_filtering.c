/**
 * READ THE README FIRST
 * READ THE README IT HAS IMPORTANT INFORMATION
 * I PROMISE READING THE README FIRST IS BEST!!
 * READ THE README
 *
 * @authors Dr. Sidharth Kumar, Michael Gathara, Akshar Patel & Dr. Mahmut Unan
 * @brief Parallel Image Filtering Stub
 *
 * This file is a stub for parallel image filtering.
 * 
 * TODO:
 *  - Implement file reading using fopen, fseek, ftell, and fread.
 *  - Implement the blurring/filtering operation using the provided stencil size.
 *  - Implement file writing using fopen and fwrite.
 */

#include <ctype.h>
#include <fcntl.h>
#include <mpi.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void parse_args(int argc, char **argv);

// Global dimension of dataset 25600 x 25600
static int gbs[2] = {2560, 2560};

// Default of 1 (WE WILL CHANGE THIS TO TEST YOUR CODE)
static int stencil_size = 3;

// Name of file to read
static char file_name[512] = "../data/brain_2560_2560.raw";

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    parse_args(argc, argv);

    printf("Rank %d nprocs %d\n", rank, nprocs);


    // READ THE FILE IN PARALLEL
    double io_read_start = MPI_Wtime();




    // STEPS
    // How do you know where in file you want to read the data from
    // Need to compute "offset" in the file where one needs to read (hint: use
    // the rank) Compute the "size" of the local buffer (hint: global image size
    // / nprocs). The size of buffer can also include space for ghost cells
    // (your choice). In case you are allocating buffer for both local image
    // data + ghost cell, then remember that processes with rank 0 and nprocs -
    // 1 will only have one layer of ghost cells as compared to other processes
    // which will have two layers of ghost cells (above and below). allocate
    // local "buffer" to store image data

    // Try posix IO
    // open https://linux.die.net/man/3/open
    // pread https://man7.org/linux/man-pages/man2/pread.2.html
    // close

    // nprocs = 4


    int total_file_size = gbs[0] * gbs[1];   

    int of = (total_file_size / nprocs) * rank;

    int buffer_size = total_file_size / nprocs; 

    unsigned char *buffer = malloc(buffer_size); 
    if (!buffer) {
       printf("Failed buffer output");

    }
    int ghost_size = (stencil_size / 2) * gbs[1] * sizeof(unsigned char);

    int fp = open(file_name, O_RDONLY);
    if (fp == -1) {
       printf("Failed to open file \n");
    }
    pread(fp, buffer + (rank == 0 ? 0 : ghost_size), buffer_size, of);
    close(fp);
   

    double io_read_end = MPI_Wtime();

    // GHOST (HALO) CELL EXCHANGE
    // Allocate buffer to recieve data from neighboring process (hint: will
    // depend on the stencil point size), or use the local buffer of previous
    // step to recieve halo data Identify rank of neighboring process (hint:
    // rank - 1 and rank + 1) Make sure you consider the edge processes rank 0
    // and rank nprocs - 1, they will recieve and send data from only one
    // process instead of two processes Use MPI_Isend and MPI_Irecv for
    // communication You can or cannot use MPI datatypes for communication
    double communication_start = MPI_Wtime();

    int rows_per = gbs[0] / nprocs;

    int top = rank - 1;
    int bot = rank + 1;


    int halo_row = gbs[1];
    MPI_Request reqs[4];


    int local_rows = rows_per;
    if (rank == 0 || rank == nprocs - 1) {
        local_rows = local_rows + 1; 
    } else {
        local_rows = local_rows + 2; 
    }


    int count = 0;

    if (top >= 0){
        MPI_Irecv(buffer, halo_row, MPI_UNSIGNED_CHAR, top, 0, MPI_COMM_WORLD, &reqs[count++]);
    }
    
    if(bot < nprocs) {
        int recieved_halorow = (rank == nprocs -1) ? rows_per : rows_per + 1;

        MPI_Irecv(buffer + (recieved_halorow  * gbs[1]), halo_row , MPI_UNSIGNED_CHAR, bot, 1, MPI_COMM_WORLD, &reqs[count++]);
    }

    if (top >= 0){
        MPI_Isend(buffer, halo_row, MPI_UNSIGNED_CHAR, top, 0, MPI_COMM_WORLD, &reqs[count++]);
    }

    if(bot < nprocs) {
        int sent_halorow;
        if (rank == nprocs -1)
            sent_halorow = rows_per - 1;
        else
            sent_halorow = rows_per;

        MPI_Isend(buffer + (sent_halorow  * gbs[1]), halo_row , MPI_UNSIGNED_CHAR, bot, 0, MPI_COMM_WORLD, &reqs[count++]);
    }    

    if (count > 0) {
    MPI_Waitall(count, reqs, MPI_STATUSES_IGNORE);
    }

    double communication_end = MPI_Wtime();

    // PERFORM THE ACTUAL BLURING OPERATION
    // allocate a new buffer of size equal to local "buffer", that will store
    // the value of the blured image You can skip the border pixels for bluring.
    // Start from (1,1) to (25600 - 1, 25600 - 1) My pixel value = (my pixel
    // value) / 9 + (sum of all neigbor pixel value) / 9 To perform the previous
    // step you need to use the ghost cell you obtained in the previous step
    double compute_start = MPI_Wtime();

    int half_size = stencil_size / 2;

 
    unsigned char *blur_buffer = malloc(buffer_size);

    for (int i = half_size; i < rows_per - half_size; i++) {
        for (int j = half_size; j < gbs[1] - half_size; j++) {
                int sum = 0;
                int loop_count = 0;
            for (int k = -half_size; k <= half_size; k++) {
                for (int l = -half_size; l <= half_size; l++) {

                    sum = sum + buffer[(i + k) * gbs[1] + (j + l)];
                    loop_count++;
                }
            }
            blur_buffer[i  * gbs[1] + j] = sum / loop_count;
        }
    }
    
    double compute_end = MPI_Wtime();

    // WRITE THE FILE IN PARALLEL (EXACT OPPOSITE of THE FIRST STEP)
    // STEPS
    // How do you know where in file you want to write the data to
    // Need to compute "offset" in the file where one needs to write (hint: use
    // the rank) You already know the "size" of the local buffer (hint: global
    // image size / nprocs)

    // Try out both collective writes (using MPI_File_write_at_all) and one
    // without collectives (using MPI_write_read_at) MPI_File_open
    // MPI_File_write_at_all(..., offset, buffer, size, ..., MPI_UNSIGNED_CHAR,
    // ....) MPI_File_close()



    double io_write_start = MPI_Wtime();
    MPI_File fh;
    MPI_File_open(MPI_COMM_WORLD, "brain_2560_2560_blurred.raw", MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &fh);
    MPI_File_write_at_all(fh, of, blur_buffer, buffer_size, MPI_UNSIGNED_CHAR, MPI_STATUS_IGNORE);
    MPI_File_close(&fh);


    double io_write_end = MPI_Wtime();

    double total_time = io_write_end - io_read_start;
    double max_time;
    MPI_Allreduce(&total_time, &max_time, 1, MPI_DOUBLE, MPI_MAX,
                  MPI_COMM_WORLD);
    if (max_time == total_time) {
        printf(
            "Time take to blur %d x %d image is %f\n"
            "Time decomposistion (IO + COMM + COMP + IO): %f + %f + %f + %f\n",
            gbs[0], gbs[1], max_time, (io_read_end - io_read_start),
            (communication_end - communication_start),
            (compute_end - compute_start), (io_write_end - io_write_start));
    }
    free(buffer);
    free(blur_buffer);
    MPI_Finalize();
}

static void parse_args(int argc, char **argv) {
    char flags[] = "g:s:f:";
    int one_opt = 0;
    int with_rst = 0;

    while ((one_opt = getopt(argc, argv, flags)) != EOF) {
        /* postpone error checking for after while loop */
        switch (one_opt) {
            case ('g'):  // global dimension
                if ((sscanf(optarg, "%dx%dx%d", &gbs[0], &gbs[1], &gbs[2]) ==
                     EOF))
                    exit(-1);
                break;

            case ('s'):  // local dimension
                if ((sscanf(optarg, "%d", &stencil_size) == EOF)) exit(-1);
                break;

            case ('f'):  // input file name
                if (sprintf(file_name, "%s", optarg) < 0) exit(-1);
                break;
        }
    }
}
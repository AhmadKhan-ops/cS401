/**
 * READ THE README FIRST
 * READ THE README IT HAS IMPORTANT INFORMATION
 * I PROMISE READING THE README FIRST IS BEST!!
 * READ THE README
 *
 * @authors Dr. Sidharth Kumar, Michael Gathara, Akshar Patel & Dr. Mahmut Unan
 * @brief Serial Image Filtering Stub
 *
 * This file is a stub for serial image filtering.
 * 
 * TODO:
 *  - Implement file reading using fopen, fseek, ftell, and fread.
 *  - Implement the blurring/filtering operation using the provided stencil size.
 *  - Implement file writing using fopen (in binary mode) and fwrite.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Global dimensions of dataset (e.g., 2560 x 2560)
static int gbs[2] = {2560, 2560};

// Default stencil size
static int stencil_size = 3;

// Name of the input file to read
static char file_name[64] = "data/brain_2560_2560.raw";

// Function prototype
static void parse_args(int argc, char **argv);

int main(int argc, char **argv) {
    // Parse command-line arguments
    parse_args(argc, argv);
    
    printf("Serial Filtering: Processing file %s\n", file_name);
    printf("Image Dimensions: %d x %d, Stencil Size: %d\n", gbs[0], gbs[1], stencil_size);
    
    // READ THE FILE
    clock_t io_read_start = clock();
    // TODO: Open the input file using fopen("rb") and read the image data into a buffer.
    // Hint: Use fseek, ftell, and fread.
    // Allocate a buffer to put your blurred image
    clock_t io_read_end = clock();
    
    // PERFORM THE BLURRING OPERATION
    clock_t compute_start = clock();
    // TODO: 
    //  - Allocate a new buffer to store the blurred image.
    //  - Implement the blurring filter:
    //      For each non-border pixel, compute the average of the current pixel and its neighbors
    //      using the given stencil_size.
    clock_t compute_end = clock();
    
    // WRITE THE FILE
    clock_t io_write_start = clock();
    // TODO: Open an output file using fopen and write the blurred image to it.
    // Hint: Make sure you open the file in the right mode
    // file name "brain_2560_2560_blurred.raw".
    clock_t io_write_end = clock();
    
    // Calculate time decomposition
    double readTime = (double)(io_read_end - io_read_start) / CLOCKS_PER_SEC;
    double compTime = (double)(compute_end - compute_start) / CLOCKS_PER_SEC;
    double writeTime = (double)(io_write_end - io_write_start) / CLOCKS_PER_SEC;
    double totalTime = readTime + compTime + writeTime;
    
    printf("Time decomposition (IO + COMP + IO): %f + %f + %f = %f seconds\n",
           readTime, compTime, writeTime, totalTime);
    
    return 0;
}

static void parse_args(int argc, char **argv) {
    char flags[] = "g:s:f:";
    int one_opt = 0;
    
    while ((one_opt = getopt(argc, argv, flags)) != -1) {
        switch (one_opt) {
            case 'g':
                // Parse global dimensions in the format: WxH (e.g., 2560x2560)
                if (sscanf(optarg, "%dx%d", &gbs[0], &gbs[1]) != 2) {
                    fprintf(stderr, "Error parsing global dimensions.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 's':
                // Parse stencil size as an integer
                if (sscanf(optarg, "%d", &stencil_size) != 1) {
                    fprintf(stderr, "Error parsing stencil size.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'f':
                // Parse file name
                if (sscanf(optarg, "%s", file_name) != 1) {
                    fprintf(stderr, "Error parsing file name.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                fprintf(stderr, "Usage: %s -g <global_dimensions WxH> -s <stencil_size> -f <file_path>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}
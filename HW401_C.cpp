#include <iostream>
#include <string>
#include <list>
using namespace std;


class archINVIN {
public:

	string name;
	double price;
	int availability;

public:

	archINVIN(string name , double price, int availability) : name(name), price(price), availability(availability) {}
	virtual void over() = 0;

	string get_name() {
		return name;
	}

	double get_price() {
		return price;

	}
	int get_availability() {
		return availability;

	}
};


class ItemCate {
private:

	string name;
	list<archINVIN*> itemlist;
	list<ItemCate*> subcate;

public:
	ItemCate(string name) : name(name) {}
	string get_name() {
		return name;
	}

	list<archINVIN*>& get_itemlist() {
		return itemlist;
	}

	list<ItemCate*>& get_subcate() {
		return subcate;
	}
	void add_item(archINVIN* item) {

		itemlist.push_back(item);

	}
	void add_subcate(ItemCate* sub) {

		subcate.push_back(sub);

	}
};


class Volleyball : public archINVIN {

	string material;
	string VolleyBallsize;

public:

	Volleyball(string name, double price, int availability, string material, string VolleyBallsize) : archINVIN(name, price, availability), material(material), VolleyBallsize(VolleyBallsize) {}
	void over() override {
		cout << "VolleyBall -> Name: " << name << " Price: " << price << " Avability: " << availability << " Material: " << material  << " Size: " << VolleyBallsize << "\n";
	}
};

class VolleyballNET : public archINVIN {
    
	string NetType;

public:

	VolleyballNET(string name, double price, int availability, string NetType) : archINVIN(name, price, availability), NetType(NetType) {}
	void over() override {
		cout << "VolleyBall Net -> Name: " << name<< " Price: " << price<< " Avability: " << availability << " Type: " << NetType << "\n";
	}
};

class Table : public archINVIN {

	string Tablesize;

public:

	Table(string name, double price, int availability, string Tablesize) : archINVIN(name, price, availability), Tablesize(Tablesize) {}
	void over() override {
		cout << "Table -> Name: " << name << " Price: " << price << " Avability: " << availability << " Size: " << Tablesize << "\n";
		if (availability == 0)
			cout << "Not enough tables to play table tennis" << "\n";
	}
};

class Paddle : public archINVIN {

	string PaddleType;

public:

	Paddle(string name, double price, int availability, string PaddleType) : archINVIN(name, price, availability), PaddleType(PaddleType) {}
	void over() override {
		cout << "Table tennis paddle -> Name: " << name << " Price: " << price << " Avability: " << availability << " Type: " << PaddleType << "\n";
		if (availability < 2)
			cout << "Not enough Paddles to play table tennis" << "\n";
	}
};

class TableBall : public archINVIN {
    
public:
	TableBall(string name, double price, int availability) : archINVIN(name, price, availability) {}
	void over() override {
		cout << "Table tennis ball -> Name: " << name << " Price: " << price << " Avability: " << availability << "\n";
		if (availability == 0)
			cout << "Not enough balls to play table tennis" << "\n";
	}
};


class Tent : public archINVIN {
    
	string durability;
	string weather_rating;
	string Tentsize;

public:

	Tent(string name , double price, int availability, string durability, string weather_rating, string Tentsize) : archINVIN(name, price, availability), durability(durability), weather_rating(weather_rating), Tentsize(Tentsize) {}
	void over() override {
		cout << "Tent -> Name: " << name << " Price: " << price << " Avability: " << availability << " Size: " << Tentsize << " Weather Rating: " << weather_rating << " Durability: " << durability << "\n";
		
	}
};

class Soccerball : public archINVIN {
    
	string Soccermaterial;
	int teamsize;
public:

	Soccerball(string name , double price, int availability, string Soccermaterial, int teamsize) : archINVIN(name, price, availability), Soccermaterial(Soccermaterial), teamsize(teamsize) {}
	void over() override {
		if (teamsize > 10) {
			cout << "Enjoy a 15 percent discount on Soccerballs!" << "\n";
			price = price * .85;
		}
		if (teamsize > 25) {
			cout << "Enjoy a 30 percent discount on Soccerballs!" << "\n";
			price = price * .70;
		}
		cout << "SoccerBall -> Name: " << name << " Price: " << price << " Avability: " << availability << " Material: " << Soccermaterial << "\n";
	}
};

class SoccerNET : public archINVIN {

	string SoccerSize;
	int teamsize;

public:

	SoccerNET(string name , double price, int availability, string SoccerSize, int teamsize) : archINVIN(name, price, availability), SoccerSize(SoccerSize), teamsize(teamsize) {}
	void over() override {
		if (teamsize > 10) {
			cout << "Enjoy a 15 percent discount on Soccer Nets!" << "\n";
			price = price * .85;
		}
		if (teamsize > 25) {
			cout << "Enjoy a 30 percent discount on Soccer Nets!" << "\n";
			price = price * .70;
		}
		cout << "Soccerball Goal Net -> Name: " << name << " Price: " << price << " Avability: " << availability << " Size: " << SoccerSize << "\n";
	}
};


void Sell(archINVIN* item, int amount) {
    
	if (item->availability >= amount) {

		item->availability = item->availability - amount;

		cout << "Sold " << amount << " of " << item->name << "\n";
	}
	else {
		cout << "Not enough Stock of " << item->name << "\n";

	}
}

void Add(archINVIN* item, int amount) {
    
	item->availability = item->availability + amount;
	cout << "New stock of " << item->name << " is: " << item->availability << "\n";
}



int main() {
	ItemCate Indoor_Sports("Indoor Sports");
	ItemCate Outdoor_Sports("Outdoor Sports");


	Volleyball* Volley_Ball = new Volleyball("Super Cool Volleyball", 67, 4, "metal", "large");
	VolleyballNET* Volley_Net = new VolleyballNET("Normal Volleyball Net", 15, 6, "rope");
	Table* Table_ = new Table("Table Tenis basic Table", 200, 3, "large");
	Paddle* Paddle_ = new Paddle("Worn Down paddle", 6, 10, "Beginner");
	TableBall* Table_T_Ball = new TableBall("4 pck of Balls", 4, 10);


	Tent* Camp_tent = new Tent("Extreme Tent", 400, 1, "Exremely Durable", "Large", "Suited for extreme Weather");
	Soccerball* Soccer_Ball = new Soccerball("Normal SoccerBall", 20, 30, "Iron Plastic", 18);
	SoccerNET* Soccer_Net = new SoccerNET("SoccerBall Net", 80, 6, "medium", 18);
	
	
	
	Indoor_Sports.add_item(Volley_Ball);
	Indoor_Sports.add_item(Volley_Net);
	Indoor_Sports.add_item(Table_);
	Indoor_Sports.add_item(Paddle_);
	Indoor_Sports.add_item(Table_T_Ball);
	
	Outdoor_Sports.add_item(Camp_tent);
	Outdoor_Sports.add_item(Soccer_Ball);
	Outdoor_Sports.add_item(Soccer_Net);



	for (auto item : Indoor_Sports.get_itemlist())
		item->over();

	for (auto item : Outdoor_Sports.get_itemlist())
		item->over();


	Sell(Paddle_, 2);
	Add(Table_, 5);


	return 0;
}

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

    archINVIN(string n, double p, int a) : name(n), price(p), availability(a) {}
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
    ItemCate(string n) : name(n) {}
    string get_name() { 
        return name; 
    }
    
    list<archINVIN*>& get_itemlist() { 
        return itemlist; 
    }
    
    list<ItemCate*>& get_subcate() { return subcate; }
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

	Volleyball(string n, double p, int a, string m, string size) : archINVIN(n, p, a), material(m), VolleyBallsize(size) {}
	void over() override {
		cout << "VolleyBall -> Name: " << name << " Price: " << price << " Avability: " << availability << " Material: " << material  << " Size: " << VolleyBallsize << "\n";
	}
};

class VolleyballNET : public archINVIN {
    
	string NetType;

public:

	VolleyballNET(string n, double p, int a, string nt) : archINVIN(n, p, a), NetType(nt) {}
	void over() override {
		cout << "VolleyBall Net -> Name: " << name<< " Price: " << price<< " Avability: " << availability << " Type: " << NetType << "\n";
	}
};

class Table : public archINVIN {

	string Tablesize;

public:

	Table(string n, double p, int a, string size) : archINVIN(n, p, a), Tablesize(size) {}
	void over() override {
		cout << "Table -> Name: " << name << " Price: " << price << " Avability: " << availability << " Size: " << Tablesize << "\n";
		if (availability == 0)
			cout << "Not enough tables to play table tennis" << "\n";
	}
};

class Paddle : public archINVIN {

	string PaddleType;

public:

	Paddle(string n, double p, int a, string type) : archINVIN(n, p, a), PaddleType(type) {}
	void over() override {
		cout << "Table tennis paddle -> Name: " << name << " Price: " << price << " Avability: " << availability << " Type: " << PaddleType << "\n";
		if (availability < 2)
			cout << "Not enough Paddles to play table tennis" << "\n";
	}
};

class TableBall : public archINVIN {
    
public:
	TableBall(string n, double p, int a) : archINVIN(n, p, a) {}
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

	Tent(string n, double p, int a, string d, string w, string t) : archINVIN(n, p, a), durability(d), weather_rating(w), Tentsize(t) {}
	void over() override {
		cout << "Tent -> Name: " << name << " Price: " << price << " Avability: " << availability << " Size: " << Tentsize << " Weather Rating: " << weather_rating << " Durability: " << durability << "\n";
		
	}
};

class Soccerball : public archINVIN {
    
	string Soccermaterial;
	int teamsize;
public:

	Soccerball(string n, double p, int a, string m, int t)
		: archINVIN(n, p, a), Soccermaterial(m), teamsize(t) {}
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

	SoccerNET(string n, double p, int a, string s, int t) : archINVIN(n, p, a), SoccerSize(s), teamsize(t) {}
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

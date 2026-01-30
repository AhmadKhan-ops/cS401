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

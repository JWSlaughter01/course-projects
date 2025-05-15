/******************************************************************************
Product.cpp

class Product
{
private:
    string PLU;
    string name;
    int type;
    double price;
    int inventory;
public:
    void setProductAttributes(string, string, int, double, int);
    void setInventory(int);
    string getPLU() const;
    string getName() const;
    int getType() const;
    double getPrice() const;
    int getInventory() const;
};
*******************************************************************************/
//include access to class file
#include "Product.h"
#include <string>

using namespace std;

//Product Constructor
// Product::Product() {
//     cout << "Welcome from the Constructor..." << endl;
// }

// //Product Deconstructor
// Product::~Product() {
//     cout << "Goodbye from the Deconstructor..." << endl;
// }

/*
Setter/Mutator functions
changes variable in differnet functions

setProductAttributes
setInventory
*/
void Product::setProductAttributes(std::string PLU, std::string name, int type, double price, int inventory) {
    this->PLU = PLU;
    this->name = name;
    this->type = type;
    this->price = price;
    this->inventory = inventory;
}

void Product::setInventory(int inventory) {
    this->inventory = inventory;
}


/*
Getter/Accessor functions
returns type in name of function

getPLU
getName
getType
getPrice
getInventory
*/
std::string Product::getPLU() const{
    return PLU;
}

std::string Product::getName() const{
    return name;
}

int Product::getType() const{
    return type;
}

double Product::getPrice() const{
    return price;
}

int Product::getInventory() const{
    return inventory;
}

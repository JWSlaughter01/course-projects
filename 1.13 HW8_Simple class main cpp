/******************************************************************************
Main.cpp

Prompt the user for a file name. 
Read the file to determine the number of records in the file. If the file open is unsuccessful, print an error message and terminate.
Dynamically allocate an array of Product objects, with a size equal to the number of records, and populate the array with the items read from the file by using the appropriate mutator(s).  
Then print the array. For name use setw(17) and left. The remaining parameters are printed right. For price use setw(5) so that your output will match with the testcase.
Loop on displaying the following menu of choices:
1.    Add to inventory
2.    Subtract from inventory
3.    Print info for all products
4.    Exit


For the extra credit, your main function should implement, in addition to the basic version, the following feature. If the user chooses 4, the program does not terminate immediately, 
but prints the history of the past transactions up to 5, then terminates. A transaction is an addition to the inventory level or a subtraction from the inventory level. 
Transactions that are not made due to invalid input should not be printed. The program should print the transaction #, the PLU, the transaction type (addition or subtraction), 
and the actual amount added or subtracted. The transaction # is a sequence number assigned to each transaction that is actually executed, starting from 1 for the first transaction. 
The transactions should be printed from most recent to least recent. If more than 5 transactions were executed, only the 5 most recent transactions are printed.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

//include product class
#include "Product.h"

//global variables for use with history
//made it much easier to have the functions access these for the extra credit section
int historyCounter = 0;
string history[10];

//function prototypes
void printProduct(Product*, int);
void displayMenu();
void addInventory(Product*, int);
void subInventory(Product*, int);
void printHistory();


int main()
{
    string filename;
    string line;
    int numProducts = 0;
    
    
    cout << "Enter the file name: ";
    cin >> filename;
    //turning line below into a comment
    //cout << endl;
    
    //variables for inputing into products
    string PLU, name;
    int type, inventory;
    double price;
    
    ifstream file;
    
    //checking if file is opened or not
    file.open(filename);
    if(!file) {
        //If the file open is unsuccessful, print an error message and terminate
        cout << "Cannot open file" << endl;
        return 1;
    }
    
    //very similar setup to IC9, scanning to read the number of lines in the file
    while (getline(file, line)) {
        numProducts++;
    }
    
    cout << "There are " << numProducts << " records in the file" << endl << endl;
    
    //moving pointer back to start of file
    file.clear();
    file.seekg(0);
    
    //Dynamically allocate an array of Product objects, with a size equal to the number of records
    Product* products = new Product[numProducts];
    
    //populate the array with the items read from the file by using the appropriate mutator(s)
    //still very similar to IC9
    int i = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> PLU >> name >> type >> price >> inventory;
        products[i].setProductAttributes(PLU, name, type, price, inventory);
        i++;
    }
    
    file.close();
    
    //Then print the array. For name use setw(17) and left. The remaining parameters are printed right. For price use setw(5) so that your output will match with the testcase
    cout << "Content of object array" << endl << "-----------------------" << endl;
    printProduct(products, numProducts);
    
    int choice;
    bool rerun = true;
    //looping until flagged
    while (rerun) {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                addInventory(products, numProducts);
                break;
            case 2:
                subInventory(products, numProducts);
                break;
            case 3:
                cout << "Current inventory" << endl << "-----------------" << endl;
                printProduct(products, numProducts);
                break;
            case 4:
                rerun = false;
                printHistory();
                break;
            default: //I didn't notice any example in the expected output for any of the tests
                break;
        }
    }
    
    //delete dynamically allocated memory
    delete[] products;
    return 0;
}

//For name use setw(17) and left. The remaining parameters are printed right. For price use setw(5) so that your output will match with the testcase
void printProduct(Product* products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        cout << "PLU: " << products[i].getPLU() << ", " << setw(17) << left << products[i].getName() << ", type: "
        << products[i].getType() << ", unit price: " << setw(5) << right << products[i].getPrice() << ", inventory: " <<
        products[i].getInventory() << endl;
    }
}

//function for displaying menu
void displayMenu() {
    cout << endl << "Menu" << endl << "----" << endl;
    cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
    cout << "3->Print info for all products, 4->Exit" << endl;
}

//function to add to inventory
void addInventory(Product* products, int numProducts) {
    string PLU;
    int amount, index;
    bool found = false;
    
    cout << "Enter the PLU: ";
    cin >> PLU;
    //starting by checking if PLU is in the file
    for (int i = 0; i < numProducts; i++) {
        if (products[i].getPLU() == PLU) {
            index = i;
            found = true;
            break;
        }
    } //if not..
    if (!found) {
        cout << "PLU not found" << endl;
        return;
    }
    //then check the change
    cout << "Enter amount to add: ";
    cin >> amount;
    
    if (amount < 1) {
        cout << "Amount must be > 0" << endl;
        return;
    }
    products[index].setInventory(products[index].getInventory() + amount);
    //needed the to_string change for it to stop giving an error
    history[historyCounter] = "Transaction #: " + to_string(historyCounter + 1) + ", PLU: " + PLU + ", type: Add to inventory, amount: " + to_string(amount);
    historyCounter++;
}

//function to subtract from inventory
//copying from addInventory function as framework
void subInventory(Product* products, int numProducts) {
    string PLU;
    int amount, index;
    bool found = false;
    
    cout << "Enter the PLU: ";
    cin >> PLU;
    //starting by checking if PLU is in the file
    for (int i = 0; i < numProducts; i++) {
        if (products[i].getPLU() == PLU) {
            index = i;
            found = true;
            break;
        }
    } //if not..
    if (!found) {
        cout << "PLU not found" << endl;
        return;
    }
    //then check the change
    cout << "Enter amount to subtract: ";
    cin >> amount;
    
    if (amount < 1) {
        cout << "Amount must be > 0" << endl;
        return;
    }
    int validation = products[index].getInventory(); //new var to try and fix overflow problem
    products[index].setInventory(products[index].getInventory() - amount);
    //had these two in the wrong order by mistake
    if (products[index].getInventory() < 0) {
        products[index].setInventory(0);
        amount = validation; //cant subtract more than starting amount..
    }
    //needed the to_string change for it to stop giving an error
    history[historyCounter] = "Transaction #: " + to_string(historyCounter + 1) + ", PLU: " + PLU + ", type: Subtract from inventory, amount: " + to_string(amount);
    historyCounter++;
}

//function for bonus credit
//functions similar to a stack, FILO/LIFO
void printHistory() {
    int counter = 0; //ensuring that only the latest 5 get posted
    //added an extra endl at start, to hopefully address last problem
    cout << endl << "History of transactions" << endl << "-----------------------" << endl;
    for (int i = historyCounter - 1; i >= 0 && counter < 5; i--, counter++) {
        cout << history[i] << endl;
    }
}

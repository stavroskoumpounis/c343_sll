#include <iostream>
#include "productlist.h"

using namespace std;

int main() {
    head = NULL;
    cnt = 0;
    int ch, id;
    string name, category;
    double price;

    //init product list
    push_back(1, "Smile", 3.99, "Toothpaste");
    push_back(2, "T-Shirt", 8.99, "Clothing");
    push_back(3, "Conditioner", 5.99, "Haircare");
    push_back(4, "Colgate", 2.99, "Toothpaste");
    push_back(5, "Sweater", 9.99, "Clothing");
    push_back(6, "Shampoo", 4.99, "Haircare");

    do {
        cout << "\n1 Insert Product";
        cout << "\n2 Display All Products";
        cout << "\n3 Display Product by ID";
        cout << "\n4 Calculate Total Price";
        cout << "\n5 Arrange Products by Category";
        cout << "\n6 Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter product ID: ";
                cin >> id;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product category: ";
                cin >> category;
                push_back(id, name, price, category);
                break;
            case 2:
                displayAll();
                break;
            case 3:
                cout << "\nEnter product ID: ";
                cin >> id;
                displayProd(id);
                break;
            case 4:
                cout << "\nTotal Price: $" << calcTotalPrice() << endl;
                break;
            case 5:
                arrangeByCategory();
                cout << "\nProducts arranged by category." << endl;
                break;
            case 6:
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 6);

    return 0;
}




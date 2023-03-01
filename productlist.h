#include<iostream>
#include <map>

using namespace std;

struct Product {
    int pId;
    string pName;
    double price;
    string category;
    struct Product *next;
};

void sortCategoryMap(map<string, Product *> &categoryMap);
void copyProduct(Product *dest, Product *src);

Product *head;
int cnt;

Product *createNewProduct(int id, string name, double price, string category) {
    Product *temp = new Product();
    temp->pId = id;
    temp->pName = name;
    temp->price = price;
    temp->category = category;
    temp->next = NULL;
    return temp;
}

void push_back(int id, string name, double price, string category) {
    Product *temp = createNewProduct(id, name, price, category);

    if (head == NULL) {
        head = temp;
    } else {
        Product *endNode = head;
        while (endNode->next != NULL) {
            endNode = endNode->next;
        }
        endNode->next = temp;
    }
}

Product pop_back() {
    Product toReturn;

    if (head == NULL) {
        cout << "List is empty" << endl;
    } else if (head->next == NULL) {
        toReturn = *head;
        head = NULL;
        cnt--;
    } else {
        Product *p = head;
        while (p->next->next != NULL) {
            p = p->next;
        }
        toReturn = *(p->next);
        delete p->next;
        p->next = NULL;
        cnt--;
    }
    return toReturn;
}

void displayAll() {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        cout << "Product List:" << endl;
        for (Product *p = head; p != NULL; p = p->next) {
            cout << "Product ID: " << p->pId << endl;
            cout << "Product Name: " << p->pName << endl;
            cout << "Price: " << p->price << endl;
            cout << "Category: " << p->category << endl;
            cout << endl;
        }
    }
}

void displayProd(int id) {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        cout << "Product:" << endl;
        for (Product *p = head; p != NULL; p = p->next) {
            if (p->pId == id) {
                cout << "Product ID: " << p->pId << endl;
                cout << "Product Name: " << p->pName << endl;
                cout << "Product Price: " << p->price << endl;
                cout << "Product Category: " << p->category << endl;
                cout << endl;
                return;
            }
        }
    }
}

double calcTotalPrice() {
    double sum = 0.0;
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1.0;
    } else {
        Product *p = head;
        while (p != NULL) {
            sum += p->price;
            p = p->next;
        }
        return sum;
    }
}

void arrangeByCategory() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Create a map to hold linked lists for each category
    map<string, Product *> categoryMap;

    // Traverse the list and add products to their respective categories
    for (Product *p = head; p != NULL; p = p->next) {
        string category = p->category;
        //if find() returns categoryMap.end(), category doesn't exist
        if (categoryMap.find(category) == categoryMap.end()) {
            //Create new linked list for category
            Product *categoryHead = createNewProduct(p->pId, p->pName, p->price, p->category);
            categoryMap[category] = categoryHead;
        } else {
            // Insert the product into the existing linked list for this category
            Product *temp = createNewProduct(p->pId, p->pName, p->price, p->category);
            temp->next = categoryMap[category];
            categoryMap[category] = temp;
        }
    }

    //sort the linked lists for each category by category name
    sortCategoryMap(categoryMap);

    //concat lists
    head = NULL;
    Product *last = NULL;
    for (auto it = categoryMap.begin(); it != categoryMap.end(); ++it) {
        Product *categoryHead = it->second;
        if (head == NULL) {
            head = categoryHead;
        } else {
            last->next = categoryHead;
        }
        while (categoryHead->next != NULL) {
            categoryHead = categoryHead->next;
        }
        last = categoryHead;
    }
}


void copyProduct(Product *dest, Product *src) {
    dest->pId = src->pId;
    dest->pName = src->pName;
    dest->price = src->price;
    dest->category = src->category;
    dest->next = src->next;
}

void sortCategoryMap(map<string, Product *> &categoryMap) {
    for (auto &p: categoryMap) {
        Product *pList = p.second;
        Product *p1, *p2, *minNode;
        string currCategory = pList->category;

        for (p1 = pList; p1->next != NULL; p1 = p1->next) {
            minNode = p1;
            for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
                if (p2->category < minNode->category) {
                    minNode = p2;
                }
            }
            if (minNode != p1) {
                // Swap the data of the nodes
                Product temp;
                copyProduct(&temp, p1);
                copyProduct(p1, minNode);
                copyProduct(minNode, &temp);
            }
        }
    }
}
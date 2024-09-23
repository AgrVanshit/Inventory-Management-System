#include <iostream>
#include <cstring>  // Use for strcpy
using namespace std;

struct itemEntry {
    float unitPrice;
    int copies, product_id;
    char name[30];
    char company[30];
};

class Store {
public:
    int numItem;
    itemEntry database[100];

    Store() {
        numItem = 0;
    }
    void insertItem(char itemName[], char company[], int pid, int c, float p);
    void deleteItem(char itemName[], int pid);
    itemEntry* searchi(char itemName[], int pid);
    void updateItem(char itemName[], int pid, int total, float price);
};

void Store::insertItem(char itemName[], char company[], int pid, int c, float p) {
    strcpy(database[numItem].name, itemName);  // Use strcpy instead of strcpy_s
    strcpy(database[numItem].company, company);  // Use strcpy instead of strcpy_s
    database[numItem].product_id = pid;
    database[numItem].copies = c;
    database[numItem].unitPrice = p;
    cout << "\n\t\t ITEM INSERTED SUCCESSFULLY\n";
    numItem++;
}

void Store::deleteItem(char itemName[], int pid) {
    int i;
    for (i = 0; i < numItem; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid)) {
            database[i].copies--;
            cout << "\n\t\t ITEM DELETED SUCCESSFULLY\n";
            return;
        }
    }
    cout << "\n\t\t ITEM NOT FOUND\n";
}

itemEntry* Store::searchi(char itemName[], int pid) {
    int i;
    for (i = 0; i < numItem; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid))
            return &database[i];
    }
    return NULL;
}

void Store::updateItem(char itemName[], int pid, int total, float price) {
    itemEntry* item = searchi(itemName, pid);
    if (item == NULL) {
        cout << "\n\t\t ITEM NOT FOUND\n";
        return;
    }
    item->copies += total;
    item->unitPrice = price;
}

int main() {
    Store sto;
    char name[30], company[30];
    int product_id, copies, unit_price, option;

    do {
        cout << "\n\t------------->DEPARTMENTAL STORE<--------------";
        cout << "\n\t\t-------------->MENU<------------";
        cout << "\n\t\t\t    1 FOR INSERT";
        cout << "\n\t\t\t    2 FOR DELETE";
        cout << "\n\t\t\t    3 FOR SEARCH";
        cout << "\n\t\t\t    4 FOR UPDATE";
        cout << "\n\t\t\t    5 FOR EXIT";
        cout << "\n\t\t  ENTER YOUR CHOICE : ";
        cin >> option;
        cin.ignore();  // To clear the newline left in the input buffer

        switch (option) {
        case 1:
            cout << "\n\t\t\t ENTER NAME OF ITEM : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t COMPANY: ";
            cin.getline(company, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            cout << "\n\t\t\t NO. OF COPIES : ";
            cin >> copies;
            cout << "\n\t\t\t UNIT PRICE PER ITEM : ";
            cin >> unit_price;
            sto.insertItem(name, company, product_id, copies, unit_price);
            break;

        case 2:
            cout << "\n\t\t\t ENTER NAME OF ITEM : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            sto.deleteItem(name, product_id);
            break;

        case 3:
            cout << "\n\t\t\t ENTER NAME OF ITEM : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            itemEntry* test;
            test = sto.searchi(name, product_id);
            if (test != NULL) {
                cout << "\n\t------------->SEARCHING RESULT<--------------";
                cout << "\n\t\t\t   ITEM FOUND"
                     << "\n\t\t\t NAME OF THE ITEM: " << test->name
                     << "\n\t\t\t COMPANY NAME: " << test->company
                     << "\n\t\t\t PRODUCT ID: " << test->product_id
                     << "\n\t\t\t NUMBER OF COPIES AVAILABLE: " << test->copies
                     << "\n\t\t\t UNIT PRICE PER ITEM: " << test->unitPrice;
            } else
                cout << "\n\t\t\t ITEM NOT FOUND";
            break;

        case 4:
            cout << "\n\t\t\t ENTER NAME OF ITEM : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            cout << "\n\t\t\t ENTER TOTAL NEW ENTRY : ";
            cin >> copies;
            cout << "\n\t\t\t ENTER NEW PRICE : ";
            cin >> unit_price;
            sto.updateItem(name, product_id, copies, unit_price);
            break;
        }
    } while (option != 5);

    return 0;
}
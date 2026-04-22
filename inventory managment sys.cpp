#include <iostream>
#include <string>
using namespace std;

/*Linked List for Item*/
struct Item {
    int id;
    string name;
    int quantity;
    Item* next;
};

Item* head = NULL;

/* Add Item */
void addItem(int id, string name, int quantity) {
    Item* newItem = new Item();
    newItem->id = id;
    newItem->name = name;
    newItem->quantity = quantity;
    newItem->next = head;
    head = newItem;
    cout << "Item added successfully.\n";
}

/* Remove Item */
void removeItem(int id) {
    Item* temp = head;
    Item* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Item removed successfully.\n";
}

/* Search Item */
void searchItem(int id) {
    Item* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Item Found:\n";
            cout << "ID: " << temp->id << "\nName: " << temp->name
                 << "\nQuantity: " << temp->quantity << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Item not found.\n";
}

/* Display Items */
void displayItems() {
    Item* temp = head;
    if (temp == NULL) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "\nInventory Items:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}

/* Queue for Customer Orders */
struct Order {
    int itemId;
    int quantity;
    Order* next;
};

Order* front = NULL;
Order* rear = NULL;

/* Add Order */
void addOrder(int itemId, int quantity) {
    Order* newOrder = new Order();
    newOrder->itemId = itemId;
    newOrder->quantity = quantity;
    newOrder->next = NULL;

    if (rear == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }
    cout << "Order added to queue.\n";
}

/* Process Order */
void processOrder() {
    if (front == NULL) {
        cout << "No orders to process.\n";
        return;
    }

    Order* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;

    cout << "Processing Order -> Item ID: "
         << temp->itemId << ", Quantity: "
         << temp->quantity << endl;

    delete temp;
}

/*Main Menu*/
int main() {
    int choice, id, quantity;
    string name;

    do {
        cout << "\n=====$Inventory Management System$=====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display Items\n";
        cout << "5. Add Customer Order\n";
        cout << "6. Process Order\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> quantity;
            addItem(id, name, quantity);
            break;

        case 2:
            cout << "Enter Item ID to remove: ";
            cin >> id;
            removeItem(id);
            break;

        case 3:
            cout << "Enter Item ID to search: ";
            cin >> id;
            searchItem(id);
            break;

        case 4:
            displayItems();
            break;

        case 5:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> quantity;
            addOrder(id, quantity);
            break;

        case 6:
            processOrder();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
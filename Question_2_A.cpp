#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product 
{
public:
    int id;
    string name;
    double price;

    Product(int _id, const string& _name, double _price) : id(_id), name(_name), price(_price) {}
};

class InventoryManager
{
private:
    vector<Product> inventory;

public:
    // Function to add a new product to the inventory
    void addProduct(const Product& newProduct) 
    {
        inventory.push_back(newProduct);
        cout << "Product added to the inventory.\n";
    }

    // Function to remove a product from the inventory based on its ID
    void removeProductById(int productId) 
    {
        auto it = remove_if(inventory.begin(), inventory.end(),
        [productId](const Product& p) { return p.id == productId; });

        if (it != inventory.end()) 
        {
            inventory.erase(it, inventory.end());
            cout << "Product with ID " << productId << " removed from the inventory.\n";
        } 
        else
            cout << "Product with ID " << productId << " not found in the inventory.\n";
    }

    // Function to display the current inventory
    void displayInventory() const 
    {
        cout << "Current Inventory:\n";
        for (const auto& product : inventory)
            cout << "ID: " << product.id << "\tName: " << product.name << "\tPrice: $" << product.price << "\n";
    }
};

int main() 
{
    InventoryManager inventoryManager;

    // Adding products to the inventory
    Product product1(1, "Laptop", 999.99);
    Product product2(2, "Smartphone", 499.99);

    inventoryManager.addProduct(product1);
    inventoryManager.addProduct(product2);

    cout << "*** Displaying the current inventory ***" << endl;
    inventoryManager.displayInventory();

    // Removing a product by ID
    inventoryManager.removeProductById(1);

    cout << "*** Displaying the updated inventory after removing id 1***" << endl;
    inventoryManager.displayInventory();

    return 0;
}

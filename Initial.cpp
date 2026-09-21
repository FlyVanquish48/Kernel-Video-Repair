#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Product {
public:
    Product(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    double getValue() const {
        return price * quantity;
    }

    void print() const {
        std::cout << std::left << std::setw(15) << name
                  << " | $" << std::fixed << std::setprecision(2) << price
                  << " | " << quantity << " units"
                  << " | $" << getValue()
                  << '\n';
    }

private:
    std::string name;
    double price;
    int quantity;
};

class Warehouse {
public:
    void addProduct(const std::string& name, double price, int quantity) {
        products.emplace_back(name, price, quantity);
    }

    double totalValue() const {
        double total = 0.0;

        for (const auto& product : products) {
            total += product.getValue();
        }

        return total;
    }

    void printReport() const {
        std::cout << "Warehouse Report\n";
        std::cout << "================\n";

        for (const auto& product : products) {
            product.print();
        }

        std::cout << "================\n";
        std::cout << "Total Value: $"
                  << std::fixed << std::setprecision(2)
                  << totalValue()
                  << '\n';
    }

private:
    std::vector<Product> products;
};

int main() {
    Warehouse warehouse;

    warehouse.addProduct("Laptop", 899.99, 6);
    warehouse.addProduct("Keyboard", 74.50, 15);
    warehouse.addProduct("Mouse", 35.99, 24);
    warehouse.addProduct("Monitor", 249.99, 10);

    warehouse.printReport();

    return 0;
}
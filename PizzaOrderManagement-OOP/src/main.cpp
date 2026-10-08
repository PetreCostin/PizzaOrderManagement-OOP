#include "Order.hpp"
#include <iostream>
#include <limits>
#include <string>

int main() {
    pizza::Order order;
    while (true) {
        std::cout << "\n=== PIZZA OOP ===\n1. Margherita (25 RON)\n2. Pepperoni (32 RON)\n3. Custom pizza (22 RON + toppings)\n4. View receipt\n5. Clear cart\n0. Exit\nChoice: ";
        int choice;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";
            continue;
        }
        if (choice == 0) break;
        switch (choice) {
            case 1: { pizza::Margherita item; order.add(item); break; }
            case 2: { pizza::Pepperoni item; order.add(item); break; }
            case 3: {
                pizza::CustomPizza item;
                std::cout << "Add extra cheese for 5 RON? (y/n): ";
                char extra;
                if (!(std::cin >> extra)) return 0;
                if (extra == 'y' || extra == 'Y') item.addTopping("Cheese", 5.0);
                std::cout << "Add mushrooms for 4 RON? (y/n): ";
                if (!(std::cin >> extra)) return 0;
                if (extra == 'y' || extra == 'Y') item.addTopping("Mushrooms", 4.0);
                order.add(item);
                break;
            }
            case 4: std::cout << order.receipt(); break;
            case 5: order.clear(); std::cout << "Cart cleared.\n"; break;
            default: std::cout << "Unknown option.\n"; continue;
        }
        if (choice >= 1 && choice <= 3) std::cout << "Added! Items: " << order.count() << "\n";
    }
    return 0;
}

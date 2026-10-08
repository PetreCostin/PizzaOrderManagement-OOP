#include "Order.hpp"
#include <cassert>
#include <stdexcept>
#include <iostream>

int main() {
    pizza::Order order;
    assert(order.total() == 0.0);
    pizza::Margherita margherita;
    pizza::Pepperoni pepperoni;
    order.add(margherita);
    order.add(pepperoni);
    assert(order.count() == 2);
    assert(order.total() == 57.0);
    pizza::CustomPizza custom;
    custom.addTopping("Cheese", 5.0);
    order.add(custom);
    custom.addTopping("Mushrooms", 4.0);
    assert(order.total() == 84.0); // clone is independent
    assert(order.receipt().find("TOTAL: 84.00 RON") != std::string::npos);
    bool threw = false;
    try { custom.addTopping("Invalid", -1.0); }
    catch (const std::invalid_argument&) { threw = true; }
    assert(threw);
    order.clear();
    assert(order.count() == 0);
    std::cout << "All tests passed!\n";
}

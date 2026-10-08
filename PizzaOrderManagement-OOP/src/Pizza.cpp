#include "Pizza.hpp"
#include <stdexcept>
#include <utility>

namespace pizza {
Pizza::Pizza(std::string name) : name_(std::move(name)) {}
std::string Pizza::description() const { return name_; }
Margherita::Margherita() : Pizza("Margherita") {}
double Margherita::price() const { return 25.0; }
std::unique_ptr<Pizza> Margherita::clone() const { return std::make_unique<Margherita>(*this); }
Pepperoni::Pepperoni() : Pizza("Pepperoni") {}
double Pepperoni::price() const { return 32.0; }
std::unique_ptr<Pizza> Pepperoni::clone() const { return std::make_unique<Pepperoni>(*this); }
CustomPizza::CustomPizza(std::string name) : Pizza(std::move(name)) {}
void CustomPizza::addTopping(const std::string& topping, double cost) {
    if (topping.empty() || !(cost >= 0.0) || !(cost < 10000.0)) throw std::invalid_argument("Invalid topping or cost");
    toppings_.push_back(topping);
    extras_ += cost;
}
double CustomPizza::price() const { return 22.0 + extras_; }
std::unique_ptr<Pizza> CustomPizza::clone() const { return std::make_unique<CustomPizza>(*this); }
std::string CustomPizza::description() const {
    std::string result = name_;
    for (const auto& topping : toppings_) result += " + " + topping;
    return result;
}
}

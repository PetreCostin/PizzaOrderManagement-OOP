#pragma once
#include <memory>
#include <string>
#include <vector>

namespace pizza {
class Pizza {
public:
    explicit Pizza(std::string name);
    virtual ~Pizza() = default;
    virtual double price() const = 0;
    virtual std::unique_ptr<Pizza> clone() const = 0;
    virtual std::string description() const;
protected:
    std::string name_;
};
class Margherita final : public Pizza {
public:
    Margherita();
    double price() const override;
    std::unique_ptr<Pizza> clone() const override;
};
class Pepperoni final : public Pizza {
public:
    Pepperoni();
    double price() const override;
    std::unique_ptr<Pizza> clone() const override;
};
class CustomPizza final : public Pizza {
public:
    explicit CustomPizza(std::string name = "Custom Pizza");
    void addTopping(const std::string& topping, double cost);
    double price() const override;
    std::unique_ptr<Pizza> clone() const override;
    std::string description() const override;
private:
    std::vector<std::string> toppings_;
    double extras_ = 0.0;
};
}

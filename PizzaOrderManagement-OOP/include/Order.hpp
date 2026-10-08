#pragma once
#include "Pizza.hpp"
#include <memory>
#include <string>
#include <vector>

namespace pizza {
class Order {
public:
    void add(const Pizza& item);
    double total() const;
    std::string receipt() const;
    std::size_t count() const;
    void clear();
private:
    std::vector<std::unique_ptr<Pizza>> items_;
};
}

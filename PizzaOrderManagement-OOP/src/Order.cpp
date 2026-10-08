#include "Order.hpp"
#include <iomanip>
#include <numeric>
#include <sstream>

namespace pizza {
void Order::add(const Pizza& item) { items_.push_back(item.clone()); }
double Order::total() const {
    return std::accumulate(items_.begin(), items_.end(), 0.0,
        [](double sum, const auto& item) { return sum + item->price(); });
}
std::size_t Order::count() const { return items_.size(); }
void Order::clear() { items_.clear(); }
std::string Order::receipt() const {
    std::ostringstream out;
    out << "\n--- PIZZA ORDER RECEIPT ---\n" << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < items_.size(); ++i)
        out << i + 1 << ". " << items_[i]->description() << " - " << items_[i]->price() << " RON\n";
    out << "TOTAL: " << total() << " RON\n";
    return out.str();
}
}

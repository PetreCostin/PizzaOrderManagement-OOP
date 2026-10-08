# PizzaOrderManagement-OOP 🍕

**University C++ project demonstrating object-oriented programming through a pizza ordering system.**

An original educational project inspired by the concept of [PizzaOOP](https://github.com/davidmarian2012/PizzaOOP), not a copy of its implementation.

## Features
- Interactive terminal menu
- Margherita, Pepperoni, and customizable pizzas
- Optional cheese and mushroom toppings
- Shopping cart with receipts in RON
- Input validation and exception handling
- Automated C++ tests and GitHub Actions CI

## OOP concepts
| Concept | Implementation |
| --- | --- |
| Abstraction | `Pizza` abstract base class |
| Inheritance | `Margherita`, `Pepperoni`, `CustomPizza` |
| Polymorphism | Virtual `price()`, `description()`, `clone()` |
| Encapsulation | Private toppings and cart storage |
| Composition | `Order` owns `unique_ptr<Pizza>` objects |
| RAII | Smart pointers manage object lifetimes |

## Build and run
Requires a C++17 compiler and CMake 3.16+.

```bash
cmake -S . -B build
cmake --build build
./build/pizza_app
```

On Windows with a multi-configuration generator, use `cmake --build build --config Release` and run the executable in `build/Release/`.

## Tests
```bash
ctest --test-dir build --output-on-failure
```

## Project layout
```
include/             Public class interfaces
src/                 Implementations and console application
tests/               Automated unit-style assertions
.github/workflows/   Continuous integration
CMakeLists.txt        Build configuration
```

## Example receipt
```
--- PIZZA ORDER RECEIPT ---
1. Margherita - 25.00 RON
2. Pepperoni - 32.00 RON
TOTAL: 57.00 RON
```

## Potential extensions
File persistence, discounts, order IDs, customer management, delivery fees, and a graphical interface.

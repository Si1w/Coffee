#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
#include <iostream>

class Ingredient {
public:
    double get_price_unit() { return price_unit; };
    size_t get_units() { return units; };
    std::string get_name() { return name; };

    virtual double price() = 0;
    virtual Ingredient* clone() const = 0;
    virtual ~Ingredient() = default;
    
protected:
    Ingredient(double price_unit, size_t units) : price_unit{price_unit}, units{units} {};

    double price_unit;
    size_t units;
    std::string name;
};

#endif // INGREDIENT_H
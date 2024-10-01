#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"

#define sub_ingredient(class_name, price_unit)  \
    class class_name : public Ingredient { \
        public: \
            class_name(size_t units) : Ingredient(price_unit, units) { \
                this->name = #class_name; \
            } \
        virtual double price() override { return price_unit * units; } \
        virtual Ingredient* clone() const override { return new class_name(*this); } \
    }

sub_ingredient(Cinnamon, 5);
sub_ingredient(Chocolate, 5);
sub_ingredient(Sugar, 1);
sub_ingredient(Cookie, 10);
sub_ingredient(Espresso, 15);
sub_ingredient(Milk, 10);
sub_ingredient(MilkFoam, 5);
sub_ingredient(Water, 1);

#endif // SUB_INGREDIENTS_H
#ifndef MOCHA_H
#define MOCHA_H

#include "espresso_based.h"
#include "sub_ingredients.h"
#include "ingredient.h"

class Mocha : public EspressoBased {
   public:
    Mocha();
    Mocha(const Mocha& cap);
    ~Mocha();
    Mocha& operator=(const Mocha& cap);

    double price();
    void brew();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items() { return side_items; };

   private:
    std::vector<Ingredient*> side_items;
};

#endif // MOCHA_H
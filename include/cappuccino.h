#ifndef CAPPUCCINO
#define CAPPUCCINO

#include "espresso_based.h"
#include "sub_ingredients.h"
#include "ingredient.h"

class Cappuccino : public EspressoBased {
public:
    Cappuccino();
    Cappuccino(const Cappuccino& cap);
	~Cappuccino();
    Cappuccino& operator=(const Cappuccino& cap);

    double price();
    void brew();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items() { return side_items; };

private:
    std::vector<Ingredient*> side_items;

};

#endif // CAPPUCCINO
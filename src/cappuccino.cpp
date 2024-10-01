#include "cappuccino.h"

Cappuccino::Cappuccino() : EspressoBased("Cappuccino") {
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}

Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap) {
    name = cap.name;
    for (auto ingredient : cap.side_items) {
        side_items.push_back(ingredient->clone());
    }
}

Cappuccino::~Cappuccino() {
    for (auto ingredient : side_items) {
        delete ingredient;
    }
    side_items.clear();
}

Cappuccino& Cappuccino::operator=(const Cappuccino& cap) {
    if (&cap != this) {
        for (auto& s : side_items) {
            delete s;
        }
        for (auto& i : ingredients) {
            delete i;
        }
        side_items.clear();
        ingredients.clear();

        for (const auto& s : cap.side_items) {
            side_items.push_back(s->clone());
        }
        for (const auto& i : cap.ingredients) {
            ingredients.push_back(i->clone());
        }
    }
    return *this;
}

double Cappuccino::price() {
    double p = 0;
    for (auto& ingredient : ingredients) {
        p += ingredient->price();
    }
    for (auto& ingredient : side_items) {
        p += ingredient->price();
    }
    return p;
}

void Cappuccino::brew() {
    std::cout << "making cappuccino..." << std::endl;
    for (const auto& i : ingredients) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    for (const auto& i : side_items) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    std::cout << "cappuccino finished" << std::endl;
}

void Cappuccino::add_side_item(Ingredient* side) { side_items.push_back(side); }
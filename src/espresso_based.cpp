#include "espresso_based.h"

void EspressoBased::brew() {
    std::cout << "Brewing " << name << std::endl;
}

EspressoBased::~EspressoBased() {
    for (auto ingredient : ingredients) {
        delete ingredient;
    }
    ingredients.clear();
}

EspressoBased::EspressoBased(const EspressoBased& esp) {
    for (auto ingredient : esp.ingredients) {
        ingredients.push_back(ingredient->clone());
    }
}
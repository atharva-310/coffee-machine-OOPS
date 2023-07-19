#include <bits/stdc++.h>
#include "recipe.cpp"

/**
 * Drink
 * instances of the drink class will be used in the menu of coffeemachine 
 * 
 * calculateCost : calcuates the cost of the drink based on the recipe 
*/

using namespace std;

class Drink {
    private: 
        string name;
        Recipe* recipe;
        int cost;
        int calculateCost() {
            int cost = 0;
            map<Ingredient*, int> ingredientList = recipe->getRequiredIngredients();
            map<Ingredient*,int>:: iterator it;
            for(it = ingredientList.begin(); it != ingredientList.end(); it++) {
                cost += (((it->first)->getCost())*(it->second));
            }
            return cost;
        }
    public: 
        //constructor 
        Drink(string name, Recipe* recipe): name(name), recipe(recipe) {
            this->cost = calculateCost();
        };

        Recipe* getRecipe() {
            return recipe;
        }
        string getName() {
            return name;
        }
        int getCost () {
            return cost;
        }

};
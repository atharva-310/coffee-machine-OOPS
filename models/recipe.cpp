#include <bits/stdc++.h>
#include "ingredient.cpp"
using namespace std;

/**
 * Recipe 
 * store the recipe for each drink in form of required ingredients;
 * 
*/
class Recipe { 
    private : 
        map<Ingredient*,int> requiredIngredients;
    
    public: 
        //constructors
        Recipe(map<Ingredient*,int> ingredientList) {
            this->requiredIngredients = ingredientList;
        }

        map<Ingredient*,int> getRequiredIngredients() {
            return requiredIngredients;
        }
        
        void addIngredient(Ingredient* ingredient, int qty) {
            requiredIngredients[ingredient] = qty;
        }

        // void print() {
        //     cout << "Required Ingredients" << endl;
        //     for(map<Ingredient*,int>::iterator it = requiredIngredients.begin() ; it!= requiredIngredients.end(); it++) {
        //         cout << (it->first)->getName() << " : " << (it->second) << " units" << endl;
        //     }
        //     return;
        // }

};
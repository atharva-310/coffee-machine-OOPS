#include <bits/stdc++.h>
#include "ingredient.cpp"

using namespace std;

class Recipe { 
    private : 
        map<Ingredient*,int> requiredIngredients;
    
    public: 
        //constructors
        Recipe() {
            requiredIngredients.clear();
        }
        Recipe(map<Ingredient*,int> ingredientList) {
            this->requiredIngredients = ingredientList;
        }

        map<Ingredient*,int> getRequiredIngredients() {
            return requiredIngredients;
        }
        
        void addIngredient(Ingredient* ingredient, int qty) {
            requiredIngredients[ingredient] = qty;
        }
        void print() {
            cout << "Required Ingredients" << endl;
            for(auto it: requiredIngredients) {
                cout << (it.first)->getName() << " : " << (it.second) << " units" << endl;
            }
            return;
        }

};
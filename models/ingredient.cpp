#include <bits/stdc++.h>

using namespace std;

/**
 * Ingredient
 * used to create instances of all the ingridents and it's cost
*/


class Ingredient {

    private: 
        string name;
        int cost;
    public: 
        // constructor
        Ingredient(string name, int cost) : name(name), cost(cost) {}

        int getCost () {
            return cost;
        }
        string getName() {
            return name;
        }
        
        void setCost (int newCost) {
            cost = newCost;
            return;
        }
        void setName (string newName) {
            name = newName;
            return;
        }
    
};
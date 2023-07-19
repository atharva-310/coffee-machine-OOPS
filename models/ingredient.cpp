#include <bits/stdc++.h>

using namespace std;

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
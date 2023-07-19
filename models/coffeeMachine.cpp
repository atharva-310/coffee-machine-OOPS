#include <bits/stdc++.h>
#include "drink.cpp"
using namespace std;

/**
 * CoffeeMachine
 * 
 * Methods
 * Private:
 * - isAvailable  @param(Drink * drink) : will check whether all the ingredients of drink are available in stock
 * - consume      @param(Drink * drink) : Will consume all ingredients
 * - processDrink @param(Drink * drink) : uses the above method to process the ordered beverage
 * 
 * Public:
 * - refillStock  : refill the the stock back to it's capacity
 * - displayMenu  : diaplay menu of all the beverages 
 * - printStock   : Display all ingredients stock
*/

class CoffeeMachine {
    private: 
        map<Ingredient*,int> stock, capacity;
        vector<Drink*> menu;

        bool isAvailable (Drink * drink) {
            cout << "Checking for ingridents...  "<< endl;
            map<Ingredient*,int> requiredIngredients = drink->getRecipe()->getRequiredIngredients();
            map<Ingredient*,int>::iterator it;
            for(it = requiredIngredients.begin(); it != requiredIngredients.end(); it++) {
                Ingredient * cur_ingredient = it->first;
                if(stock[cur_ingredient] < (it->second)) {
                    cout << "The ingredient " << cur_ingredient->getName() << " is not in Stock" << endl;
                    return false;
                }
            }
            cout << "Ingridents are in stock!!" << endl;
            return true;
        }

        void consume(Drink * drink) {
            cout << "Preparing your " << drink->getName() << endl;
            map<Ingredient*,int> requiredIngredients = drink->getRecipe()->getRequiredIngredients();
            map<Ingredient*,int>::iterator it;
            for(it = requiredIngredients.begin(); it != requiredIngredients.end(); it++) {
                Ingredient * cur_ingredient = it->first;
                stock[cur_ingredient] -= (it->second);
            }
            cout << "Your " << drink->getName()  << " is ready!!"<< endl;
        }

        void processDrink(Drink * drink) {
            cout << "-----------------------------------------\n";
            cout << "                Status                   " << endl;
            cout << "-----------------------------------------\n";
            if(!isAvailable(drink)) return;
            consume(drink);
            cout << "-----------------------------------------\n\n";
        }
       
    public: 
        //constructor 
        CoffeeMachine(map<Ingredient*,int> capacity, vector<Drink*> menu) : capacity(capacity),stock(capacity), menu(menu) {}

        void refillStock () {
            stock = capacity;
            cout << "-----------------------------------------\n";
            cout << " Stock is refilled to maximum capacity!!" << endl;
            cout << "-----------------------------------------\n\n";
      
        }
        void displayMenu () {
            cout << "\n\n";
            int choice;
            do {
                cout << "-----------------------------------------\n";
                cout << "               Menu                 " << endl;
                cout << "-----------------------------------------\n\n";

                cout << setw(10) << left << "S No." << setw(15) << left << "Beverage" << setw(15) << right << "Cost (per unit)\n";
                for(int i=0; i<menu.size(); i++) {
                    cout<< setw(10) << left << (i+1) << setw(15) << left << menu[i]->getName() << setw(15) << right << menu[i]->getCost() << endl;
                }
                cout << "-----------------------------------------\n";
                cout << "Buy the beverage  : Enter serial number \n";
                cout << "Exit machine      : -2 \n";
                cout << "Back to homepage  : -1 \n";
                cout << "Enter the option  : " ;
                cin >> choice;
                switch (choice) {
                    case -2:
                        exit(0);
                        break;
                    case -1:
                        cout << "Exiting the menu....." << endl; 
                        break;
                    default:
                        if(choice >= 1 && choice < menu.size()+1) {
                            processDrink(menu[choice-1]);
                        } else {
                            cout << "\n Invalid choice. Please try again.\n";
                            cout << "-----------------------------------------\n\n";
                        }
                        break;
                }
            } while (choice != -1 && choice != -2);
            cout << "-----------------------------------------\n\n";

        }

        void printStock ( ) {             
            cout << "-----------------------------------------\n";   
            cout << "               Stock                 " << endl;
            cout << "-----------------------------------------\n";
            cout  << setw(15) << left << "Ingredient" << setw(15) << right << "Quantity (unit)\n";
            map<Ingredient*,int>::iterator item;
            for(item = stock.begin(); item != stock.end(); item++) {
                  cout << setw(15) << left << (item->first)->getName() << setw(15) << right << (item->second) << endl;
            }
            cout << "-----------------------------------------\n\n";
        
        }

};
#include <bits/stdc++.h>
#include "models/coffeeMachine.cpp"

using namespace std;

int main() {
    Ingredient milk("Milk", 10), coffee_bean("Coffee Bean", 10), sugar("Sugar",4), cream("Cream",20);

    map<Ingredient*,int> capacity;
    capacity[&milk] = 20;
    capacity[&sugar] = 20;
    capacity[&coffee_bean] = 20;
    capacity[&cream] = 10;

    map<Ingredient*, int> coffeeIngredients, creamCoffeeIngredients;
    coffeeIngredients[&milk] = 3;
    coffeeIngredients[&sugar] = 2;
    coffeeIngredients[&coffee_bean] = 2;

    creamCoffeeIngredients[&milk] = 3;
    creamCoffeeIngredients[&sugar] = 2;
    creamCoffeeIngredients[&coffee_bean] = 2;
    creamCoffeeIngredients[&cream] = 1;

    Recipe coffeeRecipe(coffeeIngredients), creamCoffeeRecipe(creamCoffeeIngredients);
    Drink normalCoffee("Coffee", &coffeeRecipe ), creamCoffee("Cream Coffee",&creamCoffeeRecipe);

    vector<Drink*> menu;
    menu.push_back((&normalCoffee));
    menu.push_back((&creamCoffee));

    CoffeeMachine coffeeMachine(capacity,menu);

    int choice;
    do {
        cout << "-----------------------------------------\n";
        cout << "      Welcome to Coffee Makers!     " << endl;
        cout << "-----------------------------------------\n";

        cout << "1. Buy Beverage\n";
        cout << "2. Check Stock\n";
        cout << "3. Refill Stock\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        switch (choice) {
            case 1:
                coffeeMachine.displayMenu();
                break;
            case 2:
                coffeeMachine.printStock();
                break;
            case 3:
                coffeeMachine.refillStock();
                break;
            case 4:
                cout << "Exiting the Coffee Machine. Have a nice day!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);


}
/* CISC 1600
 * Lab #11: Shopping List
 * This program handles a shopping list. 
 *
 * Yharelis Ribic
 * Last edited: November 19,2023
 */
#include <iostream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 5;

// Input shopping list information
// Pre: Arrays names[], prices[], and quantities[] have size ARRAY_SIZE.
// Post: Arrays are filled with user-inputted values for item names, quantities, and prices.
void inputShoppingList(string names[], double prices[], int quantities[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << "Enter information for item #" << i + 1 << ":\n";
        cout << "Name: ";
        cin >> names[i];
        cout << "How much of that item?: ";
        cin >> quantities[i];
        cout << "Price per item: $";
        cin >> prices[i];
    }
}

// Calculate total cost of the shopping list
// Pre: Arrays prices[] and quantities[] have size ARRAY_SIZE.
// Post: Returns the total cost by summing the product of each item's price and quantity.
double calculateTotalCost(const double prices[], const int quantities[]) {
    double totalCost = 0.0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        totalCost += prices[i] * quantities[i];
    }
    return totalCost;
}

// Print out the shopping list
// Pre: Arrays names[], prices[], and quantities[] have size ARRAY_SIZE.
// Post: Outputs the shopping list with item names, quantities, prices, and the total cost.
void printShoppingList(const string names[], const double prices[], const int quantities[]) {
    cout << "This week's shopping list:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << names[i] << "\n";
        cout << "Quantity: " << quantities[i] << endl;
        cout << "Price: $" << fixed << setprecision(2) << prices[i] * quantities[i] << endl;
    }
    // Print total cost
    cout << "Total Cost: $" << fixed << setprecision(2) << calculateTotalCost(prices, quantities) << "\n";
}

int main() {
    // Declare arrays
    string names[ARRAY_SIZE];
    double prices[ARRAY_SIZE];
    int quantities[ARRAY_SIZE];

    // Call function to fill the arrays
    inputShoppingList(names, prices, quantities);

    // Call function to print out the shopping list
    printShoppingList(names, prices, quantities);

    return 0;
}


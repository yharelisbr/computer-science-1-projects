#include <iostream> 
#include <iomanip> 


using namespace std;

int main() { 

	cout << fixed << showpoint << setprecision(2);

	cout << "Welcome to our Coffeeshop!"<< endl;

	string firstName; 
	cout << "What is your first name? ";
	cin >> firstName;
	cout << "Welcome " << firstName << endl ; 

	int numCoffees, numBagels, numDonuts;
	cout << "How many coffees? ";
	cin >> numCoffees;
	cout << "How many bagels? ";
	cin >> numBagels;
	cout << "How many donuts? ";
	cin >> numDonuts;

	double coffeePrice = 2.50;
	double bagelPrice = 1.75;
	double donutPrice = 1.00;
	double taxRate = 0.085;
	double subtotal = (numCoffees * coffeePrice) + (numBagels * bagelPrice) + (numDonuts * donutPrice);
	double total = subtotal * (1 + taxRate); 

	cout << "Your total is:  $" << fixed << setprecision(2) << total << endl;
	
	double payment; 

	cout << "How much will you pay? ";
	cin >> payment; // input payment amount

	double change = payment - total;

	// receipt 
	cout << " Receipt for Customer: " << firstName <<  endl;
    	cout << " Coffees:" << numCoffees << endl;
  	cout << " Bagels:" << numBagels <<  endl;
    	cout << " Donuts:" << numDonuts << endl;
    	cout << " Total is: $" << fixed << setprecision(2) << total << endl;
    	cout << " Your change is: $" << fixed << setprecision(2) << change << endl;
   

	return 0;

}

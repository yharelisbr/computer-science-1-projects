#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
 
	char destination;
	int flightTime;
	char weekEndOrWeekDayLetter;
	int numTickets;
	double ticketPrice;
	bool isDayflight;
	bool isWeekend;
	double totalCost;
	double userPayment;
	double change;

	cout << "Welcome to Fordham Airlines!" << endl;
	 
	cout << "What is your destination? ([C]hicago, [M]iami, [P]ortland) "; 
	cin >> destination; 			
	cout << "What time will you travel? (Enter time between 0-2359) ";
	cin >> flightTime;
	
	isDayflight = (flightTime >= 500 && flightTime <= 1900) ;


	cout << "What type of day are you traveling? (week[E]nd or week[D]ay) "; 
	cin >> weekEndOrWeekDayLetter;

	isWeekend = (weekEndOrWeekDayLetter == 'E');

	if (destination == 'C') {
        ticketPrice = isDayflight ? (isWeekend ? 90.0 : 75.0) : (isWeekend ? 60.0 : 50.0);
    } 		else if (destination == 'M') {
        	ticketPrice = isDayflight ? (isWeekend ? 180.0 : 150.0) : (isWeekend ? 120.0 : 100.0);
    } 		else if (destination == 'P') {
        	ticketPrice = isDayflight ? (isWeekend ? 360.0 : 300.0) : (isWeekend ? 240.0 : 200.0);
    } 	else {
        	cout << "Invalid destination. Order cancelled." << endl;
        return 1;
    }
	cout << "Each ticket will cost: $" << fixed << setprecision(2) << ticketPrice << endl;

	cout <<  "How many tickets do you want? " ;
	cin >>  numTickets; 

	if (numTickets <= 0) {
		cout << "Invalid number of tickets. Order cancelled." << endl; 
	return 1; 
}	


	totalCost = ticketPrice * numTickets;
	
 
	cout << "You owe: $" << fixed << setprecision(2) << totalCost << endl;
	cout << "Amount paid? " ;
	cin >> userPayment ;

        if (userPayment < totalCost) {
                cout << "That is too little! No tickets ordered.";
        return 1;
}
 	change = userPayment - totalCost; 
    	cout << "You will get in change: $" << fixed << setprecision(2) << change << endl;
    	cout << "Your tickets have been ordered!" ;

    return 0;
}

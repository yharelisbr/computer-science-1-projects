#include <iostream>
#include <string>
		 
int main() {
    int month;

    // Ask the user to enter a month number
    std::cout << "Enter a month number: ";
    std::cin >> month;

    // Check if the input is within the valid range
    if (month >= 1 && month <= 12) {
         // Determine the season based on the month
        std::string season; 
        if (month == 12 || month == 1 || month == 2) {
            season = "Winter";
        } else if (month >= 3 && month <= 5) {
            season = "Spring";
        } else if (month >= 6 && month <= 8) {
            season = "Summer";
        } else {
            season = "Fall";
        }

        // Output the result
        std::cout << "It is " << season << std::endl;
    } else {
        // Invalid input
        std::cout << "Invalid month. Enter number 1-12" << std::endl;
    }

    return 0;
}
	             

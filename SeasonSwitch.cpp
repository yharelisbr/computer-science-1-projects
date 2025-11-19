#include <iostream> 
#include <string>
int main() {
	int month;

	std::cout << "Enter a month number : "; 
	std::cin  >>  month;

	if (month >= 1 && month <= 12) {
	std::string season; 

	switch (month) {
		case 12:
		case 2:
		case 1:
			season = "Winter";
			break;

		case 5:
		case 4:
		case 3:
			season =  "Spring";
			break;

		case 8:
		case 7:
		case 6:
			season = "Summer";
			break;

		case 11:
		case 10:
		case 9:
			season = "Fall";
			break;
		default:
			std::cout << "Invalid month. Enter number 1-12";
			return 1;
	}	
	
		std::cout << "It is " << season << std::endl;
	}else { 
		std::cout << "Invalid month. Enter number 1-12" << std::endl; 
	}

	return 0;
}  

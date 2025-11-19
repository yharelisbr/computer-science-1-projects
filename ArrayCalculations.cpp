/* CISC1600
 * Lab 12: Array Calculations
 * The purpose of this lab is to delcare an array of integers and implement functions 
 *
 * Yharelis Ribic
 * Last edited: December 1, 2023
 */
#include <iostream>
#include <iomanip>

using namespace std; 

const int maxSize = 50;
int myArray[maxSize];

void initializeArray(int arr[], int& size);
void displayArray(const int arr[], int size);
bool searchNumber(const int arr[], int size, int target);
int countOccurrences(const int arr[], int size, int target);
void calculateStatistics(const int arr[], int size, int& min, int& max, int& sum, double& average);

int main() {
    int size = 0;

    cout << "Please enter up to 50 non-negative whole numbers separated by space." << endl;
    cout << "Mark the end of the input list with a negative number: " << endl;
    

    initializeArray(myArray, size);

    displayArray(myArray, size);

    int min, max, sum;
    double average;

    calculateStatistics(myArray, size, min, max, sum, average);

    cout << "The minimum value in the array is " << min << endl;
    cout << "The maximum value in the array is " << max << endl;
    cout << "The sum of all the elements in the array is " << sum << endl;

    
    cout << fixed << setprecision(2);
    cout << "The average of all the elements in the array is " << average << endl;

    int searchNum;
    cout << "Please enter the value you want to search in the array: ";
    cin >> searchNum;

    if (searchNumber(myArray, size, searchNum)) {
        cout << "Find your target " << searchNum << endl;
    } else {
        cout << "Could not find " << searchNum << endl;
    }

    int countTarget;
    cout << "Please enter the value you want to know the frequency of: ";
    cin >> countTarget;

    int frequency = countOccurrences(myArray, size, countTarget);
    cout << "The number " << countTarget << " has occurred " << frequency << " time(s) in the array" << endl;

    return 0;
}

void initializeArray(int arr[], int& size) {
    int num;
    cin >> num;

    while (num >= 0 && size < maxSize) {
        arr[size++] = num;
        cin >> num;
    }
}

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool searchNumber(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

int countOccurrences(const int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            ++count;
        }
    }
    return count;
}

void calculateStatistics(const int arr[], int size, int& min, int& max, int& sum, double& average) {
    if (size == 0) {
        min = max = sum = 0;
        average = 0.0;
        return;
    }

    min = max = sum = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }

    average = static_cast<double>(sum) / size;
}

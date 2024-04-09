/*                                                   *
 * Name: Andy Derevyanko                             *
 * Class: ICS4U1-04                                  *
 * Topic: Assignment 7 - Recursion                   */

#include <iostream>

using namespace std;

// Function to calculate the GCD of two numbers
int gcd(int, int);
// Helper function to calculate the number of even digits in a number
int evenCount(int);
// Helper function to calculate the number of odd digits in a number
int oddCount(int);
// Function to calculate the number of even and odd digits in a number
void evenAndOddCount(int);
// Function to reverse a string
void reverseDisplay(const string &);
// Function to count the occurrences of a character in a string
int count(const string &, char);
// Function to calculate the product of digits in a number
int productDigits(int);
// Alternate function to reverse a string
void reverseDisplayHelper(const string &str);
// Helper function
void reverseDisplayHelper(const string &, int);
// Function to find the smallest element in an array
int smallestElement(int[], int);
// Function to calculate the sum of elements in an array
int sumArray(int[], int);

// Main function
int main() {
  // Display welcome message
  cout << "Welcome to the Recursion program!" << endl;

  while (true) {
    int choice;
    // Display menu options
    cout << "1. Compute GCD of two numbers" << endl;
    cout << "2. Count odd and even digits in a number" << endl;
    cout << "3. Reverse a string" << endl;
    cout << "4. Count number of occurrences of a specific letter in a string"
         << endl;
    cout << "5. Compute Product of digits in an integer" << endl;
    cout << "6. Reverse a string (Alternate Method)" << endl;
    cout << "7. Find the smallest number in an array of 5 elements" << endl;
    cout << "8. Find the sum in an array of a number of elements" << endl;
    cout << "9. Exit" << endl << endl;

    cout << "Enter your choice: ";

    do {
      // Get user choice and validate
      cin >> choice;
      if (choice >= 1 && choice <= 9)
        break;
      else
        cout << "Invalid choice. Please enter a number between 1 and 9: ";
    } while (choice < 1 ||
             choice > 9); // Repeat loop while the choice is not valid

    cout << endl;

    switch (choice) {
    case 1: {
      // GCD calculation
      cout << "Enter two numbers: " << endl;
      int num1, num2;
      cin >> num1 >> num2;
      cout << "The GCD of " << num1 << " and " << num2 << " is "
           << gcd(num1, num2) << endl;
      break;
    }
    case 2: {
      // Count odd and even digits
      cout << "Enter a number: ";
      int num;
      cin >> num;
      evenAndOddCount(num);
      break;
    }
    case 3: {
      // Reverse a string
      cout << "Enter a string: ";
      string s;
      cin >> s;
      cout << "Reversed string: ";
      reverseDisplay(s);
      cout << endl;
      break;
    }
    case 4: {
      // Count occurrences of a specific letter in a string
      cout << "Enter a string: ";
      string s;
      cin >> s;
      char a;
      cout << "Enter the letter to count: ";
      cin >> a;
      cout << "Occurrences of '" << a << "': " << count(s, a) << endl;
      break;
    }
    case 5: {
      // Compute product of digits in an integer
      cout << "Enter an integer: ";
      int n;
      cin >> n;
      cout << "Product of digits: " << productDigits(n) << endl;
      break;
    }
    case 6: {
      // Reverse a string (Alternate Method)
      cout << "Enter a string: ";
      string s;
      cin >> s;
      cout << "Reversed string: ";
      reverseDisplayHelper(s);
      cout << endl;
      break;
    }
    case 7: {
      // Find the smallest element in an array of 5 elements
      int arr[5];
      cout << "Enter 5 elements for the array: ";
      for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
      }
      cout << "Smallest element: " << smallestElement(arr, 5) << endl;
      break;
    }
    case 8: {
      // Find the sum in an array of a number of elements
      int size;
      cout << "Enter the size of the array: ";
      cin >> size;
      int arr[size];
      cout << "Enter elements for the array: ";
      for (int i = 0; i < size; ++i) {
        cin >> arr[i];
      }
      cout << "Sum of elements: " << sumArray(arr, size) << endl;
      break;
    }
    case 9:
      // Exit program
      cout << "Thank you for using the Recursion program!" << endl;
      return 0;
    }

    // Newline for spacing
    cout << endl;
  }
}

int gcd(int m, int n) {
  // base case: return second number
  if (m % n == 0)
    return n;
  else // recursive case: call gcd with second number and remainder of division
    return gcd(n, m % n);
}

void evenAndOddCount(int value, int odd, int even) {
  // base case: if value == 0, ouput values
  if (value == 0) {
    cout << "Number of even digits: " << even << endl;
    cout << "Number of odd digits: " << odd << endl;
  } else if (value % 2 == 0)
    // recursive case 1: even digit is found, increase even counter
    return evenAndOddCount(value / 10, odd, even + 1);
  else
    // recursive case 2: if an odd digit is found, increase odd counter
    return evenAndOddCount(value / 10, odd + 1, even);
}

void evenAndOddCount(int value) {
  // Display the number of even and odd digits using our helper functions
  evenAndOddCount(value, 0, 0);
}

void reverseDisplay(const string &s) {
  // Base case: if the string is empty, return nothing
  if (s.length() == 0)
    return;
  else {
    // Recursive case: print last character + call function with substring
    cout << s[s.length() - 1];
    reverseDisplay(s.substr(0, s.length() - 1));
  }
}

int count(const string &s, char a) {
  // Base case: if the string is empty, return 0
  if (s.length() == 0)
    return 0;

  // Recursive case 1: if first character = character "a", increase counter
  if (s[0] == a)
    return 1 + count(s.substr(1), a);
  else
    // Recusive case 2: if first character != character "a", do not increase
    return count(s.substr(1), a);
}

int productDigits(int n) {
  if (n == 0)
    // Base case: if the number is 0, return 1
    return 1;
  else
    // Recursive case: return product of digits and remaining ones
    return (n % 10) * productDigits(n / 10);
}

void reverseDisplayHelper(const string &s) {
  // output result using helper function
  reverseDisplayHelper(s, s.length() - 1);
}

void reverseDisplayHelper(const string &s, int high) {
  if (high == -1)
    // Base case: if the index is -1, return nothing2
    return;
  else {
    // Recursive case: print index, call function again with index - 1
    cout << s[high];
    reverseDisplayHelper(s, high - 1);
  }
}

int smallestElement(int arr[], int size) {
  if (size == 0)
    // Base case: if the array is empty, return a large number
    return INT32_MAX;
  else if (arr[size - 1] < smallestElement(arr, size - 1))
    // Recursive case 1: if element smaller than current return it
    return arr[size - 1];
  else
    // Recursive case 2: if element larger, continue going down function
    return smallestElement(arr, size - 1);
}

int sumArray(int arr[], int size) {
  if (size == 0)
    // Base case: if the array is empty, return 0
    return 0;
  else
    // Recursive case: return sum + next recursive call of function
    return arr[size - 1] + sumArray(arr, size - 1);
}



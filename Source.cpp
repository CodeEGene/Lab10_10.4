#include <iostream>
#include <string>

using namespace std;

const int ARRAYSIZE = 16;

bool isCardValid(int digits[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s, int size);

int main() {
	string cardNumber;
	int digits[ARRAYSIZE];
	int digitPlace = 0;
	int tens = 0;
	int intCardNumber;
	
	cout << "Enter an 8-digit card number or Q to quit: ";
	while (cin >> cardNumber) {
		intCardNumber = stoi(cardNumber);
		for (int i = 0; i < ARRAYSIZE; i++) {
			digitPlace = pow(10, i + 1);
			tens = pow(10, i);
			digits[i] = (intCardNumber % digitPlace) / tens;
		}
		

		if (isCardValid(digits, ARRAYSIZE)) {
			cout << "Card is valid."<<endl;
		}
		else {
			cout << "Card is not vaild." << endl;
		}
		cout << "Enter an 8-digit card number or Q to quit: ";
	}
}

bool isCardValid(int digits[], int size) {
	int firstSum = 0;
	int secondSum = 0;
	int totalSum = firstSum + secondSum;

	for (int i = 0; i < size; i++) {

		if (i % 2 == 0) {
			firstSum += digits[i];
		}
		else {
			secondSum += ((2 * digits[i]) % 10) + ((2 * digits[i]) % 100) / 10;
		}
	}
	totalSum = firstSum + secondSum;

	if ((totalSum % 10) == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool isNumeric(string s) {
	for (auto i : s) {
		if (!isdigit(i)) {
			return false;
		}
	}
	return true;

}
bool isCorrectLength(string s , int size) {
	
	return s.length() == size;
}
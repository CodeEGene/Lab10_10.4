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
	int tens = 0;
	int intCardNumber = 0;
	
	cout << "Enter a 16-digit card number or Q to quit: ";
	while (cin >> cardNumber) {
		if (cardNumber == "Q" || cardNumber == "q") {
			return 1;
		}
		if (!isCorrectLength(cardNumber, ARRAYSIZE)) {
			cout << endl << "Error - card number must contain 16 digits."<<endl;
			cout << "Enter an 16-digit card number or Q to quit: ";
			continue;
		}
		else if (!isNumeric(cardNumber)) {
			cout << endl << "Error - card number must contain only digits." << endl;
			cout << "Enter an 16-digit card number or Q to quit: ";
			continue;
		}


		for (int i = 0; i < ARRAYSIZE; i++) {
			digits[i] = cardNumber[i] - '0';
		}

		if (isCardValid(digits, ARRAYSIZE)) {
			cout << "Card is valid."<<endl;
		}
		else {
			cout << "Card is not vaild." << endl;
		}
		cout << "Enter an 16-digit card number or Q to quit: ";
	}
	return 0;
}

bool isCardValid(int digits[], int size) {
	int firstSum = 0;
	int secondSum = 0;
	int totalSum = firstSum + secondSum;
	int j = 0;

	for (int i = 0 ; i < size; i++) {
		j = size - 1 - i;
		if (i % 2 == 0) {
			firstSum += digits[j];
		}
		else {
			secondSum += ((2 * digits[j]) % 10) + ((2 * digits[j]) % 100) / 10;
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
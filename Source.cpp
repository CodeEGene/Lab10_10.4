#include <iostream>

using namespace std;

const int ARRAYSIZE = 8;

bool isCardValid(int digits[], int size);

int main() {
	int cardNumber;
	int digits[ARRAYSIZE];
	int digitPlace = 0;
	int tens = 0;

	cout << "Enter an 8-digit card number or Q to quit: ";
	while (cin >> cardNumber) {

		for (int i = 0; i < ARRAYSIZE; i++) {
			digitPlace = pow(10, i + 1);
			tens = pow(10, i);
			digits[i] = (cardNumber % digitPlace) / tens;
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
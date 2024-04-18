#include <iostream>

using namespace std;

int main() {
	int cardNumber;
	int digits[8];
	int firstSum = 0;
	int secondSum = 0;
	int totalSum = firstSum + secondSum;

	cout << "Please enter an 8-digit card number: ";
	cin >> cardNumber;

	for (int i = 0; i < 8; i++) {
		int digitPlace = pow(10, i + 1);
		int tens = pow(10, i);
		digits[i] = (cardNumber % digitPlace) / tens;

		if (i % 2 == 0) {
			firstSum += digits[i];
		}
		else {
			secondSum += ((2 * digits[i]) % 10) + ((2 * digits[i]) % 100) / 10;
		}
	}
	totalSum = firstSum + secondSum;

	if ((totalSum % 10) == 0) {
		cout << "Card is valid";
	}
	else {
		cout << "Card is not vaild";
	}
}
#include "Prime.h"
int main() {

	cout << "Enter a prime number " << endl;
	int prime;
	cin >> prime;
	if (isPrime(prime) == true) {

		cout << "The number " << prime << " is a prime number" << endl;
	}
	else {
		cout << prime << " is not a prime number" << endl;
	}
	system("PAUSE");
}
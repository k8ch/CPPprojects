#include "Prime.h"
bool isPrime(int n) {
	//test for the least significant bit for 0 or 1
	int lsb = n & 1; 

	//Check for the first two prime numbers
	if ((n == 2)||(n==3)) {
		return true;
	}
	//If there is no reminder, the number is even and not prime. 
	else if (((n % 2) == 0)||(n == 1)) {
		return false; 
	}
	//loop through all odd numbers starting at x = 3. 
	for (int x = 3; x*x <= n; x=x + 2) {
		if ((n%x) != 0) {
		}
		else {
		
			return false;
		}
	}
	return true;

}

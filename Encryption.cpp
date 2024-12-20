#include <iostream>
#include "Encryption.h"

using namespace std;


int Encryption::encrypt(int password) {
	
	if (password > 9999 || password < 0) {
		cout << "Please enter 4 digit password..." << endl;
		return -1;
	}
		
	int a, b, c, d;
	d = password % 10 + 7;
	password = password / 10;
	c = password % 10 + 7;
	password = password / 10;
	b = password % 10 + 7;
	password = password / 10;
	a = password + 7;


	d = d % 10;
	c = c % 10;
	b = b % 10;
	a = a % 10;
		
	return c * 1000 + d * 100 + a * 10 + b;

}

int Encryption::decrypt(int password) {		
	
	int a, b, c, d;
	d = password % 10 + 3;
	password = password / 10;
	c = password % 10 + 3;
	password = password / 10;
	b = password % 10 + 3;
	password = password / 10;
	a = password % 10 + 3;

	d = d % 10;
	c = c % 10;
	b = b % 10;
	a = a % 10;

	return c * 1000 + d * 100 + a * 10 + b;

}



#include <iostream>
#include "Encryption.h"
using namespace std;

int main() {
	int  password;
	for (int i = 0;i < 10;i++) {

		password = rand() % 10000;
		int encrypted_password = Encryption::encrypt(password);
		cout << "Generated password: " << password << endl;
		int decrypted_password = Encryption::decrypt(encrypted_password);
		//cout << encrypted_password << endl;
		cout << "Decrypted password: " << decrypted_password << endl;

		if (decrypted_password == password) {
			cout << "Password is correct!" << endl;
		}
		else{
			cout << "Password is wrong, please try again!" << endl;

		}
		cout << endl;
	}
	
	for(int j = 0;j < 10;j++){
		int wrong_try_password = 1234;
		password = rand() % 10000;
		int encrypted_password = Encryption::encrypt(password);
		cout << "Generated password:   " << password << endl;
		cout << "Wrong enter password: " << wrong_try_password << endl;
		int decrypted_password = Encryption::decrypt(encrypted_password);
		//cout << encrypted_password << endl;
		cout << "Decrypted password:   " << decrypted_password << endl;

		if (decrypted_password == wrong_try_password) {
			cout << "Password is correct!" << endl;
		}
		else {
			cout << "Password is wrong, please try again!" << endl;

		}
		cout << endl;
	}
	
	return 0;
}

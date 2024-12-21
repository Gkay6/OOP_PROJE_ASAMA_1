#include "RobotOperator.h"
#include <iostream>

using namespace std;

int main() {
   
    cout << "Test 1: Creating robot operator with code 1234" << endl;
    RobotOperator operator1("Elon", "Ma", 1234);
    operator1.print();

    cout << "\nTest 2: Testing access with wrong code (5678)" << endl;
    if (!operator1.checkAccessCode(5678)) {
        cout << "Access correctly denied" << endl;
    }
    operator1.print();

    cout << "\nTest 3: Testing access with correct code (1234)" << endl;
    if (operator1.checkAccessCode(1234)) {
        cout << "Access correctly granted" << endl;
    }
    operator1.print();

    cout << "\nTest 4: Testing encryption of code 4321" << endl;
    int testCode = 4321;
    int encrypted = operator1.encryptCode(testCode);
    cout << "Original code: " << testCode << endl;
    cout << "Encrypted code: " << encrypted << endl;

    cout << "\nTest 5: Testing decryption of encrypted code" << endl;
    int decrypted = operator1.decryptCode(encrypted);
    cout << "Encrypted code: " << encrypted << endl;
    cout << "Decrypted code: " << decrypted << endl;

    cout << "\nTest 6: Testing with invalid code (12345)" << endl;
    RobotOperator operator2("Felix", "Kjellberg", 12345);

    cout << "\nTest 7: Testing with invalid code (-123)" << endl;
    RobotOperator operator3("Henry", "Stickmin", -123);

    return 0;
}

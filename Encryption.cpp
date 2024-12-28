/** 
 * @file   Encryption.cpp
 * @author Beran Çağlı
 * @date   December, 2024
 * @brief  Implementation of the Encryption class methods
 */

#include <iostream>
#include "Encryption.h"

using namespace std;

/*!
 * Encrypts a 4-digit password using the following algorithm:
 * 1. Validates the input password (must be 4 digits)
 * 2. Separates the password into individual digits
 * 3. Adds 7 to each digit and takes modulo 10
 * 4. Rearranges the digits in a specific pattern
 *
 * \param password The 4-digit password to encrypt
 * \return The encrypted password, or -1 if validation fails
 */
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

/*!
 * Decrypts an encrypted password using the following algorithm:
 * 1. Separates the encrypted password into individual digits
 * 2. Adds 3 to each digit and takes modulo 10
 * 3. Rearranges the digits to recover the original password
 *
 * \param password The encrypted password to decrypt
 * \return The original decrypted password
 */
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

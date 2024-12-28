/** 
 * @file   RobotOperator.cpp
 * @author Beran Çağlı
 * @date   December, 2024
 * @brief  Implementation of the RobotOperator class methods
 */

#include "RobotOperator.h"
#include <iostream>

/*!
 * Constructor initializes operator information and encrypts the access code.
 * Initial access state is set to false until verified.
 *
 * \param _name Operator's first name
 * \param _surname Operator's last name
 * \param code Access code to be encrypted and stored
 */
RobotOperator::RobotOperator(const std::string& _surname, int code)
    :surname(_surname), accessState(false) {
    accessCode = Encryption::encrypt(code);
}

/*!
 * Encrypts the provided code using the Encryption class.
 *
 * \param code The code to encrypt
 * \return The encrypted code
 */
int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code);
}

/*!
 * Decrypts the provided encrypted code using the Encryption class.
 *
 * \param code The encrypted code to decrypt
 * \return The decrypted code
 */
int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code);
}

/*!
 * Verifies the provided access code by comparing its encrypted form
 * with the stored encrypted access code.
 *
 * \param code The access code to verify
 * \return true if the codes match, false otherwise
 */
bool RobotOperator::checkAccessCode(int code, bool openAccess) {

    int decryptedPass = Encryption::decrypt(accessCode);
    
    if (code == decryptedPass) {
        if (openAccess) {
            accessState = true;
        }
        else {
            accessState = false;
        }
        return true; // Access code is correct
    }
    
    return false; // Access code is incorrect
}

/*!
 * Prints operator information including name, surname,
 * and current access state to the console.
 */
void RobotOperator::print() const {
    std::cout << "Operator Information: " << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Access State: " << (accessState ? "Access Granted" : "Access Denied") << std::endl;
}

//! Verifies if the provided access code is correct
/*!
 * @return true if access is granted, false otherwise
 */
bool RobotOperator::getAccessState() const
{
    return this->accessState;
}

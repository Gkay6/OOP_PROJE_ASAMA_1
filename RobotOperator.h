/** 
 * @file   RobotOperator.h
 * @author Beran Çağlı
 * @date   December, 2024
 * @brief  Header file for the RobotOperator class that manages robot operator authentication.
 *
 * This class handles operator authentication and access control for robot operations.
 * It uses the Encryption class for secure storage and verification of access codes.
 */

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include "Encryption.h"
#include <string>

using namespace std;

//! RobotOperator class for managing robot operator authentication
/*!
 * This class maintains operator information and handles access control.
 * It stores operator's personal information and encrypted access code.
 */
class RobotOperator {
private:
    string name;            /*!< Operator's first name */
    string surname;         /*!< Operator's last name */
    unsigned int accessCode;/*!< Encrypted access code */
    bool accessState;       /*!< Current access state */
    Encryption encryption;  /*!< Encryption object for security operations */

public:
    //! Constructor for RobotOperator
    /*!
     * @param name Operator's first name
     * @param surname Operator's last name
     * @param code Access code to be encrypted and stored
     */
    RobotOperator(const string& name, const string& surname, int code);

    //! Encrypts a given access code
    /*!
     * @param code The code to encrypt
     * @return The encrypted code
     */
    int encryptCode(int code);

    //! Decrypts a given encrypted code
    /*!
     * @param code The encrypted code to decrypt
     * @return The decrypted code
     */
    int decryptCode(int code);

    //! Verifies if the provided access code is correct
    /*!
     * @param code The access code to verify
     * @return true if access is granted, false otherwise
     */
    bool checkAccessCode(int code);

    //! Prints operator information to console
    /*!
     * Displays name, surname, and current access state
     */
    void print() const;

    //! Gets the current access state
    /*!
     * @return true if operator has access, false otherwise
     */
    bool getAccessState() const;
};

#endif // ROBOTOPERATOR_H

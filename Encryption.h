/** 
 * @file   Encryption.h
 * @author Beran Çağlı
 * @date   December 2024
 * @brief  Header file for the Encryption class that handles password encryption and decryption.
 *
 * This class provides static methods for encrypting and decrypting 4-digit passwords
 * using a specific encryption algorithm. The encryption process involves mathematical
 * operations to transform the digits.
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

//! Encryption class for handling password security
/*!
 * This class provides static methods to encrypt and decrypt 4-digit passwords.
 * The encryption algorithm uses modular arithmetic to transform each digit.
 */
class Encryption {
public:
    //! Encrypts a 4-digit password
    /*!
     * @param password The 4-digit password to encrypt (0-9999)
     * @return The encrypted password, or -1 if the input is invalid
     */
    static int encrypt(int password);

    //! Decrypts an encrypted password
    /*!
     * @param password The encrypted password to decrypt
     * @return The decrypted original password
     */
    static int decrypt(int password);
};

#endif //ENCRYPTION_H

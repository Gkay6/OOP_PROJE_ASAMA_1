#include "RobotOperator.h"
#include <iostream>

RobotOperator::RobotOperator(const std::string& _name, const std::string& _surname, int code)
    : name(_name), surname(_surname), accessState(false) {
    accessCode = Encryption::encrypt(code);
}

int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code);
}

int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code);
}

bool RobotOperator::checkAccessCode(int code) {
    int encryptedInput = Encryption::encrypt(code);
    accessState = (encryptedInput == accessCode);
    return accessState;
}

void RobotOperator::print() const {
    std::cout << "Operator Information: " << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Access State: " << (accessState ? "Access Granted" : "Access Denied") << std::endl;
}

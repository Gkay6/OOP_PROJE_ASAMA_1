#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H
using namespace std;
#include "Encryption.h"
#include <string>

class RobotOperator {
private:
    string name;
    string surname;
    unsigned int accessCode;
    bool accessState;
    Encryption encryption;

public:
    RobotOperator(const string& name, const string& surname, int code);

    int encryptCode(int code);
    int decryptCode(int code);
    bool checkAccessCode(int code);
    void print() const;
    bool getAccessState() const { return accessState; }
};

#endif // ROBOTOPERATOR_H

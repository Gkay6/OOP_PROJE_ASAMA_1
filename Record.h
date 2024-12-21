#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>

class Record {
private:
    std::string fileName;
    std::fstream file;

public:
    Record();
    ~Record();

    bool openFile();
    bool closeFile();
    void setFileName(const std::string& name);
    std::string readLine();
    bool writeLine(const std::string& str);

    Record& operator<<(const std::string& str);
    Record& operator>>(std::string& str);
};

#endif //RECORD_H

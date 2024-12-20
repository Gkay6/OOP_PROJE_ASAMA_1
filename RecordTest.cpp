#include <iostream>
#include "Record.h"

int main() {
    Record record;

    record.setFileName("test.txt");
    if (record.openFile()) {
        std::cout << "Test 1: Dosya başarıyla açıldı." << std::endl;
    }
    else {
        std::cout << "Test 1: Dosya açılamadı!" << std::endl;
    }

    if (record.writeLine("Test satırı 1")) {
        std::cout << "Test 2: Yazma işlemi başarılı." << std::endl;
    }
    else {
        std::cout << "Test 2: Yazma işlemi başarısız!" << std::endl;
    }

    record << "Test satırı 2";
    std::cout << "Test 3: Operator<< test edildi." << std::endl;

    if (record.closeFile()) {
        std::cout << "Test 4: Dosya başarıyla kapatıldı." << std::endl;
    }
    else {
        std::cout << "Test 4: Dosya kapatılamadı!" << std::endl;
    }

    if (record.openFile()) {
        std::cout << "Test 5: Dosya okuma için açıldı." << std::endl;

        std::string line;
        record >> line;
        std::cout << "Test 6: Okunan satır: " << line << std::endl;


        line = record.readLine();
        std::cout << "Test 7: Okunan ikinci satır: " << line << std::endl;
    }

    return 0;
}

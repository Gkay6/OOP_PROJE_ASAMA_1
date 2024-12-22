/** 
 * @file   Record.cpp
 * @author Beran Çağlı
 * @date   December, 2024
 * @brief  Implementation of the Record class methods
 */

#include "Record.h"

/*!
 * Constructor initializes the fileName to empty string.
 */
Record::Record() {
    fileName = "";
}

/*!
 * Destructor ensures that any open file is properly closed
 * before the object is destroyed.
 */
Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

/*!
 * Opens the file specified by fileName for reading and writing.
 * File is opened in append mode, allowing both read and write operations.
 *
 * \return true if file is successfully opened, false if fileName is empty
 *         or file cannot be opened
 */
bool Record::openFile() {
    if (fileName.empty()) {
        return false;
    }

    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    return file.is_open();
}

/*!
 * Closes the currently open file.
 *
 * \return true if file was successfully closed, false if no file was open
 */
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

/*!
 * Sets the name of the file to be operated on.
 *
 * \param name The name of the file to be used for operations
 */
void Record::setFileName(const std::string& name) {
    fileName = name;
}

/*!
 * Reads a single line from the file.
 *
 * \return The line read from the file, or empty string if file is not open
 */
std::string Record::readLine() {
    std::string line;
    if (file.is_open()) {
        std::getline(file, line);
    }
    return line;
}

/*!
 * Writes a string to the file, followed by a newline character.
 *
 * \param str The string to be written to the file
 * \return true if write was successful, false if file is not open
 */
bool Record::writeLine(const std::string& str) {
    if (file.is_open()) {
        file << str;
        return true;
    }
    return false;
}

/*!
 * Overloaded output operator for writing to file.
 * Uses writeLine() internally.
 *
 * \param str The string to be written to the file
 * \return Reference to this Record object for chaining
 */
Record& Record::operator<<(const std::string& str) {
    writeLine(str);
    return *this;
}

/*!
 * Overloaded input operator for reading from file.
 * Uses readLine() internally.
 *
 * \param str Reference to string where read data will be stored
 * \return Reference to this Record object for chaining
 */
Record& Record::operator>>(std::string& str) {
    str = readLine();
    return *this;
}

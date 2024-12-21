/** 
 * @file   Record.h
 * @author Beran Çağlı
 * @date   December, 2024
 * @brief  Header file for the Record class that handles file operations.
 *
 * This class provides functionality for reading from and writing to files,
 * specifically designed for robot applications to handle data recording.
 */

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>

//! Record class for handling file operations
/*!
 * This class manages file operations including opening, closing,
 * reading from, and writing to files. It provides both standard
 * methods and operator overloads for file operations.
 */
class Record {
private:
    std::string fileName;   /*!< Name of the file to be operated on */
    std::fstream file;      /*!< File stream object for I/O operations */

public:
    //! Default constructor
    Record();

    //! Destructor
    /*!
     * Ensures that any open file is properly closed
     */
    ~Record();
    
    //! Opens the file for reading and writing
    /*!
     * @return true if file is successfully opened, false otherwise
     */
    bool openFile();

    //! Closes the currently open file
    /*!
     * @return true if file was open and is now closed, false if no file was open
     */
    bool closeFile();

    //! Sets the name of the file to be operated on
    /*!
     * @param name The name of the file
     */
    void setFileName(const std::string& name);

    //! Reads a line from the file
    /*!
     * @return The line read from the file, empty string if file is not open
     */
    std::string readLine();

    //! Writes a line to the file
    /*!
     * @param str The string to write to the file
     * @return true if write was successful, false if file is not open
     */
    bool writeLine(const std::string& str);

    //! Overloaded output operator for writing to file
    /*!
     * @param str The string to write to the file
     * @return Reference to the Record object for chaining
     */
    Record& operator<<(const std::string& str);

    //! Overloaded input operator for reading from file
    /*!
     * @param str String reference where read data will be stored
     * @return Reference to the Record object for chaining
     */
    Record& operator>>(std::string& str);
};

#endif //RECORD_H

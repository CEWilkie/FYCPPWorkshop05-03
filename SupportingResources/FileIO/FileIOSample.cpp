//
// Created by cew05 on 03/03/2025.
//

// Include the header as this is the implementation file
#include "FileIOSample.h"

// Including fstream for files
#include <fstream>
#include <iostream>

void samples::readFile() {

    // Create file object to read from
    const std::string path = "../SupportingResources/FileIO/FileIO.md";
    std::fstream file(path);

    // Now use a loop to read all lines from the file
    std::string line;
    while (std::getline(file, line))
    {
        printf("%s\n", line.c_str());
//        std::cout << line << std::endl;
    }

    // When a file object destructs itself it should close. However, its good practise
    // to close the file yourself to ensure future usage of the file encounters no issues.
    file.close();
}

void samples::writeFile() {

    // Create file object to read from
    const std::string path = "../SupportingResources/FileIO/FileIO.txt";
    std::fstream file(path);

    // This will write to the start of the file and OVERWRITE anything already there!
    std::string myNewLine = "Whatever was here is gone now!";
    file << myNewLine << std::endl << "This is also overwritten!" << std::endl;

    file.close();

    // So make sure you open the file in APPEND mode if you want to write to the end of it
    std::fstream appendFile(path, std::ios::app);
    appendFile << "This will be at the end!" << std::endl;

    appendFile.close();
}
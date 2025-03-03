# File Reading / Writing

File handling is typically done through including the header `<fstream>`.
Once included, this will allow you to create `std::fstream` objects, which
will accept a file path for a specified file to read/write to.

When using files, take care with your file paths. In Clion with cmake, relative
paths originate from the executable, and so you must first back out of the 
cmake-build-x directory before then giving the path of the file. Appending `../`
to the start of your path string will allow for you to back out of a directory. 
This may be different in other IDEs.

Finally, as a note of good practise it is best to ensure that you close your
file streams once you are done with them. Whilst destructors should handle
file closure when a file object goes out of scope or is deleted, its always
best to keep the code safe.

### Examples

##### Reading Files
```c++
#include <fstream>
#include <iostream>

int main() 
{
    // Create file object to read from
    const std::string path = "./dir/myFile.txt";
    std::fstream file(path);
    
    // Now use a loop to read all lines from the file
    // getline will take each line (string ending with newline char)
    std::string line;
    while (std::getline(file, line))
    {
        // output using formatted print
        printf("%s\n", line.c_str());
        
        // same as
        // std::cout << line << std::endl;
    }
    
    file.close();   
}
```


##### Writing to Files
```c++
#include <fstream>
#include <iostream>

int main() 
{
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
```
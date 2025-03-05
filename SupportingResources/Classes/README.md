# Classes and Objects

A class is a template from which object instances can be built. Classes can
contain their own variables and functions, and additionally have shared (static)
variables where the data remains the same across all classes.

The contents within a class can be split into 2 primary categories of 
private and public data. Private data can only be accessed from within the
class itself - its functions for example. Public data can be accessed from 
anywhere, with no restrictions. This often leads to the necessity of 
Setter/Getter functions - these are public functions employed in order for the
rest of the program to access the private data.

You should utilise private elements for enforcing particular conditions or 
formats on the data stored in the variables. Or alternatively, it can help 
indicate the functions that should be or can be suitably interacted with - 
the private functions would hence indicate processes used by other 
public functions and shouldnt be called as a stand-alone function.

### Headers and CPP Files

With classes, it can be beneficial to split their declaration and definition
across multiple files. This not only helps prevent file bloat, but also builds
upon C++'s system of including header files to bring together multiple components.

### Inheritance

Class Inheritance isnt terrible! The key part is that when you declare your
child class, you make sure to use 
`class <MyClassName> : public <ParentClassName> {};` - replacing the `<>` 
with your actual class names.

The inheriting class will gain access to anything declared as a public or 
protected element within the parent class. The Parent class will not gain 
any elements from the child though. Its just 1-Way.

### Examples

Here is an example of a simple class - ParentClass. The class has been split 
into a .cpp and .h file.

```c++
// ParentClass.h

#include <string>
#include <vector>

/*
 * In the header file we will declare the class, its functions and variables. When you want to use
 * the class in another file, you should ONLY include the class header. You could implement a
 * handful of definitions for getter functions in the header, but generally you should aim to split
 * the declaration and impementation into header and cpp files.
 */

class ParentClass {

    // Public elements of the class are accessible to anything anywhere.
    public:

        // explicit constructor. Explicit will prevent against accidental type conversions
        // as ParentClass("some given string") can also be interpreted as a typecast of the
        // string value to type ParentClass
        explicit ParentClass(const std::string& _name);
        
        // You can have multiple different constructors!
        ParentClass();
        
        ~ParentClass();

        // Function belonging to the class
        void addChild(const std::string& _childName);

        // this function is virtual, meaning that if a child class needs to, it can redefine
        // the function
        virtual void sayHi();

        // public getter functions to access the contents of private data
        std::string getName() { return name; }
        std::vector<std::string> getChildren() { return children; }

    // Protected elements of a class are accessible only to child classes. Aside from that, they act
    // as private elements do
    protected:
        std::string name {"Default McNamey"};

    // Private elements cannot be accessed from anywhere but within the class and its functions.
    // Hence, private variables will require a public getter/setter to access/alter them.
    // Private elements are not shared to child classes.
    private:
        std::vector<std::string> children;
};
```


```c++
// ParentClass.cpp

#include "ParentClass.h"

// This is a constructor. It is used to create the object
ParentClass::ParentClass(const std::string& _name) {
    name = _name;
}

// This means that the default destructor will be used
// Destructors are called when a program goes out of scope, and clean up the object and its memory
ParentClass::~ParentClass() = default;

// This function is public and interacts with an otherwise hidden private variable (children)
// This function is called a Setter due to its interaction and use case
void ParentClass::addChild(const std::string& _childName) {
    children.push_back(_childName);
}

// This is the default implementation of the virtual function
void ParentClass::sayHi() {
    printf("Hello! I am %s. My children are: ", name.c_str());

    // Use a for-each loop for each child in the children vector
    for (const std::string& _child : children) {
        printf("%s", _child.c_str());
    }
}
```
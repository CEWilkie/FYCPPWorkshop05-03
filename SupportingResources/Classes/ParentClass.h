//
// Created by cew05 on 03/03/2025.
//

#ifndef CPPSUPPORTWORKSHOP_PARENTCLASS_H
#define CPPSUPPORTWORKSHOP_PARENTCLASS_H

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


#endif //CPPSUPPORTWORKSHOP_PARENTCLASS_H

//
// Created by cew05 on 03/03/2025.
//

#include "ParentClass.h"

// This is a constructor. It is used to create the object
ParentClass::ParentClass(const std::string& _name) {
    name = _name;
}

// This means that the default constructor will be used
ParentClass::ParentClass() = default;

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
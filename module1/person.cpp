#include <iostream>
#include <string>

class Person {
    const std::string name_;
    unsigned age_;

public:
    Person(const std::string & name, unsigned age)
        : name_(name), age_(age)
    {}

    std::string getName() const { return name_; }
    // void setName(const std::string & name) { name_ = name; }
    // not allowed, name_ is const

    unsigned getAge() const { return age_; }
    void setAge(unsigned age) { age_ = age; }
};

void printPerson(const Person & p) {
    std::cout << "Name: " << p.getName() << ", age: " << p.getAge() << '\n';
    // p.setAge(-1);
    // impossible, p passed as const& - read only
    // clang error: 'this' argument to member function 'setAge' has type 'const Person', but function is not marked const
    // g++ error: passing 'const Person' as 'this' argument discards qualifiers [-fpermissive]
}

int main() {
    Person adam{"Adam", 25};
    std::cout << "Hello " << adam.getName() << '\n';

    adam.setAge(50);
    std::cout << adam.getName() << ", you look older! Are you really " << adam.getAge() << "?\n";

    const Person eva{"Eva", 30};
    // eva.setAge(40);
    // not possible, eva is const.

    printPerson(adam);
    printPerson(eva);
}

#include "src/domain/People/Person.h" 
#include <iostream>
#include <string>
#include <stdexcept>
 
Person::Person(std::string name, int age): id_(personCount_ + 1) {
    if(!setName(name)) {
        throw std::invalid_argument("Невалидное имя!");
    }
    if(!setAge(age)) {
        throw std::invalid_argument("Невалидный возраст!");
    } 
    personCount_++;
}

int Person::getId() const {
    return id_;
}

std::string Person::getName() const {
    return name_;
}

int Person::getAge() const {
    return age_;
}

bool Person::setName(const std::string& name) {
    if(name.empty()) {
        return false;
    }
    name_ = name;
    return true;
}

bool Person::setAge(int age) {
    if((age >= 16) && (age <= 100)) {
        age_ = age;
        return true;
    }
    return false;
}

void Person::print() const {
    std::cout << "Имя: " << name_ << std::endl;
    std::cout << "Возраст: " << age_ << std::endl;
}

int Person::personCount_ = 0; 

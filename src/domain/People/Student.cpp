#include "src/domain/People/Person.h"
#include "src/domain/People/Student.h"
#include <iostream>
#include <string>
#include <stdexcept>

Student::Student(std::string name, int age, std::string group, int year): Person(name, age) {
    if(!setGroup(group)) {
        throw std::invalid_argument("Невалидная группа!");
    }
    if(!setYear(year)) {
        throw std::invalid_argument("Невалидный год!");
    }
}

std::string Student::getName() const {
    return "Студент " + Person::getName();
}

std::string Student::getGroup() const {
    return group_;
}

int Student::getYear() const {
    return year_;
}

bool Student::setGroup(std::string group) {
    if(group.empty()) {
        return false;
    }
    group_ = group;
    return true;
}

bool Student::setYear(int year) {
    if((1 <= year) && (year <= 6)) {
        year_ = year;
        return true;
    }
    return false;
}

void Student::print() const {
    Person::print();
    std::cout << "Группа: " << group_ << std::endl;
    std::cout << "Год: " << year_ << std::endl;
}


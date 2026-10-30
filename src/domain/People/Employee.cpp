#include "src/domain/People/Employee.h"
#include "src/domain/People/Person.h"
#include "src/domain/People/Student.h"
#include "src/domain/Building.h"
#include <iostream>
#include <string>
#include <stdexcept>

Employee::Employee(
std::string name, int age, std::string position, Building* workplace
): Person(name, age), workplace_(workplace) {
    if(!setPosition(position)) {
        throw std::invalid_argument("Невалидная должность!");
    }
}

std::string Employee::getName() const{
    return "Сотрудник " + Person::getName();
}

std::string Employee::getPosition() const {
    return position_;
}

Building* Employee::getWorkplace() const {
    return workplace_;
}

bool Employee::setPosition(std::string position) {
    if(position.empty()) {
        return false;
    }
    position_ = position;
    return true;
}

bool Employee::assignBuilding(Building& workplace) {
    workplace_ = &workplace;
    return true;
}

bool Employee::admitStudent(Building& building, Student& student) {
    if(workplace_ != &building) {
        return false;
    }
    return building.addStudent(student);
}

void Employee::print() const {
    Person::print();
    std::cout << "Должность: " << position_ << std::endl;
    if(workplace_ == nullptr) {
        std::cout << "Место работы: не определено" << std::endl; 
    }
    else {
        std::cout << "Место работы: " << workplace_->getAddress() << std::endl;
    }
}
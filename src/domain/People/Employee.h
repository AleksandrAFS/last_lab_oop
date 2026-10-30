#pragma once
#include "src/domain/People/Person.h"
#include <string>

class Building;
class Student;

class Employee: public Person {
    private:
        std::string position_;
        Building* workplace_ = nullptr;
    public:
        Employee(std::string name, int age, std::string position, Building* workplace);
        std::string getName() const override;
        std::string getPosition() const;
        Building* getWorkplace() const;
        bool setPosition(std::string position);
        bool assignBuilding(Building& workplace);
        bool admitStudent(Building& building, Student& student);
        void print() const override;
};
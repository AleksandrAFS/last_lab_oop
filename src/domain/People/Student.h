#pragma once
#include "src/domain/People/Person.h" 
#include <string>

class Student: public Person {
    private:
        std::string group_;
        int year_;
    public:
        Student(std::string name, int age, std::string group, int year);
        std::string getName() const override;
        std::string getGroup() const;
        int getYear() const;
        bool setGroup(std::string group);
        bool setYear(int year);
        void print() const override;
};


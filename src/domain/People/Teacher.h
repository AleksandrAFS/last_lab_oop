#pragma once
#include "src/domain/People/Person.h"
#include <string>

class Course;
class Student;

class Teacher: public Person {
    private:
        std::string department_;
        std::string subject_;
    public:
        Teacher(std::string name, int age, std::string department, std::string subject);
        std::string getName() const override;
        std::string getDepartment() const;
        std::string getSubject() const;
        bool setDepartment(std::string department);
        bool setSubject(std::string subject);
        bool enrollStudent(Course& course, Student& student);
        void print() const override;
};
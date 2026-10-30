#include "src/domain/People/Teacher.h"
#include "src/domain/People/Person.h"
#include "src/domain/People/Student.h"
#include "src/domain/Courses/Course.h"
#include <iostream>
#include <string>
#include <stdexcept>

Teacher::Teacher(std::string name, int age, std::string department, std::string subject): Person(name, age) {
    if(!setDepartment(department)) {
        throw std::invalid_argument("Невалидная кафедра!"); 
    }
    if(!setSubject(subject)) {
        throw std::invalid_argument("Невалидный предмет!");
    }
}

std::string Teacher::getName() const {
    return "Преподаватель " + Person::getName();
}

std::string Teacher::getDepartment() const {
    return department_;
}

std::string Teacher::getSubject() const {
    return subject_;
}

bool Teacher::setDepartment(std::string department) {
    if(department.empty()) {
        return false;
    }
    department_ = department;
    return true;
}

bool Teacher::setSubject(std::string subject) {
    if(subject.empty()) {
        return false;
    }
    subject_ = subject;
    return true;
}

bool Teacher::enrollStudent(Course& course, Student& student) {
    if(course.getTeacher() == nullptr) {
        return false;
    }
    if(course.getTeacher() == this)  {
        return course.addStudent(student);
    }
    return false;
}

void Teacher::print() const {
    Person::print();
    std::cout << "Кафедра: " << department_ << std::endl;
    std::cout << "Предмет: " << subject_ << std::endl;
}


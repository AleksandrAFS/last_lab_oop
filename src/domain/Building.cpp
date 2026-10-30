#include "src/domain/Building.h"
#include "src/domain/People/Student.h"
#include "src/domain/Courses/Course.h"
#include <iostream>
#include <string>
#include <stdexcept>

Building::Building(std::string name, std::string address, int studentCapacity): id_(countBuilding_ + 1) {
    if(!setName(name)) {
        throw std::invalid_argument("Невалидное название!");
    }
    if(!setAddress(address)) {
        throw std::invalid_argument("Невалидный адрес!");
    }
    if(!((1 <= studentCapacity) && (studentCapacity <= 100))) {
        throw std::invalid_argument("Невалидный максимум зарегистрированных студентов!");
    }
    studentCapacity_ = studentCapacity;
    countBuilding_ ++;
}

int Building::getId() const {
    return id_;
}

std::string Building::getName() const {
    return name_;
}

std::string Building::getAddress() const {
    return address_;
}

int Building::getStudentCapacity() const {
    return studentCapacity_;
}

int Building::getStudentCount() const {
    return studentCount_;
}

int Building::getCourseCount() const {
    return courseCount_;
}

bool Building::setName(std::string name) {
    if(name.empty()) {
        return false;
    }
    name_ = name;
    return true;
}

bool Building::setAddress(std::string address) {
    if(address.empty()) {
        return false;
    }
    address_ = address;
    return true; 
}

bool Building::addStudent(Student& student) {
    if(hasStudent(student.getId())) {
       return false; 
    }
    for(int i = 0; i < studentCapacity_; i++) {
        if(students_[i] == nullptr) {
            students_[i] = &student;
            studentCount_ ++;
            return true;
        }
    }
    return false;
}

bool Building::hasStudent(int studentId) const {
    for(int i = 0; i < studentCapacity_; i++) {
        if((students_[i] != nullptr) && (students_[i]->getId() == studentId)) {
            return true;
        }
    }
    return false;
}

bool Building::addCourse(Course& course) {
    if(hasCourse(course.getId()) || (course.getId() <= 0)) {
       return false; 
    }
    for(int i = 0; i < 20; i++) {
        if(courses_[i] == nullptr) {
            courses_[i] = &course;
            courseCount_ ++;
            return true;
        }
    }
    return false;
}

bool Building::hasCourse(int courseId) const {
    for(int i = 0; i < 20; i++) {
        if((courses_[i] != nullptr) && (courses_[i]->getId() == courseId)) {
            return true;
        }
    }
    return false;
}

Building& Building::operator+(Course& course) {
    if(!addCourse(course)) {
        throw std::runtime_error("Курс невозможно добавить!");
    }
    return *this;
}

Course& Building::operator[](int index) {
    if((index >= 20) || (index < 0) || (courses_[index] == nullptr)) {
        throw std::out_of_range("Курса под этим индексом нет!");
    }
    return *courses_[index];
}

const Course& Building::operator[](int index) const {
    if((index >= 20) || (index < 0) || (courses_[index] == nullptr)) {
        throw std::out_of_range("Курса под этим индексом нет!");
    }
    return *courses_[index];
}

void Building::print() const {
    std::cout << "--Здание университета--" << std::endl;
    std::cout << "Айди: " << id_ << std::endl;
    std::cout << "Название: " << name_ << std::endl;
    std::cout << "Адрес: " << address_ << std::endl;
    std::cout << "Количество действующих курсов: " << courseCount_ << std::endl;
    if(courseCount_ > 0) {
        std::cout << "Айди Название Количество часов" << std::endl;
        for(int i = 0; i < 20; i++) {
            if(courses_[i] != nullptr) {
                std::cout << courses_[i]->getId() << " - " << courses_[i]->getTitle() << " - " << courses_[i]->getHours() << std::endl;
            }
        }
    }
    std::cout << "Максимальное количество студентов: " << studentCapacity_ << std::endl;
    std::cout << "Зарегистрированно студентов: " << studentCount_ << std::endl;
    if(studentCount_ > 0) {
        for(int i = 0; i < studentCapacity_; i++) {
            if(students_[i] != nullptr) {
                std::cout << "-----------------" << std::endl;
                students_[i]->print();
            }
        }
    }
}

int Building::countBuilding_ = 0;
#include "src/domain/Courses/Course.h"
#include "src/domain/People/Teacher.h"
#include "src/domain/People/Student.h"
#include <string>
#include <iostream>
#include <stdexcept>

Course::Course(): id_(0), title_(""), hours_(0), capacity_(30) {}

Course::Course(int id, std::string title, int hours, int capacity) {
    if(id <= 0) {
        throw std::invalid_argument("Невалидный айди");
    }
    id_ = id;
    if(!setTitle(title)) {
        throw std::invalid_argument("Невалидное название курса!");
    }
    if(!setHours(hours)) {
        throw std::invalid_argument("Невалидное количество часов!");
    }
    if(!((1 <= capacity) && (capacity <= 30))) {
        throw std::invalid_argument("Невалидный максимум количества студентов на курсе!");
    }
    capacity_ = capacity;
}

Course::Course(const Course& other): 
    id_(other.id_), 
    title_(other.title_), 
    hours_(other.hours_), 
    capacity_(other.capacity_), 
    teacher_(other.teacher_), 
    studentCount_(other.studentCount_) {
    for(int i = 0; i < 30; i++) { 
        students_[i] = other.students_[i];
    }   
}

int Course::getId() const {
    return id_;
}

std::string Course::getTitle() const {
    return title_;
}

int Course::getHours() const {
    return hours_;
}

int Course::getCapacity() const {
    return capacity_;
}

int Course::getStudentCount() const {
    return studentCount_;
}

Teacher* Course::getTeacher() const {
    return teacher_;
}

bool Course::setTitle(std::string title) {
    if(title.empty()) {
        return false;
    }
    title_ = title;
    return true;
}

bool Course::setHours(int hours) {
    if(hours > 0) {
        hours_ = hours;
        return true;
    }
    return false;
}

bool Course::assignTeacher(Teacher& teacher) {
    teacher_ = &teacher;
    return true;
}

bool Course::addStudent(Student& student) {
    if(hasStudent(student.getId())) {
        return false;
    }
    for(int i = 0; i < capacity_; i++) {
        if(students_[i] == nullptr) {
            students_[i] = &student;
            studentCount_++;
            return true;
        }
    }
    return false;
}

bool Course::hasStudent(int studentId) const {
    for(int i = 0; i < capacity_; i++) {
        if((students_[i] != nullptr) && (students_[i]->getId() == studentId)) {
            return true;
        }
    }
    return false;
}

bool Course::configure(int id, const std::string& title, int hours, int capacity) {
    if((id_ != 0) || (id <= 0) || (title.empty()) || (hours <= 0) ||(!((1 <= capacity) && (capacity <= 30)))) {
        return false;
    }
    id_ = id;
    title_ = title;
    hours_ = hours;
    capacity_ = capacity;
    return true;
}

Course& Course::operator+(Student& student) {
    if(!addStudent(student)) {
        throw std::runtime_error("Невозможно добавить студента!");
    }
    return *this;
}

Student& Course::operator[](int index) {
    if((index < 0) || (index >= capacity_) || (students_[index] == nullptr)) {
        throw std::out_of_range("Студента под этим индексом нет!");
    }
    return *students_[index];
}

const Student& Course::operator[](int index) const {
    if((index < 0) || (index >= capacity_) || (students_[index] == nullptr)) {
        throw std::out_of_range("Студента под этим индексом нет!");
    }
    return *students_[index];
}

std::string Course::getType() const {
    return "Учебный курс";
}

void Course::print() const {
    std::cout << "--Курс--" << std::endl;
    std::cout << "Айди: " << id_ << std::endl;
    std::cout << "Название: " << title_ << std::endl;
    std::cout << "Тип: " << getType() << std::endl;
    std::cout << "Время: " << hours_ << std::endl;
    std::cout << "Максимум студентов: " << capacity_ << std::endl;
    if(teacher_ != nullptr) {
        std::cout << "Преподаватель:" << std::endl;
        teacher_->print();
    }
    std::cout << "Учащиеся: " << studentCount_ << std::endl;
    if(studentCount_ > 0) {
        for(int i = 0; i < capacity_; i++) {
            if(students_[i] != nullptr) {
                std::cout << "-----------------" << std::endl;
                students_[i]->print();
            }
        }
    }
}
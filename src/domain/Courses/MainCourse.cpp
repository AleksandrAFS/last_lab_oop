#include "src/domain/Courses/MainCourse.h"
#include "src/domain/Courses/Course.h"
#include <iostream>
#include <string>
#include <stdexcept>

MainCourse::MainCourse(): Course(), semester_(1), assessment_("зачёт") {}

MainCourse::MainCourse(
    int id, std::string title, int hours, int capacity, int semester, std::string assessment
): Course(id, title, hours, capacity) {
    if(!setSemester(semester)) {
        throw std::invalid_argument("Невалидный семестр!");
    }
    if(!setAssessment(assessment)) {
        throw std::invalid_argument("Невалидная форма контроля!");
    }
}

MainCourse::MainCourse(const MainCourse& other): Course(other), semester_(other.semester_), assessment_(other.assessment_) {}

int MainCourse::getSemester() const {
    return semester_;
} 

std::string MainCourse::getAssessment() const {
    return assessment_;
}

bool MainCourse::setSemester(int semester) {
    if((1 <= semester) && (semester <= 12)) {
        semester_ = semester;
        return true;
    }
    return false;
}

bool MainCourse::setAssessment(std::string assessment) {
    if((assessment == "зачёт") || (assessment == "экзамен")) {
        assessment_ = assessment;
        return true;
    }
    return false;
}

std::string MainCourse::getType() const {
    return "Основной учебный курс";
}

void MainCourse::print() const {
    Course::print();
    std::cout << "Cеместр: " << semester_ << std::endl;
    std::cout << "Форма контроля: " << assessment_ << std::endl;
}
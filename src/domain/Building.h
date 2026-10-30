#pragma once
#include <string>

class Student;
class Course;

class Building {
    private:
        static int countBuilding_;
        int id_;
        std::string name_;
        std::string address_;
        int studentCapacity_;
        Student* students_[100] = {};
        Course* courses_[20] = {};
        int studentCount_ = 0;
        int courseCount_ = 0;
    public:
        Building(std::string name, std::string address, int studentCapacity);
        int getId() const;
        std::string getName() const;
        std::string getAddress() const;
        int getStudentCapacity() const;
        int getStudentCount() const;
        int getCourseCount() const;
        bool setName(std::string name);
        bool setAddress(std::string address);
        bool addStudent(Student& student);
        bool hasStudent(int studentId) const;
        bool addCourse(Course& course);
        bool hasCourse(int courseId) const;
        Building& operator+(Course& course);
        const Course& operator[](int index) const;
        Course& operator[](int index);
        void print() const;
};
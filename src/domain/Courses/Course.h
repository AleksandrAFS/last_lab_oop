#pragma once
#include <string>

class Teacher;
class Student;

class Course {
    private:
        int id_;
        std::string title_;
        int hours_;
        int capacity_;
        Teacher* teacher_ = nullptr;
        Student* students_[30] = {};
        int studentCount_ = 0;
    public:
        Course();
        Course(int id, std::string title, int hours, int capacity);
        Course(const Course& other);
        int getId() const;
        std::string getTitle() const;
        int getHours() const;
        int getCapacity() const;
        int getStudentCount() const;
        Teacher* getTeacher() const;
        bool setTitle(std::string title); 
        bool setHours(int hours);
        bool assignTeacher(Teacher& teacher);
        bool addStudent(Student& student);
        bool hasStudent(int studentId) const;
        bool configure(int id, const std::string& title, int hours, int capacity);
        Course& operator+(Student& student);
        Student& operator[](int index);
        const Student& operator[](int index) const;
        virtual std::string getType() const;
        virtual void print() const;
        virtual ~Course() = default;
};
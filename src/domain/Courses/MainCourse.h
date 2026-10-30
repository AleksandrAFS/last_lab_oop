#pragma once
#include "src/domain/Courses/Course.h"
#include <string>

class MainCourse: public Course {
    private:
        int semester_;
        std::string assessment_;
    public:
        MainCourse();
        MainCourse(int id, std::string title, int hours, int capacity, int semester, std::string assessment);
        MainCourse(const MainCourse& other);
        int getSemester() const; 
        std::string getAssessment() const;
        bool setSemester(int semester);
        bool setAssessment(std::string assessment);
        std::string getType() const override;
        void print() const override;
};
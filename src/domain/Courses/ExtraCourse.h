#pragma once
#include "src/domain/Courses/Course.h"
#include <string>

class ExtraCourse: public Course { 
    private:
        std::string platform_; 
        int durationWeeks_;
    public:
        ExtraCourse();
        ExtraCourse(int id, std::string title, int hours, int capacity, std::string platform, int durationWeeks);
        ExtraCourse(const ExtraCourse& other);
        std::string getPlatform() const;
        int getDurationWeeks() const;
        bool setPlatform(std::string platform);
        bool setDurationWeeks(int durationWeeks);
        std::string getType() const override;
        void print() const override;
};
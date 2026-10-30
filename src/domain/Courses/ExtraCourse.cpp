#include "src/domain/Courses/ExtraCourse.h"
#include "src/domain/Courses/Course.h"
#include <iostream>
#include <string>
#include <stdexcept>

ExtraCourse::ExtraCourse(): Course(), platform_("Не указана"), durationWeeks_(1) {}

ExtraCourse::ExtraCourse(
int id, std::string title, int hours, int capacity, std::string platform, int durationWeeks
): Course(id, title, hours, capacity) {
    if(!setPlatform(platform)) {
        throw std::invalid_argument("Невалидная платформа!");
    }
    if(!setDurationWeeks(durationWeeks)) {
        throw std::invalid_argument("Невалидное количество недель!");
    }
}

ExtraCourse::ExtraCourse(
    const ExtraCourse& other
): Course(other), platform_(other.platform_), durationWeeks_(other.durationWeeks_) {}

std::string ExtraCourse::getPlatform() const {
    return platform_;
}

int ExtraCourse::getDurationWeeks() const {
    return durationWeeks_;
}

bool ExtraCourse::setPlatform(std::string platform) {
    if(platform.empty()) {
        return false;
    }
    platform_ = platform;
    return true;
}

bool ExtraCourse::setDurationWeeks(int durationWeeks) {
    if(durationWeeks > 0) {
        durationWeeks_ = durationWeeks;
        return true;
    }
    return false;
}

std::string ExtraCourse::getType() const {
    return "Дополнительное образование (заочно)";
}

void ExtraCourse::print() const {
    Course::print();
    std::cout << "Платформа: " << platform_ << std::endl;
    std::cout << "Количество недель: " << durationWeeks_ << std::endl;
}
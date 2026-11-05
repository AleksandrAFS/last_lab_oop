#include "tests/step1.4.h"
#include "src/domain/People/Person.h"
#include "src/domain/Building.h"
#include "src/domain/Courses/Course.h"
#include <cassert>
#include <stdexcept>
#include <iostream>

void step_1_4() {
    Person Anonymous("Alex", 18);
    Anonymous.print();
    Building X("X", "г. Москва ул. Тверская", 50);
    X.print();
    Course Test(1, "Тестирование", 50, 20);
    Test.print();

    try {
        Person ErrName("", 1);
        assert(false && "При таком имени невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}
    
    try {
        Person ErrAge("Sasha", -1);
        assert(false && "При таком возрасте невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}

    try {
        Building ErrTitle("", "г. Москва ул. Тверская", 50);
        assert(false && "При таком названии невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}

    try {
        Building ErrAdress("X", "", 50);
        assert(false && "При таком адресе невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}

    try {
        Course ErrTitle(1, "", 50, 20);
        assert(false && "При таком названии невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}

    try {
        Course ErrHours(1, "Тестирование", -1, 20);
        assert(false && "При таком кол-ве часов невозможно создать экземпляр!");
    }
    catch(const std::invalid_argument&) {}

    std::cout << "Тест 1.4 выполнился без ошибок!" << std::endl;
}
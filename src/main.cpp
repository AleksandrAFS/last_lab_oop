#include "src/domain/People/Student.h"
#include "src/domain/People/Teacher.h"
#include "src/domain/People/Employee.h"
#include "src/domain/Building.h"
#include "src/domain/Courses/MainCourse.h"
#include "src/domain/Courses/ExtraCourse.h"
#include "tests/step1.4.h"
#include "tests/step2.4.h"
#include "tests/step3.2.h"
#include <cassert>
#include <stdexcept>
#include <iostream>

int main() {
    step_1_4();
    step_2_4();
    step_3_2();
    Student Anna("Анна", 18, "261-351", 1);
    Student Ivan("Иван", 19, "261-351", 1);
    Student Vova("Вова", 18, "261-351", 1);
    Teacher Olga("Ольга", 37, "ФИТ", "Базы данных");
    Building A("АВ", "Метро Автозаводская", 2);
    Building B("ПК", "Метро ВДНХ", 100);
    Employee Pavel("Павел", 40, "Системный администратор", &A);
    MainCourse CPlusPlus(1, "C++", 100, 2, 1, "экзамен");
    ExtraCourse DataAnalysis(2, "Анализ данных", 100, 1, "СДО", 8);

    CPlusPlus.assignTeacher(Olga);
    DataAnalysis.assignTeacher(Olga);

    assert(
        (Olga.enrollStudent(CPlusPlus, Anna) == true) && 
        "Должен быть успех, т.к. в курсе по C++ указали, что может быть 2 студента! Анна занимает 1 место."
    );
    assert(
        (Olga.enrollStudent(CPlusPlus, Anna) == false) && 
        "Должен быть отказ, т.к. Анну уже записали!"
    );
    assert(
        (Olga.enrollStudent(CPlusPlus, Ivan) == true) && 
        "Должен быть успех, т.к. в курсе по C++ указали, что может быть 2 студента! Иван занимает 2 место."
    );
    assert(
        (Olga.enrollStudent(CPlusPlus, Vova) == false) && 
        "Должен быть отказ, т.к. в курсе по C++ указали, что может быть 2 студента, а Вова уже 3!"
    );
    assert(
        (Pavel.admitStudent(A, Anna) == true) && 
        "Должен быть успех, т.к. указали, что место работы Павла в корпусе A(поэтому он может записать туда)!"
    );
    assert(
        (Pavel.admitStudent(B, Anna) == false) && 
        "Должен быть отказ, т.к. Павел не работает в корпусе B => не может записать туда!"
    );
    
    A + CPlusPlus;
    
    try {
        A + CPlusPlus;
        assert(false && "Должна быть ошибка, т.к. этот курс уже добавлен!");
    }
    catch(const std::runtime_error&) {}

    A + DataAnalysis;

    assert(
        (A[0][0].getName() == "Студент Анна") && 
        "Берем из A 1-ый курс(т.е. C++) и из него берем 1-го студента(т.е. Анну), так изначально задавали => другого поведения не ожидается!"
    );

    try {
        CPlusPlus[-1];
        assert(false && "Поиск по отрицательным индексам не предусмотрен!");
    }
    catch(const std::out_of_range&) {}

    ExtraCourse CopyDataAnalysis(DataAnalysis);

    CopyDataAnalysis.addStudent(Anna);

    assert(
        (CopyDataAnalysis.getStudentCount() == 1) && 
        (DataAnalysis.getStudentCount() == 0) && 
        "В копии экземпляра линковки списка студентов с оригинальным не предусмотрено!"
    );
    
    std::cout << "Основной тест завершился без ошибок!" << std::endl;

    return 0;
}
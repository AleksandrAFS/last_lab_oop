#include "src/domain/People/Student.h"
#include "src/domain/People/Teacher.h"
#include "src/domain/People/Employee.h"
#include "src/domain/Building.h"
#include "src/domain/Courses/MainCourse.h"
#include "src/domain/Courses/ExtraCourse.h"
#include <cassert>
#include <stdexcept>
#include <iostream>

int main() {
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
    assert(Olga.enrollStudent(CPlusPlus, Anna) == true);
    assert(Olga.enrollStudent(CPlusPlus, Anna) == false);
    assert(Olga.enrollStudent(CPlusPlus, Ivan) == true);
    assert(Olga.enrollStudent(CPlusPlus, Vova) == false);
    assert(Pavel.admitStudent(A, Anna) == true);
    assert(Pavel.admitStudent(B, Anna) == false);
    A + CPlusPlus;
    bool flag = true;
    try {
        A + CPlusPlus;
    }
    catch (const std::runtime_error& e) {
        flag = false;
    }
    assert(flag == false);
    A + DataAnalysis;
    assert(A[0][0].getName() == "Студент Анна");
    flag = true;
    try {
        CPlusPlus[-1];
    }
    catch (const std::out_of_range& e) {
        flag = false;
    }
    assert(flag == false);
    ExtraCourse CopyDataAnalysis(DataAnalysis);
    assert(CopyDataAnalysis.addStudent(Anna) == true);
    std::cout << "Все тесты завершились без ошибок!" << std::endl;
    return 0;
}
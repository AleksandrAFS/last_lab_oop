#include "src/domain/Courses/Course.h"
#include "src/domain/Courses/MainCourse.h"
#include "src/domain/People/Person.h"
#include "src/domain/People/Employee.h"
#include "src/domain/People/Student.h"
#include "src/domain/People/Teacher.h"
#include "tests/step3.2.h"
#include <cassert>
#include <string>
#include <iostream>

void step_3_2() {
    Course ProgrammingLanguage = {};
    MainCourse Python(1, "Питон", 1000, 20, 2, "зачёт");
    MainCourse PythonCopy(Python);
    Employee Grisha("Гриша", 50, "Завхоз", nullptr);
    Teacher Anton("Антон", 39, "ФИТ", "Сети");
    Student TestStudentOne("Саша", 20, "261-251", 2);
    Student TestStudentTwo("Маша", 21, "261-241", 3);

    assert(
        (ProgrammingLanguage.configure(0, "", 0, 0) == false) && 
        (ProgrammingLanguage.getId() == 0) &&
        ProgrammingLanguage.getTitle().empty() &&
        (ProgrammingLanguage.getHours() == 0) &&
        (ProgrammingLanguage.getCapacity() == 30) &&
        (ProgrammingLanguage.getTeacher() == nullptr) &&
        (ProgrammingLanguage.getStudentCount() == 0) &&
        "Должно отклонить и ничего не изменить!"
    );
    
    assert(
        (ProgrammingLanguage.configure(2, "Java", 1500, 20) == true) && 
        (ProgrammingLanguage.getId() == 2) &&
        (ProgrammingLanguage.getTitle() == "Java") &&
        (ProgrammingLanguage.getHours() == 1500) &&
        (ProgrammingLanguage.getCapacity() == 20) &&
        (ProgrammingLanguage.getTeacher() == nullptr) &&
        (ProgrammingLanguage.getStudentCount() == 0) &&
        "Должно выдать true и изменить определенные параметры!"
    );

    Python.addStudent(TestStudentOne);
    PythonCopy.addStudent(TestStudentTwo);
    assert(
        (Python.hasStudent(TestStudentTwo.getId()) == false) &&
        (PythonCopy.hasStudent(TestStudentOne.getId()) == false) &&
        "Проверка на линковку списков участников в копии и оригинале!"
    );

    assert((PythonCopy.getType() == "Основной учебный курс") && "Проверка на сохранение типа!"); 

    Person* arr[3] = {&TestStudentOne, &Anton, &Grisha};
    std::string arr_pr[3] = {"Студент Саша", "Преподаватель Антон", "Сотрудник Гриша"};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            assert((arr[j]->getName() == arr_pr[j]) && "Префиксы не должны повторяться!");
        }
    }

    std::cout << "Тест 3.2 выполнился без ошибок!" << std::endl;
}

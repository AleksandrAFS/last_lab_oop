#include "src/domain/Building.h"
#include "src/domain/People/Student.h"
#include "src/domain/People/Teacher.h"
#include "src/domain/People/Employee.h"
#include "src/domain/Courses/ExtraCourse.h"
#include "src/domain/Courses/MainCourse.h"
#include "tests/step2.4.h"
#include <cassert>
#include <iostream>

void step_2_4() {
    Student Oliver("Оливер", 20, "261-352", 2);
    Student James("Джеймс", 20, "261-353", 2);
    Teacher Harry("Гарри", 50, "ФИТ", "Программирование");
    Teacher Arthur("Артур", 40, "ФИТ", "Основы анализа данных");
    Building Housing1("Первый", "Большая Семеновская", 2);
    Building Housing2("Второй", "Красноказарменная", 50);
    Employee George("Джордж", 40, "Администратор", &Housing1);
    MainCourse Programming(1, "Программирование", 100, 20, 2, "экзамен");
    ExtraCourse FundamentalsDataAnalysis(2, "Основы анализа данных", 100, 20, "СДО", 10);

    Programming.assignTeacher(Harry);
    FundamentalsDataAnalysis.assignTeacher(Arthur);
    Harry.enrollStudent(Programming, Oliver);
    Harry.enrollStudent(Programming, James);
    Arthur.enrollStudent(FundamentalsDataAnalysis, Oliver);
    Arthur.enrollStudent(FundamentalsDataAnalysis, James);
    George.admitStudent(Housing1, Oliver);
    George.admitStudent(Housing1, James);
    Housing1.addCourse(Programming);
    Housing1.addCourse(FundamentalsDataAnalysis);
    Oliver.print();
    James.print();
    Harry.print();
    Arthur.print();
    George.print();
    Programming.print();
    FundamentalsDataAnalysis.print();
    Housing1.print();
    Housing2.print();
    
    
    assert((Housing1.addStudent(Oliver) == false) && "Студента нельзя еще раз добавить!");

    Student MrX("X", 20, "X", 2);
    assert(
        (Housing1.addStudent(MrX) == false) && 
        (Housing1.getStudentCount() == 2) &&
        Housing1.hasStudent(Oliver.getId()) && 
        Housing1.hasStudent(James.getId()) && 
        (Housing1.getCourseCount() == 2) && 
        Housing1.hasCourse(Programming.getId()) && 
        Housing1.hasCourse(FundamentalsDataAnalysis.getId()) && 
        "Все должно остаться после неудачного добавления при переполнении!"
    );

    assert(
        (Harry.enrollStudent(FundamentalsDataAnalysis, MrX) == false) &&
        (FundamentalsDataAnalysis.getStudentCount() == 2) &&
        FundamentalsDataAnalysis.hasStudent(Oliver.getId()) &&
        FundamentalsDataAnalysis.hasStudent(James.getId()) &&
        "Список курса должен не меняется при отсутствии прав!"
    );

    assert(
        (George.admitStudent(Housing2, MrX) == false) &&
        (Housing2.getCourseCount() == 0) &&
        (Housing2.getStudentCount() == 0) &&
        "При нехватке прав сотрудника, данные здания не меняются!"
    );

    assert(
        (Housing1.addCourse(Programming) == false) &&
        (Housing1.getCourseCount() == 2) &&
        "Повторный экземпляр записи не появляется при попытке добавления!"
    );
    
    std::cout << "Тест 2.4 выполнился без ошибок!" << std::endl;
}
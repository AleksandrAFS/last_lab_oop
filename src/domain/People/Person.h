#pragma once 
#include <string>

class Person {
    private:
        static int personCount_; 
        int id_;
        std::string name_;
        int age_;
    public:
        Person(std::string name, int age);
        int getId() const;
        virtual std::string getName() const;
        int getAge() const;
        bool setName(const std::string& name);
        bool setAge(int age);
        virtual void print() const;
        virtual ~Person() = default; 
};
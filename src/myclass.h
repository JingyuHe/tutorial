#ifndef GUARD_myclass
#define GUARD_myclass

#include "common.h"

// simplest struct
struct Student
{
    size_t ID;
    string name;
    size_t year;
}; // you have to add ; after definition of struct and class

// class

// class is essential for the so called "object oriented class"
// encapsulation of all the things in objects

class Student_class
{
public:
    size_t ID;
    string name;
    size_t year;

    // the major difference between class and struct is that you can define a lot of functions associated with the class

    // constructor, how do you initialize your class
    // this is just to declare, details in myclass.cpp
    Student_class(size_t &ID, string &name, size_t &year, string &home_address, double &salary);

    // another simple constructor
    Student_class();

    // destructor
    ~Student_class();

    // member function
    double get_salary();

    void update_salary(double new_salary);

    // friend function
    // not part of the class, we claim it can get access to the private object
    friend void double_salary(Student_class &stu);

protected:
    string home_address;

private:
    // private objects cannot be access directly, you have to operate through member functions
    double salary;

    // private functions are useful internally, but you do not want outside user get access to it
    void some_hidden_function();
};

void double_salary_nonfriend(Student_class &stu);

// define operator for your class
// how to print
// note that operators are not member function of the class
// they should be defined outside the class
// a lof of operators you can redefine, see https://en.cppreference.com/w/cpp/language/operators

std::ostream &operator<<(std::ostream &os, Student_class &stu);

// you can even define + operator
Student_class operator+(Student_class const &lhs, Student_class const &rhs);











// inherit
class Alumni : public Student_class
{
public:
    size_t year_graduation;

    // the constructor can be based on the constructor it inherits from
    Alumni(size_t &ID, string &name, size_t &year, string &home_address, double &salary, size_t &year_graduation) : Student_class(ID, name, year, home_address, salary)
    {
        this->year_graduation = year_graduation;
    }
};

// get access to    public          protected           private
// same class       yes             yes                 yes
// inherit class    yes             yes                 no
// outside          yes             no                  no

#endif
#include "myclass.h"

// note that this constructor belongs to Student_class type, you have declare it
Student_class::Student_class(size_t &ID, string &name, size_t &year, string &home_address, double &salary)
{
    // initialize object with the input
    this->ID = ID;
    this->name = name;
    this->year = year;
    this->home_address = home_address;
    this->salary = salary;
}
// "this" is a pointer to the current class
// "this->" means getting access to the object in the current class object
// equivalent to (*this).ID

Student_class::Student_class()
{
    // empty initialization
    this->ID = 0;
    this->name = "";
    this->year = 0;
    this->home_address = "";
    this->salary = 0.0;
}

// destructor
Student_class::~Student_class()
{
    // Deallocate the memory that was previously reserved
    //  for this string.
    // delete &ID;
    // delete &name;
    // delete &year;
    // delete &salary;
}

// print
std::ostream &operator<<(std::ostream &os, Student_class &stu)
{
    return os << "ID " << stu.ID << ", name " << stu.name << ", year " << stu.year << ", salary" << stu.get_salary() << endl;
}

// add
Student_class operator+(Student_class const &lhs, Student_class const &rhs)
{
    Student_class output;
    output.ID = lhs.ID * rhs.ID;
    output.year = lhs.year + rhs.year;
    output.name = "two people";
    return output;
}

double Student_class::get_salary()
{
    return this->salary;
}

void Student_class::update_salary(double new_salary)
{
    this->salary = new_salary;

    this->some_hidden_function();

    return;
}


// private function
void Student_class::some_hidden_function()
{
    cout << "surprise!" << endl;
    return;
}

// this is a friend function
// it's not part of the class, thus no Student_class::double salary
void double_salary(Student_class &stu)
{
    stu.salary = stu.salary * 2.0;

    return;
}

void double_salary_nonfriend(Student_class &stu)
{
    stu.update_salary(stu.get_salary() * 2.0);
    return;
}

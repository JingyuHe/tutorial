// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include "common.h"
#include "myclass.h"

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void demo_class()
{
    // create a std::vector of students struct
    std::vector<Student> stu(10);
    stu[0].ID = 1;
    stu[0].name = "Yuanzhi";
    stu[0].year = 2022;

    stu[1].ID = 2;
    stu[1].name = "Qianshu";
    stu[1].year = 2022;

    // class

    string address = "ta wai";
    double salary = 15000;
    Student_class stu1(stu[0].ID, stu[0].name, stu[0].year, address, salary);
    Student_class stu2(stu[1].ID, stu[1].name, stu[1].year, address, salary);

    stu1.update_salary(17000);

    cout << stu1.get_salary() << endl;

    // stu1.double_salary() // // wrong

    double_salary(stu1);
    cout << stu1.get_salary() << endl;

    cout << "print " << endl;
    cout << stu1 << endl;

    Student_class stu3 = stu1 + stu2;
    cout << "sum of students" << endl;

    cout << stu3 << endl;

    size_t year_graduation = 2026;
    Alumni stu4(stu[0].ID, stu[0].name, stu[0].year, address, salary, year_graduation);

    cout << stu4 << endl;

    return;
}
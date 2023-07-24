// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include "RcppArmadillo.h"
#include <iostream>
#include <random>
#include "test.h"
#include "myclass.h"
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void test(size_t seed, NumericVector nn1, arma::vec nn2, std::vector<double> nn3)
{
    cout << nn1 << endl;
    cout << nn2 << endl;
    cout << nn3.size() << endl;

    // for loop
    arma::vec m1(5);
    double sum = 0.0;

    for (size_t i = 0; i < m1.n_elem; i++)
    {
        sum += m1(i);
    }

    // while loop
    size_t ind = 0;
    sum = 0;
    while (ind < m1.n_elem)
    {
        sum += m1(ind);
        ind = ind + 1;
    }

    double n1;

    size_t n2 = 5;
    size_t n3 = 2;

    n1 = 5.0 / 2.0;

    n1 = (double)5 / (double)2;
    n1 = (double)n2 / (double)n3;

    bool n4 = true;
    bool n5 = false;

    n4 = (bool)0;
    n5 = (bool)100;

    std::vector<size_t> vec1(n2);
    std::vector<double> vec2(n2);
    std::vector<std::vector<double>> mat1(n2);
    for (size_t i = 0; i < n2; i++)
    {
        // keep original values
        mat1[i].resize(n3);
    }

    // return length of vector
    vec1.size();

    arma::vec vec3(n2);

    // generate random numbers
    std::random_device rd;
    std::mt19937 mt(rd());

    // std::mt19937 mt(seed);
    std::uniform_real_distribution<double> dist(1.0, 10.0); // generate 10 samples from uniform

    std::normal_distribution<double> normal(5.0, 2.0);

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << normal(mt) << "\n";
    }
    std::cout << endl;

    // pointer and address
    size_t a1 = 100;

    cout << a1 << " " << &a1 << endl;

    // create a pointer
    size_t *p1 = &a1;

    cout << p1 << " " << *p1 << endl;

    std::vector<size_t> vec11(10);
    for (size_t i = 0; i < 10; i++)
    {
        vec11[i] = i;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << vec11[i] << endl;
    }

    cout << "address of a vector " << &vec11 << endl;

    std::vector<size_t> *p2 = &vec11;

    for (size_t i = 0; i < 10; i++)
    {
        cout << (*p2)[i] << endl;
    }

    // cout << "value of the pointer " << *p2 << endl;

    // allocate space for a pointers
    arma::vec *p3;

    cout << "empty pointer " << p3 << endl;

    p3 = new arma::vec(10);

    cout << "pointer " << p3 << endl;

    (*p3)(0) = 2;

    cout << (*p3) << endl;

    // avoid wild pointer!

    // pass by reference / pass by value

    size_t temp1 = 10;

    cout << "out function temp1 " << temp1 << endl;
    pass_by_reference(temp1);
    cout << "out function, after " << temp1 << endl;



    // NumericVector
    NumericVector nvec1 = wrap(nn3);
    NumericMatrix nmat1;



    return;
}

void pass_by_value(size_t temp1)
{
    cout << "in function " << temp1 << endl;
    temp1 = temp1 + 1;
    cout << "in function, after calculation " << temp1 << endl;
    return;
}

void pass_by_reference(const size_t &temp1)
{
    cout << "in function " << temp1 << endl;
    // temp1 = temp1 + 1;
    cout << "in function, after calculation " << temp1 << endl;
    return;
}
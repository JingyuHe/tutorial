#ifndef GUARD_hello_world
#define GUARD_hello_world

using namespace arma;
using namespace std;
using namespace Rcpp;

void pass_by_value(size_t temp1);
void pass_by_reference(const size_t &temp1);

#endif
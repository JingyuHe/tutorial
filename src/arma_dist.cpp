#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::mat arma_dist(const arma::mat &X)
{
    // this function calculates distance between matrix rows

    size_t n = X.n_rows;
    mat D(n, n, fill::zeros); // Allocate a matrix of dimension n x n
    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = 0; k < i; k++)
        {
            D(i, k) = sqrt(sum(pow(X.row(i) - X.row(k), 2)));
            D(k, i) = D(i, k);
        }
    }
    return D;
}
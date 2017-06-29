#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector fun(Rcpp::Function f, Rcpp::NumericVector x) {
    Rcpp::NumericVector res = f(x);
    return res;
}

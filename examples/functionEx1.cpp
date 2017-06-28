
#include <Rcpp.h>

// [[Rcpp::export]]
SEXP fun(Rcpp::Function f, SEXP x) {
    return ::f(x);
}


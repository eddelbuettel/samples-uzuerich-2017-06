
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector fun() {
    Rcpp::Function rt("rt");
    return rt(3, 4);
}

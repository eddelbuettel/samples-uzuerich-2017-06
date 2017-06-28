#include <Rcpp.h>

// [[Rcpp::export]]
int intVec1a(Rcpp::IntegerVector vec) {
    int prod = 1;
    for (int i=0; i<vec.size(); i++) {
        prod *= vec[i];
    }
    return prod;
}


// [[Rcpp::export]]
int intVec1b(std::vector<int> vec) {
    int prod = 1;
    for (unsigned int i=0; i<vec.size(); i++) {
        prod *= vec[i];
    }
    return prod;
}

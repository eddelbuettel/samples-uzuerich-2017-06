#include <Rcpp.h>

// [[Rcpp::export]]
int intVec2a(Rcpp::IntegerVector vec) {
    int prod = std::accumulate(vec.begin(), vec.end(),
			       1, std::multiplies<int>());
    return prod;
}


// [[Rcpp::export]]
int intVec2b(std::vector<int> vec) {
    int prod = std::accumulate(vec.begin(), vec.end(),
			       1, std::multiplies<int>());
    return prod;
}

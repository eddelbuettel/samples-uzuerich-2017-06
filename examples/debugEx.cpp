
#include <Rcpp.h>

// [[Rcpp::export]]
bool divbyzero(int x) {
    int res = x / 0L;
    Rcpp::Rcout << "res is now " << res << std::endl;
    return true;
}


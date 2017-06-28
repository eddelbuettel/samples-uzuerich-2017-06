
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericMatrix takeRoot(Rcpp::NumericMatrix mm) {
    Rcpp::NumericMatrix m = Rcpp::clone<Rcpp::NumericMatrix>(mm);
    std::transform(m.begin(), m.end(), m.begin(), ::sqrt);
    return m;
}

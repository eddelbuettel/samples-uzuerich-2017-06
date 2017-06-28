// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadillo.h>
         
// [[Rcpp::export]]
Rcpp::List armafun(arma::mat m1) {
    arma::mat m2 = m1 + m1;
    arma::mat m3 = m1 * 2;
    return Rcpp::List::create(m1, m2);
}

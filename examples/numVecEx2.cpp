
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::DataFrame numVecEx2(Rcpp::NumericVector xs) {
    Rcpp::NumericVector x1(xs);
    Rcpp::NumericVector x2(Rcpp::clone(xs));
    x1[0] = 22;
    x2[1] = 44;
    return(Rcpp::DataFrame::create(Named("orig", xs),
                                   Named("x1", x1),
                                   Named("x2", x2)));
}

// [[Rcpp::export]]
Rcpp::DataFrame intVecEx2(Rcpp::IntegerVector xs) {
    Rcpp::IntegerVector x1(xs);
    Rcpp::IntegerVector x2(Rcpp::clone(xs));
    x1[0] = 22;
    x2[1] = 44;
    return(Rcpp::DataFrame::create(Named("orig", xs),
                                   Named("x1", x1),
                                   Named("x2", x2)));
}



#include <Rcpp.h>
#include <numeric>   	// for std::partial_sum
using namespace Rcpp;
// [[Rcpp::export]]
NumericVector cumsum1(NumericVector x) {
    double acc = 0;     // init an accumulator var
    NumericVector res(x.size());  // init result vector
    for (int i = 0; i < x.size(); i++){
         acc += x[i];
         res[i] = acc;
    }
    return res;
}


// [[Rcpp::export]]
NumericVector cumsum2(NumericVector x) {
    // initialize the result vector
    NumericVector res(x.size());
    std::partial_sum(x.begin(), x.end(), 
                     res.begin());
    return res;
}



// [[Rcpp::export]]
NumericVector cumsum3(NumericVector x) {
    return cumsum(x);  // compute + return result vector
}

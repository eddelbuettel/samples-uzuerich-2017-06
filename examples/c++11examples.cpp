
#include <Rcpp.h>

// Enable C++11 via this plugin 
// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::export]]
int useAuto() {
    auto val = 42;		// val will be of type int
    return val;
}



#include <Rcpp.h>

// [[Rcpp::plugins("cpp11")]]
         
// [[Rcpp::export]]
std::vector<std::string> useInitLists() {
    std::vector<std::string> vec = {"larry", "curly", "moe"};
    return vec;
}




#include <Rcpp.h>

// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::export]]
int simpleProd(std::vector<int> vec) {
    int prod = 1;
    for (int &x : vec) {       // loop over all values of vec
       prod *= x;              // access each elem., comp. product
    }
    return prod;
}



#include <Rcpp.h>

// [[Rcpp::plugins("cpp11")]]

// [[Rcpp::export]]
std::vector<double>
transformEx(const std::vector<double>& x) {
    std::vector<double> y(x.size());
    std::transform(x.begin(), x.end(), y.begin(), 
                   [](double x) { return x*x; } );
    return y;
}



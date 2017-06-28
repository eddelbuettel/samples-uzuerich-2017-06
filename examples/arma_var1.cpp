#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat rcppSim(const arma::mat& coeff, const arma::mat& errors) {
    int m = errors.n_rows;
    int n = errors.n_cols;
    arma::mat simdata(m,n);
    simdata.row(0) = arma::zeros<arma::mat>(1,n);
    for (int row=1; row<m; row++) {
        simdata.row(row) = simdata.row(row-1) * coeff + errors.row(row);
    }
    return simdata;
}

/*** R
a <- matrix(c(0.5,0.1,0.1,0.5),2,2)
e <- matrix(rnorm(10000),ncol=2)
head(rcppSim(a, e))
*/

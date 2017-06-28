#include <Rcpp.h>

// [[Rcpp::export]]
double long_computation(int nb) {
    double sum = 0;
    for (int i = 0; i < nb; ++i) {
        for (int j = 0; j < nb; ++j) {
	    sum += R::dlnorm(i+j, 0.0, 1.0, 0);
	}
    }
    return sum + nb;
}



// [[Rcpp::plugins("openmp")]]

#ifdef _OPENMP
#include <omp.h>
#endif

#include <Rcpp.h>

// [[Rcpp::export]]
double long_computation_omp(int nb, int threads=1) {
#ifdef _OPENMP
    if (threads > 0) omp_set_num_threads( threads );
    REprintf("Number of threads=%i\n", omp_get_max_threads());
#endif
 
    double sum = 0;
#pragma omp parallel for schedule(dynamic)   
    for (int i = 0; i < nb; ++i) {
        double thread_sum = 0;
  	for (int j = 0; j < nb; ++j) {
	    thread_sum += R::dlnorm(i+j, 0.0, 1.0, 0);
	}
        sum += thread_sum;
    }
    return sum + nb;
}



f <- function(n, x=1) for(i in 1:n) x <- 1/(1+x)
g <- function(n, x=1) for(i in 1:n) x <- (1/(1+x))
h <- function(n, x=1) for(i in 1:n) x <- (1+x)^(-1)
j <- function(n, x=1) for(i in 1:n) x <- {1/{1+x}}
k <- function(n, x=1) for(i in 1:n) x <- 1/{1+x}

library(rbenchmark)
N <- 1e5
benchmark(f(N,1),g(N,1),h(N,1),j(N,1),k(N,1))[,1:4]

library(Rcpp)
cppFunction("
    double m(int n, double x=1) {
        for (int i=0; i<n; i++)
             x = 1 / (1+x);
        return x;
    }")


benchmark(f(N,1),g(N,1),h(N,1),j(N,1),k(N,1),m(N,1),order="relative")[,1:4]


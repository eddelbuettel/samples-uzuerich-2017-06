
f <- function(n) {
    if (n < 2) return(n)
    return(f(n-1) + f(n-2))
}

## Using it on first 11 arguments
sapply(0:10, f)


library(rbenchmark)
benchmark(f(10), f(15), f(20))[,1:4]



Rcpp::cppFunction('int g(int n) { 
   if (n < 2) return(n); 
   return(g(n-1) + g(n-2)); }')
## Using it on first 11 arguments
sapply(0:10, g)



library(rbenchmark)
benchmark(f(20), g(20))[,1:4]

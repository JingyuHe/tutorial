R_dist <- function(X) {
    n <- nrow(X)
    D <- matrix(0, n, n) # Pre-allocate the output 
    for (i in 1:n) {
        for (k in 1:i) {
            D[i, k] <- D[k, i] <- sqrt(sum((X[i, ] - X[k, ])^2))
        }
    }       
    return(D)
}


X <- as.matrix(USArrests) # Example dataset

library(rbenchmark)

benchmark(
    arma_dist = arma_dist(X), # Armadillo implementation
    R_dist = R_dist(X), # Naive R implementation
    dist = as.matrix(dist(X)), # Built-in R function (C++) 
    columns = c("test", "replications", "elapsed", "relative"), 
    replications = 5000
)


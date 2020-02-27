# Problem Statement: 
Since matrix-multiplication is associative (but not necessarily commutative), there may be more than one way to compute the product.
Nevertheless, the path we choose greatly affects the number of calculations we make on the way. In this classic problem, we need to 
make a set of decisions that minimizes the effort (well, at least for machines).

Given a chain **<A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>n</sub>>** of **n** matrices, where for **i = 1, 2, ..., n**,
matrix **A<sub>i</sub>** has dimension **p<sub>i - 1</sub> x p<sub>i</sub>**, we need to fully parenthesize the product
**<A<sub>1</sub>A<sub>2</sub>...A<sub>n</sub>>** in a way that minimizes the number of scalar multiplications.

<p align="center">
  <img width="811" height="281" src="https://miro.medium.com/max/1844/1*D_1tbv_wNFJ-rrremAGX4Q.png">
</p>

**Note:** A product of matrices is *fully parenthesized* if it is either a single matrix or the product 
of two fully parenthesized matrix products, surrounded by parentheses.

# CAM5 - Prayatna PR

The task boils down to finding the number of connected components in the given graph. How does one do that is quite simple:
given a graph, you call a series of depth first searches (one from an arbitrary source from each connected component), each of which
marks all the vertices in their respective connected component as **visited**. It guarantees one search per connected component. 
Consequently, the number of depth first trees (in the forest of the same) - each corresponding to a search from a **unique source** in the 
algorithm - is the number of connected components in the graph.

<p align="center">
  <img width="500" height="400" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/85/Pseudoforest.svg/1200px-Pseudoforest.svg.png">
</p>

## Notes for intuition:
> One can also think of the connected components as equivalence classes: two vertices are related if there is an edge connecting the first 
to the second in the graph. What it implies is this: the relation partitions the set of vertices into a class of subsets, each of which 
contains the vertices in a distinct connected component. These subsets are mutually exclusive and exhaustive (their union is the original 
vertex set, and the pairwise intersections are empty). When you start to think of the connected components this way, to aid your intuition,
there is one data structure in the town that makes life a bit easier: **the all powerful disjoint-set data structure** (more on this, later).

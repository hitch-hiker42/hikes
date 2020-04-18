# Vertex Cover

A **vertex cover** (sometimes node cover) of a graph is a set of vertices that includes at least one endpoint of every edge of the graph.
The problem of finding a **minimum vertex cover** is a classical optimization problem in computer science and is a typical example of an 
NP-hard optimization problem that has an approximation algorithm.

Formally, a vertex cover **V'** of an undirected graph **G = (V, E)** is a subset of V such that:

<p align="center">
  <img width="300" height="100" src="https://wikimedia.org/api/rest_v1/media/math/render/svg/52545db3d614057c40cc2461795c64e755f8c539">
</p>

It is a set of vertices **V'** where every edge in **G** has at least one endpoint in the vertex cover **V'**. Such a set is said to cover the edges of **G**. 
The following figure shows two examples of vertex covers, with some vertex cover **V'** marked in red.

<p align="center">
  <img width="320" height="100" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/58/Vertex-cover.svg/200px-Vertex-cover.svg.png">
</p>

A minimum vertex cover is a vertex cover of smallest possible size. The **vertex cover number** is the size of a minimum vertex cover. 
The following figure shows examples of minimum vertex covers in the previous graphs.

<p align="center">
  <img width="320" height="100" src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/Minimum-vertex-cover.svg/200px-Minimum-vertex-cover.svg.png">
</p>

## Examples

1. The size of the minimum vertex cover of any empty graph is **0**.
2. The size of the minimum vertex cover of  a complete graph on **n** - vertices is **n - 1**.
3. The size of the minimum vertex cover of a complete bipartite graph **K<sub>m, n</sub>** is **min(m, n)**.
4. In a graph on **n** - vertices, the vertex set itself is always a vertex cover, hence the **size of the vertex cover** = **O(n)**.
5. The endpoints of a **maximal matching** forms a vertex cover.

## Properties

1. A set of vertices is a vertex cover if and only if its complement is an independent set.

2. Consequently, the number of vertices of a graph is equal to its minimum vertex cover number plus the size of a maximum independent set.

## References

1. [Wikipedia](https://en.wikipedia.org/wiki/Vertex_cover)
2. [Brilliant](https://brilliant.org/wiki/vertex-cover/)
3. [TryAlgo](https://tryalgo.org/en/matching/2016/08/05/konig/)

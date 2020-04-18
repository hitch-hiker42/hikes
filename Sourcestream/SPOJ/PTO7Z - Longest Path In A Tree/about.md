# Longest Path in a Tree

Here is a brief terminology before we continue (credits: wikipedia):

> 1. The **distance, d(u, v)** between two vertices **u** and **v** in a graph is the number of edges in a shortest path connecting them. This is also known as the geodesic distance. Notice that there may be more than one shortest path between two vertices. If there is no path connecting the two vertices, i.e., if they belong to different connected components, then conventionally the distance is defined as infinite.

<p align="center">
  <img width="500" height="200" src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcScvLuYzG2TMZcm4iG6H0tueqOP3Q4TnT37gOWjsBQdLRpKPXUF&usqp=CAU">
</p>

> 2. The **eccentricity, ε** of a vertex **v** is the greatest distance between **v** and any other vertex. It can be thought of as how far a node is from the node most distant from it in the graph.

<p align="center">
  <img width="300" height="200" src="https://wikimedia.org/api/rest_v1/media/math/render/svg/d078af5df2ef5998f87f97e2b269ae3fc8c35825">
</p>

> 3. The **radius, r** of a graph is the minimum eccentricity of any vertex.

<p align="center">
  <img width="400" height="200" src="https://wikimedia.org/api/rest_v1/media/math/render/svg/38af03e1b81b0a52bb946e56905bb831967000d4">
</p>

> 4. The **diameter, d** of a graph is the maximum eccentricity of any vertex in the graph. That is, **d** is the greatest distance between any pair of vertices. To find the diameter of a graph, first find the shortest path between each pair of vertices. The greatest length of any of these paths is the diameter of the graph.

<p align="center">
  <img width="300" height="200" src="https://wikimedia.org/api/rest_v1/media/math/render/svg/f5c63eea6c9f40b4745dece06551878285877933">
</p>

> 5. A **central vertex** in a graph of radius **r** is one whose eccentricity is **r** — that is, a vertex that achieves the radius.

> 6. A **peripheral vertex** in a graph of diameter **d** is one that is distance **d** from some other vertex — that is, a vertex that achieves the diameter.

> 7. The partition of a graph's vertices into subsets by their distances from a given starting vertex is called the **level structure** of the graph.

Onto the point now. We can arbitrarily choose a root of the tree for we need to search through its edges, and it requires picking a source to start from. Without the loss of generality, let us pick the node labeled - **1**. 

Now, we need to agree on a few arguments:

1. The longest path in a **tree** is in fact the diameter of the tree.

2. The diameter is identified (and distinguished) only by its endpoints. Call one **x**, the other **y**.

3. We can only have two scenarios now, either the root is on the diameter or it's not!

4. If it's on the diameter, the node farthest from it, say **w** has to be an endpoint of the diameter **(w = x** or **w = y)** for if it is not, then there exists two nodes **u** and **v** such that **x = u** and **y = v** and neither is equal to **w**. If this is the case, then **d(1, u) > d(1, w)** and **d(1, v) > d(1, w)** which is clearly not the case as **w** is peripheral to (farthest from) **1**.

5. If it's not on the diameter, then let there be a node **z** which is a junction where the root (**= 1**), the node, **u**, the node, **v**, and the node, **w** meets. So, **z** is the lowest common ancestor of **u, w,** and **w**. Now, the distance **d(1, z)** is constant for each path with distances: **d(1, u)**, **d(1, v)**, and **d(1, w)**. So, we are left with **d(z, u), d(z, v)** and **d(z, w)**. Again, it follows from argument **4** that **w** must be on an endpoint of the diameter or we will again meet a contradiction given **d(z, w)** is maximal (**w** is peripheral to **z**).

**The conclusion is as follows:** we can call a depth first search with vertex - **1** as the source to find the vertex farthest from it: let it be **w** as you did above. It will be one end of the diameter as just proved. The other end is found by calling another depth first search, now with **w** as the source to find the vertex farthest from it. It will naturally be the other end of the diameter.

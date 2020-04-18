# List the branches in a tree

We are given a rooted tree with **N** nodes labeled **1** through **N**. The root of the tree is (without the loss of generality) at the node labeled - **1**. Let us define a **branch** to be a path that starts at the root and end at a leaf (there will be as many branches as there are leaves in the tree).

<p align="center">
  <img width="811" height="281" src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQa4ZrcxWlz3aKaoSIMV0a0dGcUYyd0yjmmzy1Fn6gwOg4EZsZq&usqp=CAU">
</p>

The procedure lists all those branches in the dfs order traversal of the tree (the branch whose leaf is discovered first will be printed first,
followed by the one whose leaf is discovered next, and so on.)

**Example:** In the tree on the left in the picture, the branches are: **{1, 2}**, **{1, 3, 4}**, **{1, 3, 5}**; and in the one that's one the right,
they are: **{1, 2, 3}**, **{1, 5, 6}**, **{1, 5, 7}**, **{1, 8, 4}**.

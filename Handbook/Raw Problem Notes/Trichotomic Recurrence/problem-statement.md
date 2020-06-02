# Trichotomic Recurrence

## Problem Statement:
> They say that good things come in three, like the *triangles*, or *the law of trichotomy*, or *the three musketeers*. This problem is no different, so we'll be dealing with *three* today.

We are given a sequence of **N** non-negative integers, **A = <A<sub>0</sub>, A<sub>1</sub>, ..., A<sub>N-1</sub>>**. Next, we'll process 
**Q** queries of the following type(s) over it:

- **1 X Y** `: Output the sum of the elements in the range [X, Y], 0 <= X <= Y < N`

- **2 X Y D<sub>1</sub> D<sub>2</sub> D<sub>3</sub>** `: [X, Y] divides the range(hence the sequence) [0, N) into three parts: [0, X), [X, Y], (Y, N)`

  - For each element **A<sub>idx</sub>** such that **idx** belongs to the left range (**0 <= idx < X**), update **A<sub>i</sub>** as: **A<sub>idx</sub> = A<sub>idx</sub> + idx<sup>2</sup> * D<sub>1</sub>**

  - For each element **A<sub>idx</sub>** such that **idx** belongs to the middle range (**X <= idx <= Y**), update **A<sub>i</sub>** as: **A<sub>idx</sub> = A<sub>idx</sub> + idx * D<sub>2</sub>**
  
  - For each element **A<sub>idx</sub>** such that **idx** belongs to the right range (**Y < idx < N**), update **A<sub>i</sub>** as: **A<sub>idx</sub> = A<sub>idx</sub> + D<sub>3</sub>**
  
 **Note:** Since the values can be quite large, all output must be **modulo 10<sup>9</sup>+7**.
  
## Constraints:
1 <= **N** <= 10<sup>6</sup>

1 <= **A<sub>i</sub>** <= 10 <sup>5</sup>

## Input: 
The input consists of **Q + 2** lines in total.

The first line will contain two positive integers, **N**, the number of elements in the sequence and **Q**, the number of queries

The next line will contain **N** space-separtated non-negative integers **A<sub>0</sub>, A<sub>1</sub>, ..., A<sub>N-1</sub>**, the elements of the sequence

The next **Q** lines contains queries, each of which can be of one of the two types (the meaning of the symbols is derived from the problem statement above):

Type 1: **1 X Y**

Type 2: **2 X Y D<sub>1</sub> D<sub>2</sub> D<sub>3</sub>**

## Output:
For each query of the first type, output one non-negative integer as explained above.

## Sample:
```cpp
Input:
6 3
1 3 2 4 5 6
1 3 5
2 3 4 1 2 3
1 2 5

Output:
11
35
```

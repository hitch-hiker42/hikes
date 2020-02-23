# Problem Statement: 
An automobile factory has two assembly lines, each with **n** stations.
A station is denoted by **S<sub>i</sub>[j]** where **i** denotes the assembly line the station is on and **j** denotes the index or the number of the station.
The time taken per station is denoted by **a<sub>i[j]</sub>**.
Each station is dedicated to do some sort of work in the manufacturing process.
So, a chassis must pass through each of the **n** stations in order before exiting the factory.
The parallel stations of the two assembly lines perform the same task.
After it passes through station **S<sub>i</sub>[j]**, it will continue to station **S<sub>i</sub>[j+1]** unless it decides to transfer to the other line.
Continuing on the same line incurs no extra cost, but transferring from line **i** at station **j** to station **j + 1** on the other line takes time **t<sub>i</sub>[j]**.
Each assembly line takes an entry time **e<sub>i</sub>** and exit time **x<sub>i</sub>**.
Find the minimum time through the factory from start to exit and print the corresponding schedule of stations to be chosen.

<p align="center">
  <img width="811" height="281" src="http://www.euroinformatica.ro/documentation/programming/!!!Algorithms_CORMEN!!!/images/fig347_01_0.jpg">
</p>

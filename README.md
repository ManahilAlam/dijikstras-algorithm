# dijikstras-algorithm
Shopping complexes often consist of various shops connected by pathways. Finding the shortest path between two shops can be crucial for optimizing routes and enhancing the shopping experience. This project implements Dijkstra's algorithm to calculate the shortest path between any two shops in a shopping complex.

1. Introduction
Shopping complexes often consist of various shops connected by pathways. Finding the shortest path between two shops can be crucial for optimizing routes and enhancing the shopping experience. This project implements Dijkstra's algorithm to calculate the shortest path between any two shops in a shopping complex.
2. Problem Statement
Given a shopping complex represented as a graph, where nodes represent shops and edges represent pathways with associated travel times, find the shortest path from a specified source shop to a destination shop.
3. Objective
To develop a C++ program that uses Dijkstra's algorithm to determine the shortest distance between any two shops in a shopping complex.
4. Methodology
The project utilizes Dijkstra's algorithm, which is well-suited for finding the shortest path in a weighted graph with non-negative weights. The adjacency list representation of the graph is employed for efficient storage and retrieval of edge data.
5. Implementation
Data Structures Uses
Adjacency List: For storing the graph.
Distance Vector: To keep track of the shortest distance from the source to each node.
Set: To manage and fetch the next node with the shortest known distance efficiently.
Key Functions and Algorithms:
Graph Representation: The graph is represented using an adjacency list where each node points to a list of pairs representing connected nodes and edge weights.
Dijkstra's Algorithm:
Initialize distances from the source to all nodes as infinite (INT_MAX), except for the source node which is set to 0.
Use a set to pick the node with the smallest known distance.
Update the distances to neighboring nodes if a shorter path is found.
Repeat until all nodes are processed.

User Input and Validation:
Take input for the source and destination shops.
Validate if the input shop numbers are within the valid range.

6. Results
The program successfully calculates the shortest path between any two shops in the shopping complex using Dijkstra's algorithm. The adjacency list allows efficient storage and traversal of the graph. The use of a set ensures the efficient retrieval of the next node with the smallest known distance.
7. Conclusion
The project demonstrates the effectiveness of Dijkstra's algorithm in finding the shortest path in a graph with non-negative weights. By applying this algorithm, the shortest distance between any two shops in a shopping complex can be efficiently determined.



# sourcecode-link
https://mega.nz/folder/nQIiGCAY#2SomJr0mwxLc7hbcw9jG6g

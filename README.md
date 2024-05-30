# dijikstras-algorithm
Shopping complexes often consist of various shops connected by pathways. Finding the shortest path between two shops can be crucial for optimizing routes and enhancing the shopping experience. This project implements Dijkstra's algorithm to calculate the shortest path between any two shops in a shopping complex.
ChicRoute is a C++ application that uses Dijkstra's algorithm to calculate and visualize the shortest path between shops in a mall. The project features a graphical user interface (GUI) built with the Simple and Fast Multimedia Library (SFML), allowing users to select source and destination shops interactively. The application then dynamically computes and displays the shortest path along with the total distance. 

The primary objective of ChicRoute is to provide a practical solution for navigating mall layouts while also serving as an educational tool for demonstrating Dijkstra's algorithm. By combining algorithmic logic with real-world scenarios, ChicRoute offers users a comprehensive understanding of shortest path algorithms through interactive visualization.

ChicRoute's implementation involves using a standard C++ compiler, the SFML library for graphics and user input, and the Windows operating system. Visual Studio is recommended for development, but optional. The SFML library modules utilized include graphics, window, and system for rendering visuals, managing the application window, handling events, and supporting utility functions.

Dijkstra's algorithm is implemented in ChicRoute to find the shortest path from a source shop to all other shops in a weighted graph. The graph is represented with an adjacency list, and a priority queue (simulated with std::set) efficiently retrieves the node with the smallest distance during computation. Vectors track the shortest distances and their respective parents to reconstruct the path.

The graphical user interface allows users to interactively select source and destination shops, triggering the calculation and visualization of the shortest path. Shops are represented as sprites, and the shortest path is highlighted using colored lines. The total distance of the shortest path is displayed on the screen.

In conclusion, ChicRoute successfully integrates algorithmic principles with graphical visualization to solve the shortest path problem in a mall setting. It provides an immersive and educational experience, demonstrating the practical utility of Dijkstra's algorithm in route planning scenarios.



# sourcecode-link
https://mega.nz/folder/SZRHFBpI#qiIrugYpXPW9EYBDrCbdpQ

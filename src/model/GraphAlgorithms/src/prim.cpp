#include <iostream>
#include <vector>
#include <limits>

// Structure to represent an edge in the graph
struct Edge {
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

std::vector<Edge> primAlgorithm(const std::vector<std::vector<size_t>>& graph) {
    size_t numVertices = graph.size();

    // Initialize data structures
    std::vector<size_t> cheapestCost(numVertices, std::numeric_limits<size_t>::max());
    std::vector<Edge> cheapestEdge(numVertices, Edge(-1, -1, std::numeric_limits<size_t>::max()));
    std::vector<bool> inTree(numVertices, false);

    // Initialize the starting vertex
    size_t startVertex = 0;  // You can choose any starting vertex arbitrarily
    cheapestCost[startVertex] = 0;

    // Main loop of Prim's algorithm
    for (size_t i = 0; i < numVertices; ++i) {
        // Find the vertex with the minimum cost that is not yet in the tree
        size_t currentVertex = numVertices;  // Initialize to an invalid value
        for (size_t v = 0; v < numVertices; ++v) {
            if (!inTree[v] && (currentVertex == numVertices || cheapestCost[v] < cheapestCost[currentVertex])) {
                currentVertex = v;
            }
        }

        // Add the current vertex to the tree
        inTree[currentVertex] = true;

        // Update cost and edge information for adjacent vertices
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph[currentVertex][neighbor] > 0 && !inTree[neighbor] && graph[currentVertex][neighbor] < cheapestCost[neighbor]) {
                cheapestCost[neighbor] = graph[currentVertex][neighbor];
                cheapestEdge[neighbor] = Edge(currentVertex, neighbor, graph[currentVertex][neighbor]);
            }
        }
    }

    // Return the resulting minimum spanning tree
    return cheapestEdge;
}

int main() {
    // Example graph represented as an adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Run Prim's algorithm and get the minimum spanning tree
    std::vector<Edge> minimumSpanningTree = primAlgorithm(graph);

    // Display the minimum spanning tree
    std::cout << "Minimum Spanning Tree Edges:" << std::endl;
    for (const Edge& edge : minimumSpanningTree) {
        std::cout << "Edge: " << edge.from << " - " << edge.to << "   Weight: " << edge.weight << std::endl;
    }

    return 0;
}
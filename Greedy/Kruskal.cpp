#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}

    // Overloading the comparison operator for sorting the edges
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Find function for the disjoint set
int find(std::vector<int>& parent, int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return find(parent, parent[vertex]);
}

// Union function for the disjoint set
void unionSet(std::vector<int>& parent, int x, int y) {
    int xSet = find(parent, x);
    int ySet = find(parent, y);
    parent[xSet] = ySet;
}

// Function to perform Kruskal's algorithm
std::vector<Edge> kruskal(std::vector<Edge>& edges, int numVertices) {
    // Sort the edges in ascending order of their weights
    std::sort(edges.begin(), edges.end());

    std::vector<Edge> mst; // Minimum Spanning Tree
    std::vector<int> parent(numVertices, -1); // Parent array for disjoint set

    int edgeCount = 0; // Counter to keep track of the number of edges in the MST

    for (const Edge& edge : edges) {
        int srcSet = find(parent, edge.src);
        int destSet = find(parent, edge.dest);

        // If including the edge doesn't form a cycle, add it to the MST
        if (srcSet != destSet) {
            mst.push_back(edge);
            unionSet(parent, srcSet, destSet);

            // Increment the edge count
            ++edgeCount;

            // Stop when we have included (numVertices - 1) edges in the MST
            if (edgeCount == numVertices - 1)
                break;
        }
    }

    return mst;
}

int main() {
    int numVertices = 6; // Number of vertices

    // Create the graph as a vector of edges
    std::vector<Edge> edges;
    edges.emplace_back(0, 1, 2);
    edges.emplace_back(0, 2, 4);
    edges.emplace_back(1, 2, 1);
    edges.emplace_back(1, 3, 7);
    edges.emplace_back(2, 4, 3);
    edges.emplace_back(3, 4, 1);
    edges.emplace_back(3, 5, 5);
    edges.emplace_back(4, 5, 2);

    // Compute the Minimum Spanning Tree (MST) using Kruskal's algorithm
    std::vector<Edge> mst = kruskal(edges, numVertices);

    // Print the edges of the MST
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        std::cout << edge.src << " -- " << edge.dest << "  Weight: " << edge.weight << "\n";
    }

    return 0;
}

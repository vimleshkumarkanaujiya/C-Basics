#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Structure to represent a vertex in the graph
struct Vertex {
    int id;
    int key;

    Vertex(int id, int key) : id(id), key(key) {}

    // Overloading the comparison operator for the priority queue
    bool operator>(const Vertex& other) const {
        return key > other.key;
    }
};

// Function to perform Prim's algorithm
std::vector<int> prim(const std::vector<std::vector<std::pair<int, int>>>& graph, int source) {
    int n = graph.size(); // Number of vertices

    // Create a vector to store the parent of each vertex in the MST
    std::vector<int> parent(n, -1);

    // Create a vector to store the key (minimum weight) of each vertex
    std::vector<int> key(n, INF);

    // Create a priority queue to store the vertices
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;

    // Set the key of the source vertex to 0 and add it to the priority queue
    key[source] = 0;
    pq.emplace(source, 0);

    while (!pq.empty()) {
        // Extract the vertex with the minimum key from the priority queue
        Vertex current = pq.top();
        pq.pop();

        int u = current.id;
        int currentKey = current.key;

        // If the extracted vertex has already been included in the MST, skip it
        if (currentKey > key[u]) {
            continue;
        }

        // Iterate through the neighbors of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If the neighbor is not yet included in the MST and the weight is smaller than its key,
            // update its key and parent, and add it to the priority queue
            if (weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.emplace(v, weight);
            }
        }
    }

    return parent;
}

int main() {
    int n = 6; // Number of vertices

    // Create the graph as an adjacency list
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Add edges to the graph (vertex, weight)
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(2, 4);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 7);
    graph[2].emplace_back(4, 3);
    graph[3].emplace_back(4, 1);
    graph[3].emplace_back(5, 5);
    graph[4].emplace_back(5, 2);

    int source = 0; // Source vertex for Prim's algorithm

    std::vector<int> parent = prim(graph, source);

    // Print the edges of the Minimum Spanning Tree (MST)
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < n; ++i) {
        std::cout << parent[i] << " -- " << i << "\n";
    }

    return 0;
}

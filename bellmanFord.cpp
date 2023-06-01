#include <iostream>
#include <vector>
#include <limits>

struct Edge {
    int source;
    int destination;
    int weight;
};

class Graph {
private:
    int numVertices;
    std::vector<Edge> edges;

public:
    Graph(int vertices) {
        numVertices = vertices;
    }

    void addEdge(int src, int dest, int weight) {
        Edge newEdge;
        newEdge.source = src;
        newEdge.destination = dest;
        newEdge.weight = weight;
        edges.push_back(newEdge);
    }

    void bellmanFord(int startVertex) {
        std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
        distance[startVertex] = 0;

        // Relax edges repeatedly V-1 times
        for (int i = 0; i < numVertices - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;
                if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                std::cout << "Negative weight cycle detected!" << std::endl;
                return;
            }
        }

        // Print shortest path distances
        std::cout << "Vertex\tDistance from Source" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << "\t" << distance[i] << std::endl;
        }
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    int startVertex = 0;
    graph.bellmanFord(startVertex);

    return 0;
}

#include <iostream>
#include <list>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;

        // Initialize the adjacency list with an empty list for each vertex
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            // Add an edge from source to destination
            adjList[src].push_back(dest);
        }
    }

    void printAdjList() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Adjacency list of vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numVertices = 4;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);

    graph.printAdjList();

    return 0;
}

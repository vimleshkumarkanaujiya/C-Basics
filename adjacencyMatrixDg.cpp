#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;

        // Initialize the adjacency matrix with zeros
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            // Add an edge from source to destination
            adjMatrix[src][dest] = 1;
        }
    }

    void printAdjMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
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

    graph.printAdjMatrix();

    return 0;
}

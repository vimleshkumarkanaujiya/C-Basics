#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;

        // Initialize the adjacency list
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            // Add an edge from source to destination
            adjList[src].push_back(dest);
        }
    }

    void DFS(int startVertex, std::vector<bool>& visited) {
        // Mark the current vertex as visited and print it
        visited[startVertex] = true;
        std::cout << startVertex << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[startVertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void DFSTraversal() {
        // Create a boolean array to keep track of visited vertices
        std::vector<bool> visited(numVertices, false);

        // Call the DFS function for each unvisited vertex
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }
};

int main() {
    int numVertices = 7;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    std::cout << "DFS Traversal: ";
    graph.DFSTraversal();

    return 0;
}

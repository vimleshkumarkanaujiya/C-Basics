#include <iostream>
#include <queue>
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

    void BFS(int startVertex) {
        // Create a boolean array to keep track of visited vertices
        std::vector<bool> visited(numVertices, false);

        // Create a queue for BFS traversal
        std::queue<int> queue;

        // Mark the current vertex as visited and enqueue it
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Dequeue a vertex from the queue and print it
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex is not visited, mark it as visited and enqueue it
            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
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

    std::cout << "BFS Traversal: ";
    graph.BFS(0);

    return 0;
}

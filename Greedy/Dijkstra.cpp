#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Structure to represent a vertex in the graph
struct Vertex {
    int id;
    int distance;

    Vertex(int id, int distance) : id(id), distance(distance) {}

    // Overloading the comparison operator for the priority queue
    bool operator>(const Vertex& other) const {
        return distance > other.distance;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int source) {
    int n = graph.size(); // Number of vertices

    // Create a vector to store the distances from the source vertex
    std::vector<int> distance(n, INF);

    // Create a priority queue to store the vertices
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;

    // Set the distance of the source vertex to 0 and add it to the priority queue
    distance[source] = 0;
    pq.emplace(source, 0);

    while (!pq.empty()) {
        // Extract the vertex with the minimum distance from the priority queue
        Vertex current = pq.top();
        pq.pop();

        int u = current.id;
        int dist = current.distance;

        // If the extracted vertex has already been processed, skip it
        if (dist > distance[u]) {
            continue;
        }

        // Iterate through the neighbors of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Calculate the distance to the neighbor through the current vertex
            int newDist = dist + weight;

            // If the new distance is shorter, update the distance and add the neighbor to the priority queue
            if (newDist < distance[v]) {
                distance[v] = newDist;
                pq.emplace(v, newDist);
            }
        }
    }

    // Print the distances from the source vertex to all other vertices
    std::cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF) {
            std::cout << "Vertex " << i << ": INF\n";
        } else {
            std::cout << "Vertex " << i << ": " << distance[i] << "\n";
        }
    }
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

    int source = 0; // Source vertex for Dijkstra's algorithm

    dijkstra(graph, source);

    return 0;
}

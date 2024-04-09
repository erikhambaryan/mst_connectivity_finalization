#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;





// Structure to represent an edge in the graph
struct Edge {
    string src, dest;
    int weight;
};

class Graph {
    map<string, int> habitatIndices; 
    int V; // Number of vertices
    vector<Edge> edges; // Vector to store edges of the graph
    vector<vector<int>> adjList; 

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(const string& src, const string& dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);

        // Adding edge to adjacency list
        adjList[habitatIndices[src]].push_back(habitatIndices[dest]);
        adjList[habitatIndices[dest]].push_back(habitatIndices[src]);
    }

    // Function to find the parent of a subset
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    
    void KruskalMST() {
        vector<Edge> result; // Stores the resultant MST
        int e = 0; 
        int i = 0; 

        // Sort all edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1); // Array to store parent of a node to detect cycles

        // Number of edges to be taken is equal to V-1
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = find(parent, habitatIndices[next_edge.src]);
            int y = find(parent, habitatIndices[next_edge.dest]);

            // If including this edge does not cause cycle, include it in result
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
                ++e;
            }
        }

        
        cout << "Edges of Minimum Spanning Tree:" << endl;
        for (i = 0; i < result.size(); ++i)
            cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }

    // Depth First Search (DFS) to find all paths
    void dfs(int current, int finish, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths, int& minPathLength) {
        visited[current] = true;
        path.push_back(current);

        if (current == finish) { // If we reach the finish vertex
            if (path.size() < minPathLength) {
                allPaths.clear();
                minPathLength = path.size();
            }
            if (path.size() == minPathLength) {
                allPaths.push_back(path);
            }
        } else {
            for (int v : adjList[current]) {
                if (!visited[v]) {
                    dfs(v, finish, visited, path, allPaths, minPathLength); // Recursive call for next vertex
                }
            }
        }

        path.pop_back();
        visited[current] = false;
    }
    
    // Function to find the shortest path between two vertices using DFS
    vector<int> shortestPathDFS(const string& start, const string& finish) {
        vector<bool> visited(V, false);
        vector<int> path;
        vector<vector<int>> allPaths;
        int minPathLength = INT_MAX;

        dfs(habitatIndices[start], habitatIndices[finish], visited, path, allPaths, minPathLength);

        if (allPaths.empty()) // If no path found
            return vector<int>();

        // Select the shortest path among all paths found
        return allPaths[0];
    }

    // Function to add a habitat to the graph
    void addHabitat(const string& name, bool isEmpty) {
        habitatIndices[name] = V;
        ++V;
        adjList.resize(V);
    }

    // Function to get the index of a habitat by its name
    int getIndex(const string& name) {
        return habitatIndices[name];
    }

    // Function to get the habitat name by its index
    string getHabitatName(int index) {
        for (const auto& entry : habitatIndices) {
            if (entry.second == index) {
                return entry.first;
            }
        }
        return ""; // Return empty string if index not found (should not happen)
    }
};

int main() {

	
    int V, E;
    cout << "Enter the number of habitats: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    // Input habitats and their emptiness
    for (int i = 0; i < V; ++i) {
        string habitat;
        bool isEmpty;
        cout << "Enter habitat name: ";
        cin >> habitat;
        cout << "Is habitat " << habitat << " empty? (1 for yes, 0 for no): ";
        cin >> isEmpty;
        graph.addHabitat(habitat, isEmpty);
    }

    // Input edges
    cout << "\nEnter edges in format (src dest weight):\n";
    for (int i = 0; i < E; ++i) {
        string src, dest;
        int weight;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    
    graph.KruskalMST();

    // Testing DFS
    cout << "\n\nGIVE 2 VERTEXES TO FIND THE SHORTEST (if) POSSIBLE ROUTE\n";
    string s, f;
    cout << "Enter Start point: ";
    cin >> s;
    cout << "\nStart point set: " << s;
    cout << "\n\nEnter Finish point: ";
    cin >> f;
    cout << "Finish point set: " << f;

    // Find the shortest path using DFS
    vector<int> shortestPath = graph.shortestPathDFS(s, f);

    // Print the shortest path
    cout << "Shortest Path from habitat " << s << " to habitat " << f << ": ";
    if (shortestPath.empty()) {
        cout << "No path exists!" << endl;
    } else {
        for (int i = 0; i < shortestPath.size(); ++i) {
            cout << graph.getHabitatName(shortestPath[i]);
            if (i != shortestPath.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}

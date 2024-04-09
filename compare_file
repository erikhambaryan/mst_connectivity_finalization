#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <vector>

//save test : 4/2/2024
using namespace std;


void anim(){

    double seconds = 0.3;
    double input_sec = seconds * 1000000;
    for(int i = 0; i < 10; i++){

        system("clear");
        cout << "________________________           " << endl;
        cout << "|   |    |    |    | |  |          " << endl;
        cout << "|___|____|____|____|_|__|_         " << endl;
        cout << "|                  | |    )        " << endl;
        cout << "`--(o)(o)------------(o)--'        " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING" << endl;
        usleep(input_sec);

        system("clear");
        cout << "      _______________________      " << endl;
        cout << "     |   |    |    |    | |  |     " << endl;
        cout << "     |___|____|____|____|_|__|_    " << endl;
        cout << "     |                  | |    )   " << endl;
        cout << "     `--(o)(o)------------(o)--'   " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING." << endl;
        usleep(input_sec);

        system("clear");
        cout << "           _______________________ " << endl;
        cout << "          |   |    |    |    | |  |" << endl;
        cout << "          |___|____|____|____|_|__|" << endl;
        cout << "          |                  | |   " << endl;
        cout << "          `--(o)(o)------------(o)-" << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING.." << endl;
        usleep(input_sec);

        system("clear");
        cout << "                ___________________" << endl;
        cout << "               |   |    |    |    |" << endl;
        cout << "               |___|____|____|____|" << endl;
        cout << "               |                  |" << endl;
        cout << "               `--(o)(o)-----------" << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING..." << endl;
        usleep(input_sec);

        system("clear");
        cout << "                     ______________" << endl;
        cout << "                    |   |    |    |" << endl;
        cout << "                    |___|____|____|" << endl;
        cout << "                    |              " << endl;
        cout << "                    `--(o)(o)------" << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING" << endl;
        usleep(input_sec);

        system("clear");
        cout << "                           ________" << endl;
        cout << "                          |   |    " << endl;
        cout << "                          |___|____" << endl;
        cout << "                          |        " << endl;
        cout << "                          `--(o)(o)" << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING." << endl;
        usleep(input_sec);

        system("clear");
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING.." << endl;
        usleep(input_sec);

        system("clear");
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "                                   " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING..." << endl;
        usleep(input_sec);

        system("clear");
        cout << "_____                              " << endl;
        cout << "| |  |                             " << endl;
        cout << "|_|__|_                            " << endl;
        cout << "| |    )                           " << endl;
        cout << "--(o)--'                           " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING" << endl;
        usleep(input_sec);

        system("clear");
        cout << "___________                        " << endl;
        cout << " |    | |  |                       " << endl;
        cout << "_|____|_|__|_                      " << endl;
        cout << "      | |    )                     " << endl;
        cout << "--------(o)--'                     " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING." << endl;
        usleep(input_sec);

        system("clear");
        cout << "__________________                 " << endl;
        cout << "   |    |    | |  |                " << endl;
        cout << "___|____|____|_|__|_               " << endl;
        cout << "            | |     )               " << endl;
        cout << "(o)------------(o)--'              " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING.." << endl;
        usleep(input_sec);

        system("clear");
        cout << "________________________           " << endl;
        cout << "|   |    |    |    | |  |          " << endl;
        cout << "|___|____|____|____|_|__|_         " << endl;
        cout << "|                  | |    )        " << endl;
        cout << "`--(o)(o)------------(o)--'        " << endl;
        cout << "-----------------------------------" << endl;
        cout << "LOADING..." << endl;
        usleep(input_sec * 3);



    }

}


void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void printAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex___(" << i << ")";
        for (auto v : adjList[i])
            cout << "->(" << v << ")";
        cout << endl;
    }
}




//_______________________________________________________________________________________________
// Depth First Search (DFS) to find all paths
void dfs(const vector<vector<int>>& adjList, int current, int finish, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths, int& minPathLength) {
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
                dfs(adjList, v, finish, visited, path, allPaths, minPathLength);
            }
        }
    }

    path.pop_back();
    visited[current] = false;
}

// Function to find the shortest path between two vertices using DFS
vector<int> shortestPathDFS(const vector<vector<int>>& adjList, int start, int finish) {
    vector<bool> visited(adjList.size(), false);
    vector<int> path;
    vector<vector<int>> allPaths;
    int minPathLength = INT_MAX;

    dfs(adjList, start, finish, visited, path, allPaths, minPathLength);

    if (allPaths.empty()) // If no path found
        return vector<int>();

    // Select the shortest path among all paths found
    return allPaths[0];
}
//_______________________________________________________________________________________________



int main(int argc) {
    system("clear");

    //animation part with arg (1)
            if(argc == 2){
                cout << "ANIMATION: ON" << endl;
                sleep(2);
                anim();
            }
            else {
                cout << "ANIMATION: OFF" << endl;
                sleep(1);
            }


// FOLDED please open
    //user input
    int v, e;
    cout << "\nEnter the number of vertices:";
    cin >> v;
    cout << "Number of vertices set:" << v;
    cout << "\n\nEnter the number of edges:";
    cin >> e;
    cout << "Number of edges set:" << e;


        //creation of adjecansy list
    vector<vector<int>> adjList(v);



    // Take input for edges
    cout << "\n\nEnter edges in pairs (x.space.y):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        addEdge(adjList, u, v);
    }
    cout << "\nADJ_LIST CREATED AND FILLED:\n";



    // Print adjacency list
    cout << "\nAdjacency List representation of the graph:\n";
    printAdjacencyList(adjList);

// FOLDED please open

    //calculating shortest routs from start to finish if possible
    cout << "\n\nGIVE 2 VERTEXES TO FIND THE SHORTEST (if) POSSIBLE ROUTE\n";

    int s, f;
    cout << "Enter Start poit:";
    cin >> s;
    cout << "Start point set:" << s;
    cout << "\n\nEnter Finish point:";
    cin >> f;
    cout << "Finish point set:" << f;

    // Find the shortest path using DFS
    vector<int> shortestPath = shortestPathDFS(adjList, s, f);

    // Print the shortest path
    cout << "Shortest Path from vertex " << s << " to vertex " << f << ": ";
    if (shortestPath.empty()) {
        cout << "No path exists!" << endl;
    } else {
        for (int i = 0; i < shortestPath.size(); ++i) {
            cout << shortestPath[i];
            if (i != shortestPath.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }


    return 0;
}

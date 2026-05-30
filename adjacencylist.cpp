#include <iostream>
#include <vector>

const int MAX_N = 200005;

// the compiler doesn't actually store MAX_N number of actual zeros - it only records the fact that
// the program needs a global block of memory of that size (which it only initialises gradually as needed)

// What this means is that a block of memory is set aside for those values, but the values
// have not been mapped to the physical RAM

std::vector<int> adj[MAX_N]; // adj[MAX_N] is an ARRAY - not a vector - that holds MAX_N number of vectors
bool visited[MAX_N]; // an array of boolean values (of visited nodes)

void dfs(int current_node) {
    // the bool is set to true for the element with the index of the current node
    visited[current_node] = true; 

    std::cout << "Visited node: " << current_node << '\n';

    for (int neighbour : adj[current_node]) {
        if (!(visited[neighbour])) {
            dfs(neighbour);
        }
    }
    
}

int main() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, e;
    if (!(std::cin >> n >> e)) return 0;

    // n represents the node id (starting from index 1 instead 0)
    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 0; i < e; ++i) {
        int u, v; // the two connected nodes
        std::cin >> u >> v;

        // basically, this 'appends' Node v to the inner vector of Node u
        // this is done as each inner vector contains the number that represents the nodes that they
        // are connected to.

        if (u == v) continue;

        adj[u].push_back(v);
        adj[v].push_back(u); // since it is bidirectional, we add u to the the vector of Node v too
    }

    int network_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            network_count++;
            dfs(i);
        }

        std::cout << "Node " << i << " is connected to: ";
        for (int neighbour : adj[i]) { // This means: for neighbour in adj[i] -> python equivalent
            std::cout << "Node " << neighbour << ", ";
        }
        std::cout << '\n';
    }

    std::cout << network_count << '\n';

    return 0;
}
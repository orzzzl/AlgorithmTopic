// 0-based
// A class that represents an undirected graph
class Graph {
    int V;    // No. of vertices
    list<int> *adj;
    void APUtil(int u, bool visited[], int disc[], int low[], int parent[], set<int> &ap) {
        static int time = 0;
        int children = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;
            if (!visited[v]) {
                children++;
                parent[v] = u;
                APUtil(v, visited, disc, low, parent, ap);
                low[u]  = min(low[u], low[v]);
                if (parent[u] == -1 && children > 1)    ap.insert(u);
                if (parent[u] != -1 && low[v] >= disc[u])    ap.insert(u);
            } else if (v != parent[u]) {
                low[u]  = min(low[u], disc[v]);
            }
        }
    }
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);  // Note: the graph is undirected
    }
    set<int> AP() {
        bool *visited = new bool[V];
        int *disc = new int[V];
        int *low = new int[V];
        int *parent = new int[V];
        set<int> ap; 
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                APUtil(i, visited, disc, low, parent, ap);
        return ap;
    }
};

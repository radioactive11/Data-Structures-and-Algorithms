#include <iostream>
#include <queue>
#include <list>

using namespace std;

#define INF = 0x3f3f3f3f
typedef pair <int, int> pii;


class Graph
{
    private:
    int V; // Number of vertices
    list<pii> *adj;

    public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pii> [V];
}

void Graph::addEdge(int v, int u, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
     priority_queue< pii, vector <pii> , greater<pii> > pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pii>::iterator itr;

        for(itr=adj[u].begin(); itr!=adj[u].end(); itr++)
        {
            int v = (*itr).first;
            int weight = (*itr).second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest Paths: " << endl;
    cout << "Vertex\tDistance From Source" << endl;
     for (int i = 0; i < V; ++i)
        cout << i << "\t" << dist[i] << endl;
}

int main()
{
    int V = 9;
    Graph g(V);
  
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
  
    return 0;
}

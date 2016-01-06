#include <iostream>
#include <queue>          // std::queue
#include <algorithm>    // std::max
#include <signal.h>

using namespace std;
class Graph
{
public:
    int V;
    int E;
    int **adj;
    Graph() {
        V = 0;
        E = 0;
    }
    Graph(int v, int e)
    {
        V = v;
        E = e;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    Graph(int v, int e, pair<int,int> *Edges, int pairs)
    {
        V = v;
        E = e;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < pairs; i++) {
            adj[i][i] = 1;
            adj[Edges[i].first][Edges[i].second] = 1;
            adj[Edges[i].second][Edges[i].first] = 1;
        }
    }
    void show() {
        cout<<"Graph Vertices : "<<V<<endl;
        cout<<"Graph Edges    : "<<E<<endl;
        cout<<"Graph Adjacency:"<<endl;
        cout<<"  ";
        for (int i = 0; i < V; i++) {
            cout<<i<<" ";
        }
        cout<<endl;
        for (int i = 0; i < V; i++) {
            cout<<i<<" ";
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

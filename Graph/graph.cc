#include "graph.h"

void DFS_(Graph *G, int *visited, int u)
{
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < G->V; v++) {
        if (visited[v] == 0 && G->adj[u][v] == 1) {
            DFS_(G, visited, v);
        }
    }
}
void DFS(Graph *G)
{
    int *visited = new int[G->V];
    memset(visited,0,G->V);
    DFS_(G,visited, 0);
    cout<<endl;
}

int main() {
    int edges = 6;
    int pairs = edges;
    pair<int,int> *Edges = new pair<int,int> [pairs];   //creating the array

    Edges [0] = make_pair(0,1);             //Filling arbitrary numbers
    Edges [1] = make_pair(1,2);
    Edges [2] = make_pair(1,3);
    Edges [3] = make_pair(3,4);
    Edges [4] = make_pair(4,5);
    Edges [5] = make_pair(2,5);

    Graph *G = new Graph(6, edges, Edges, pairs);
    G->show();
    DFS(G);
    return 0;
}

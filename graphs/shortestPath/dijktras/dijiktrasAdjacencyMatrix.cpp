/*
    Dijiktras for Adjacency Matrix
    https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/
#include <bits/stdc++.h>
using namespace std;

// number of vertices in the graph
#define V 9

/* a utility function to find the vertex with minimum distance value,
from the set of vertices not yet included in the shortest path tree*/
int minDistance(int dist[], bool sptSet[]){
    // initialized min value
    int min = INT_MAX, min_index;

    // we will look for the next element woth smallest distance to out current root node, which is not yet processed
    for(int v = 0; v < V; v++)
        if(sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// to print the distance array
void printSolution(int dist[]){
    cout << "vertex \t\t Distance from source\n";
    for(int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

/* implements Dijiktras single source shortest path algorithm for a graoh represented using adjacency matrix representation */
void dijkstra(int graph[V][V], int src){
    int dist[V];    // the output array, dist[i] will hold shortest path sdistance from source to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortestpath tree or the shotrtest distance from src to i is finalized

    // initialize all distances as INFINITE and stpSet[] as false
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // distance of source vertex from itself is always 0
    dist[src] = 0;

    // find the shortest path for all the vertices
    for(int count = 0; count < V-1; count++){
        /* pick the minimum distance vertex from the set of vertices not yet processed, u is always
        equal to src in the first iteration*/
        int u = minDistance(dist, sptSet);

        // mark the picked Vertex as processed
        sptSet[u] = true;

        // update dist value of the adjacent vertices of the picked vertex
        for(int v = 0; v < V; v++){
            /* Update dist[v], only if the v'th vertex is not already processed and it exist's in graph
            and the distance from u-->v is less than already stored distance at v
            */
            if( dist[u] != INT_MAX && !sptSet[v] && graph[u][v]
                && dist[u] + graph[u][v] < dist[v]
            ){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }


    printSolution(dist);
}
// Driver function
int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
    return 0;
}

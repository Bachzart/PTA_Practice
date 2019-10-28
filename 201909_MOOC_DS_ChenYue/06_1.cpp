#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum) {
    Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V = 0; V < Graph->Nv; V++) {
        for(W = 0; W < Graph->Nv; W++) {
            Graph->G[V][W] = INFINITY;
        }
    }
    return Graph;
}
void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = 1;
    Graph->G[E->V2][E->V1] = 1;
}
MGraph BuildGraph() {
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &Graph->Ne);
    if(Graph->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0; i < Graph->Ne; i++) {
            scanf("%d %d", &E->V1, &E->V2);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}
bool IsEdge(MGraph Graph, Vertex V, Vertex W) {
    return Graph->G[V][W] < INFINITY ? true : false;
}
void Visit(Vertex V) {
    printf("%d ", V);
}
void DFS(MGraph Graph, Vertex V, void (*Visit)(Vertex), int Visited[]) {
    Visit(V);
    Visited[V] = true;
    Vertex W;
    for(W = 0; W < Graph->Nv; W++) {
        if(!Visited[W] && IsEdge(Graph, V, W)) DFS(Graph, W, Visit, Visited);
    }
}
void BFS(MGraph Graph, Vertex S, void (*Visit)(Vertex), int Visited[]) {
    Vertex Queue[MaxVertexNum], front = -1, rear = -1;	// use a simple queue
    Vertex V, W;
    Visit(S);
    Visited[S] = true;
    Queue[++rear] = S;	//enqueue
    while(front < rear) {
        V = Queue[++front];	//dequeue
        for(W = 0; W < Graph->Nv; W++) {
            if(!Visited[W] && IsEdge(Graph, V, W)) {
                Visit(W);
                Visited[W] = true;
                Queue[++rear] = W;
            }
        }
    }
}
void ListComponents(MGraph Graph) {
    Vertex S;
    int Visited[MaxVertexNum] = {false};
    for(S = 0; S < Graph->Nv; S++) {
        if(!Visited[S]) {
            printf("{ ");
            DFS(Graph, S, Visit, Visited);
            printf("}\n");
        }
    }
    memset(Visited, 0, sizeof(Visited));
    for(S = 0; S < Graph->Nv; S++) {
        if(!Visited[S]) {
            printf("{ ");
            BFS(Graph, S, Visit, Visited);
            printf("}\n");
        }
    }
}
int main() {
    MGraph G = BuildGraph();
    ListComponents(G);
    return 0;
}

/* simple method: use 2-dimensional array represent adjcent matrix

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10 + 5;
const int inf = 0x3fffffff;
int G[maxn][maxn], nv, ne;
bool visited[maxn] = {false};
void init() {
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			G[i][j] = inf;
		}
	}
}
void dfs(int node) {
	visited[node] = true;
	cout << node << ' ';
	for(int i = 0; i < nv; i++) {
		if(!visited[i] && G[node][i] != inf) dfs(i);
	}
}
void bfs(int node) {
	queue<int> q;
	cout << node << ' ';
	visited[node] = true;
	q.push(node);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < nv; i++) {
			if(!visited[i] && G[front][i] != inf) {
				cout << i << ' ';
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
void listcomponents() {
	for(int i = 0; i < nv; i++) {
		if(!visited[i]) {
			cout << "{ ";
			dfs(i);
			cout << "}\n";
		}
	}
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < nv; i++) {
		if(!visited[i]) {
			cout << "{ ";
			bfs(i);
			cout << "}\n";
		}
	}
}
int main() {
	init();
	cin >> nv >> ne;
	for(int i = 0; i < ne; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}
	listcomponents();
	return 0;
}

*/

/*
some samples:
in:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
out:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

*/

/* notes: The adjacency list is built by head pointer, so the traversal sequences
is not same as sample output. Actually, because the adjacency list is not 
unique, so the traversal sequences also is not unique. You can use the sort
function to get the same result. 
 */

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
struct ENode{
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G; 
};
typedef PtrToGNode LGraph;
LGraph CreateGraph(int VertexNum) {
	Vertex V;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V < Graph->Nv; V++) {
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}
void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}
LGraph BuildGraph() {
	LGraph Graph;
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
void Visit(Vertex V) {
	printf("%d ", V);
}
void DFS(LGraph Graph, Vertex S, void (*Visit)(Vertex), int Visited[]) {
	PtrToAdjVNode W;
	Visit(S);
	Visited[S] = true;
	for(W = Graph->G[S].FirstEdge; W; W = W->Next) {
		if(!Visited[W->AdjV]) DFS(Graph, W->AdjV, Visit, Visited);
	}
}
void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex), int Visited[]) {
	Vertex Queue[MaxVertexNum], front = -1, rear = -1;
	Vertex V;
	Visit(S);
	Visited[S] = true;
	Queue[++rear] = S;
	while(front < rear) {
		V = Queue[++front];
		PtrToAdjVNode W;
		for(W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if(!Visited[W->AdjV]) {
				Visit(W->AdjV);
				Visited[W->AdjV] = true;
				Queue[++rear] = W->AdjV;
			}
		}
	}
}
void ListComponents(LGraph Graph) {
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
	LGraph G = BuildGraph();
	ListComponents(G);
	return 0;
}

/*
samples:
in:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
out:
{ 0 2 4 1 7 }
{ 3 5 }
{ 6 }
{ 0 2 1 7 4 }
{ 3 5 }
{ 6 }

*/


#ifndef _Graph_H
#define _Graph_H
// graph expressed by adjacety list
struct node;
typedef struct node *Node;
struct graph;
typedef struct graph *Graph;
struct queue;
typedef struct queue *Queue;
struct qnode;
typedef struct qnode *Qnode;
struct node
{
	int vertex;
	int weight;
	Node adjnext;
	int indegree;
	int outdegree;
	int tmp;
};
struct graph
{
	int vertex_num;
	int *top_num;
	Node *vertex_array;
	int *path;
};
struct queue
{
	int capacity;
	int size;
	int *array;
	Qnode header;
	Qnode tailer;
};
struct qnode
{
	int x;
	Qnode next;
};
Graph creategraph(int vertex_num,FILE *fp);
void topsort(Graph p);
int breadthfirstsearch(Graph p,int startv,int endv);
int dijkstra(Graph p,int startv,int endv);
int depthfirstsearch(Graph p,int startv,int endv);
int depthfirstsearchwithstack(Graph p,int startv,int endv);
int DFS(Graph p,int startv,int endv);
int UCS(Graph p,int startv,int endv);
int deletemin(Graph p,int *bheap,int size);
int inserttobheap(Graph p,int *bheap,int size,int vertex);
void printgraph(Graph p);
void freegraph(Graph p);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#define VERTEXNUM 10000

int main(int argc, char const *argv[])
{
	Graph p;
	FILE *fp;
	fp=fopen("graph3.txt","r");
	p=creategraph(VERTEXNUM,fp);
	fclose(fp);

	// topsort(p);
	// breadthfirstsearch(p,1,12);
	// dijkstra(p,1,12);

	// initial graph vertex's tmp used for recorde path length
	// or whethere visited.
	int startv=1,endv=12;
	// for(int i=1;i<=p->vertex_num;i++)
	// 	p->vertex_array[i]->tmp=INT_MAX;
	// p->vertex_array[startv]->tmp=0;
	// p->path[startv]=0;
	// depthfirstsearch(p,startv,endv);
	// DFS(p,4,endv);
	// depthfirstsearchwithstack(p,startv,endv);
	UCS(p,startv,endv);

	printgraph(p);

	freegraph(p);
	exit(0);
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
// create graph with adjacency list
Graph creategraph(int vertex_num,FILE *fp)
{
	Graph p;
	int vertexs=0;
	int vertex,weight,adjvertex;
	p=malloc(sizeof(struct graph));
	if(p==NULL)
		return NULL;
	p->vertex_array=malloc(vertex_num*sizeof(Node));
	if(p==NULL)
		return NULL;
	// for UCS 
	p->vertex_array[0]=malloc(sizeof(struct node));
	p->vertex_array[0]->tmp=-1;
	while(fscanf(fp,"%d|%d|%d",&vertex,&weight,&adjvertex)!=EOF)
	{
		if(p->vertex_array[vertex]==NULL)
		{
			vertexs++;
			Node n;
			n=malloc(sizeof(struct node));
			if(n==NULL)
				return NULL;
			p->vertex_array[vertex]=n;
			p->vertex_array[vertex]->vertex=vertex;
			p->vertex_array[vertex]->weight=0;
			p->vertex_array[vertex]->adjnext=NULL;
			p->vertex_array[vertex]->indegree=0;
			p->vertex_array[vertex]->outdegree=0;
		}
		if(adjvertex!=0)
		{
			Node n;
			n=malloc(sizeof(struct node));
			if(n==NULL)
				return NULL;
			n->vertex=adjvertex;
			n->weight=weight;
			n->adjnext=p->vertex_array[vertex]->adjnext;
			p->vertex_array[vertex]->adjnext=n;
			p->vertex_array[vertex]->outdegree++;

			if(p->vertex_array[adjvertex]==NULL)
			{
				vertexs++;
				Node n;
				n=malloc(sizeof(struct node));
				if(n==NULL)
					return NULL;
				p->vertex_array[adjvertex]=n;
				p->vertex_array[adjvertex]->vertex=adjvertex;
				p->vertex_array[adjvertex]->weight=0;
				p->vertex_array[adjvertex]->adjnext=NULL;
				p->vertex_array[adjvertex]->indegree=0;
				p->vertex_array[adjvertex]->outdegree=0;
			}
			p->vertex_array[adjvertex]->indegree++;
		}
	}
	p->vertex_array[vertexs+1]=NULL;
	p->vertex_num=vertexs;
	// create topnum array and initial 
	p->top_num=malloc(p->vertex_num*sizeof(int));
	for(int i=0;i<p->vertex_num;i++)
		p->top_num[i]=-1;
	// create path recorde and initial
	p->path=malloc((p->vertex_num+1)*sizeof(int));
	for(int i=0;i<p->vertex_num+1;i++)
		p->path[i]=-1;
	printf("create graph finished!\n");
	return p;
}
// top sort
void topsort(Graph p)
{
	int vertex_num=p->vertex_num;
	//create queue(stack) and initial
	Queue q;
	q=malloc(sizeof(struct queue));
	q->capacity=vertex_num;
	q->size=0;
	q->array=malloc(vertex_num*sizeof(int));
	for(int i=0;i<vertex_num;i++)
		q->array[i]=0;
	// initial topnum array
	for(int i=0;i<vertex_num;i++)
		p->top_num[i]=-1;
	// if indegree=0,enqueue(push)
	for(int i=1;i<=vertex_num;i++){
		if(p->vertex_array[i]->indegree==0)
			q->array[q->size++]=p->vertex_array[i]->vertex;
		// save the indegree
		p->vertex_array[i]->tmp=p->vertex_array[i]->indegree;
	}
	// if queue not empty,dequeue(pop)
	int i=0,counter=0;
	while(q->size!=0)
	{
		int vertex=0;
		vertex=q->array[--q->size];
		q->array[q->size]=0;
		p->top_num[i++]=vertex;
		counter++;

		Node n,next;
		n=p->vertex_array[vertex]->adjnext;
		while(n!=NULL)
		{
			vertex=n->vertex;
			if(--p->vertex_array[vertex]->tmp==0)
				q->array[q->size++]=p->vertex_array[vertex]->vertex;
			n=n->adjnext;
		}
	}
	if(counter!=p->vertex_num)
		printf("has cycle!\n");
	else
		printf("no cycle!\n");
	// free queue(stack)
	free(q->array);
	free(q);
}
// breadth-first search with a queue
int breadthfirstsearch(Graph p,int startv,int endv)
{
	// breadth-first search
	// create a queue
	Queue q;
	q=malloc(sizeof(struct queue));
	q->header=malloc(sizeof(struct qnode));
	q->tailer=q->header;
	q->header->x=-1;
	q->header->next=NULL;
	// initial graph vertex's tmp
	for(int i=1;i<=p->vertex_num;i++)
		p->vertex_array[i]->tmp=-1;
	p->vertex_array[startv]->tmp=0;
	// the first time-enqueue
	Qnode qn;
	qn=malloc(sizeof(struct qnode));
	qn->x=startv;
	qn->next=q->tailer->next;
	q->tailer->next=qn;
	q->tailer=qn;
	//initial path and set path in startv
	for(int i=0;i<p->vertex_num+1;i++)
		p->path[i]=-1;
	p->path[startv]=0;
	// int i=0;
	// int end;
	while(q->header->next!=NULL) // queue is not empty
	{
		// printf("%d\n",++i );
		// if-dqueue
		Qnode qn;
		int vertex;
		qn=q->header->next;
		vertex=qn->x;
		// printf("dequeue:%d\n", vertex);
		// if(end==endv)
		// 	break;
		q->header->next=qn->next;
		free(qn);
		if(q->header->next==NULL)
			q->tailer=q->header;
		// if-enqueue
		Node n;
		n=p->vertex_array[vertex]->adjnext;
		// int j=0;
		while(n!=NULL)
		{
			// printf("  %d\n",++j);
			int adjvertex=n->vertex;
			int adjtmp=p->vertex_array[adjvertex]->tmp;
			if(adjtmp==-1)
			{
				p->path[adjvertex]=vertex;
				int vertextmp=p->vertex_array[vertex]->tmp;
				p->vertex_array[adjvertex]->tmp=vertextmp+1;
				// p->vertex_array[adjvertex]->tmp=vertextmp+n->weight;
				// if(adjvertex==endv)
				// {
				// 	end=endv;
				// 	break;
				// }
				Qnode qn;
				qn=malloc(sizeof(struct qnode));
				qn->x=n->vertex;
				qn->next=q->tailer->next;
				q->tailer->next=qn;
				q->tailer=qn;
			}
			n=n->adjnext;
		}
	}
	// free queue
	qn=q->header->next;
	while(qn!=NULL)
	{
		q->header->next=qn->next;
		free(qn);
		qn=q->header->next;
	}
	// free header
	free(q->header);
	// free queue
	free(q);
	return 0;
}
// dijkstra 
int dijkstra(Graph p,int startv,int endv)
{
	// create a queue
	Queue q;
	q=malloc(sizeof(struct queue));
	q->header=malloc(sizeof(struct qnode));
	q->tailer=q->header;
	q->header->x=-1;
	q->header->next=NULL;
	// initial graph tmp
	for(int i=1;i<=p->vertex_num;i++)
		p->vertex_array[i]->tmp=INT_MAX;
	p->vertex_array[startv]->tmp=0;
	// the first time-enqueue
	Qnode qn;
	qn=malloc(sizeof(struct qnode));
	qn->x=startv;
	qn->next=q->tailer->next;
	q->tailer->next=qn;
	q->tailer=qn;
	// // create path recorde and initial
	// p->path=malloc((p->vertex_num+1)*sizeof(int));
	for(int i=0;i<p->vertex_num+1;i++)
		p->path[i]=-1;
	p->path[startv]=0;
	// int i=0;
	// int end;
	while(q->header->next!=NULL) // queue is not empty
	{
		// printf("%d\n",++i );
		// if-dqueue
		Qnode qn;
		int vertex;
		qn=q->header->next;
		vertex=qn->x;
		// printf("dequeue:%d\n", vertex);
		// if(end==endv)
		// 	break;
		q->header->next=qn->next;
		free(qn);
		if(q->header->next==NULL)
			q->tailer=q->header;
		// if-enqueue
		Node n;
		n=p->vertex_array[vertex]->adjnext;
		// int j=0;
		while(n!=NULL)
		{
			// printf("  %d\n",++j);
			int vertextmp=p->vertex_array[vertex]->tmp;
			int adjvertex=n->vertex;
			int adjtmp=p->vertex_array[adjvertex]->tmp;
			if(adjtmp>vertextmp+n->weight)
			{
				p->path[adjvertex]=vertex;
				// p->vertex_array[adjvertex]->tmp=vertextmp+1;
				p->vertex_array[adjvertex]->tmp=vertextmp+n->weight;
				// if(adjvertex==endv)
				// {
				// 	end=endv;
				// 	break;
				// }
				Qnode qn;
				qn=malloc(sizeof(struct qnode));
				qn->x=n->vertex;
				qn->next=q->tailer->next;
				q->tailer->next=qn;
				q->tailer=qn;
			}
			n=n->adjnext;
		}
	}
	// free queue
	qn=q->header->next;
	while(qn!=NULL)
	{
		q->header->next=qn->next;
		free(qn);
		qn=q->header->next;
	}
	// free header
	free(q->header);
	// free queue
	free(q);
	return 0;
}
// the core of depth-first search with recursion
int depthfirstsearch(Graph p,int startv,int endv)
{
	int adjvertex=0;
	Node s,e,n;
	s=p->vertex_array[startv];
	// s->tmp=0;
	n=s->adjnext;
	printf("startv %d\n",startv);
	while(n!=NULL)
	{
		adjvertex=n->vertex;
		e=p->vertex_array[adjvertex];
		// if(e->tmp==-1)
		// if(adjvertex!=endv)
		if(s->tmp+n->weight<e->tmp)
		{
			p->path[adjvertex]=startv;
			e->tmp=s->tmp+n->weight;
			printf(" %d->%d ",startv,adjvertex);
			depthfirstsearch(p,adjvertex,endv);
		}
		n=n->adjnext;
	}

	return 0;
}
// the core of depth-first search with a stack
int depthfirstsearchwithstack(Graph p,int startv,int endv)
{
	int vertex_num=0,vertex=0,adjvertex=0;
	int tmp=0,adjtmp=0,newadjtmp=0;
	Node n;
	// initialize tmp and path
	for(int i=1;i<=p->vertex_num;i++)
		p->vertex_array[i]->tmp=INT_MAX;
	p->vertex_array[startv]->tmp=0;
	p->path[startv]=0;
	// create stack and push the startv
	vertex_num=p->vertex_num;
	int pstack[vertex_num],size=0;
	pstack[size++]=startv;
	// if-pstack is not empty->loop
	while(size>0)
	{
		// pop the vertex
		vertex=pstack[--size];
		// p->vertex_array[vertex]->tmp=0;
		// the adjvertex
		n=p->vertex_array[vertex]->adjnext;
		while(n!=NULL)
		{
			// if-push
			adjvertex=n->vertex;
			tmp=p->vertex_array[vertex]->tmp;
			adjtmp=p->vertex_array[adjvertex]->tmp;
			newadjtmp=tmp+n->weight;
			// if(adjtmp==-1) // visit
			if(newadjtmp<adjtmp)
			{
				p->vertex_array[adjvertex]->tmp=newadjtmp;
				p->path[adjvertex]=vertex;
				// push
				pstack[size++]=adjvertex;
			}
			n=n->adjnext;
		}
	}
	return 0;
}
// depth-first search with recursion 
int DFS(Graph p,int startv,int endv)
{
	// all vertex push stack
	// used for some disconnected vertex
	// and generate depth-first spanning forest
	int stack[p->vertex_num+1],size=0,vertex=0;
	for (int i = 0; i < p->vertex_num; ++i)
		stack[size++]=i+1;
	stack[size++]=startv;
	// stack pop vertexs-if 
	while(--size>=0)
	{
		vertex=stack[size];
		if (p->vertex_array[vertex]->tmp==-1)
			depthfirstsearch(p,vertex,endv);
	}
	return 0;
}
// uninformation cost search
int UCS(Graph p,int startv,int endv)
{
	int vertex=0,adjvertex=0,vertex_num=0;
	vertex_num=p->vertex_num;
	int tmp=0,adjtmp=0,newadjtmp=0;
	Node n;
	// create a min heap and initialize
	int bheap[2*vertex_num+1],size=0;
	bheap[size]=0;bheap[++size]=startv;
	// initialize tmp and path
	for(int i=1;i<=vertex_num;i++)
		p->vertex_array[i]->tmp=INT_MAX;
	p->vertex_array[startv]->tmp=0;
	p->path[startv]=0;
	// if-heap is not empty->loop
	int pathtmp[vertex_num+1]; // for negative weight
	int i=0;
	unsigned char visted=0x00;// whether in heap
	while(size>0)
	{
		printf("%d\n",++i );
		// delete min
		vertex=deletemin(p,bheap,size);
		size--;
		printf("deheap:%d\n",vertex);
		printf("bheap:[");
		for(int i=1;i<=size;i++)
			printf(" %d",bheap[i] );
		printf(" ]\n");
		// if-break
		if(vertex==endv)
			break;
		// if-insert
		n=p->vertex_array[vertex]->adjnext;
		while(n!=NULL)
		{
			adjvertex=n->vertex;
			tmp=p->vertex_array[vertex]->tmp;
			adjtmp=p->vertex_array[adjvertex]->tmp;
			newadjtmp=fabs(tmp+n->weight);
			// newadjtmp=tmp+n->weight;
			if(newadjtmp<adjtmp)
			{
				if(adjvertex!=vertex)
					pathtmp[adjvertex]=vertex;
				p->path[adjvertex]=vertex;
				p->vertex_array[adjvertex]->tmp=newadjtmp;
				// int vih=visted&(0x01<<adjvertex);
				// if(vih==0)//if-in heap
				// {
				// 	visted|=(0x01<<adjvertex);
					inserttobheap(p,bheap,size,adjvertex);
					size++;
					printf("enheap:%d\n", adjvertex);
				// }
			}

			n=n->adjnext;
		}
		printf("bheap:[");
		for(int i=1;i<=size;i++)
			printf(" %d",bheap[i] );
		printf(" ]\n");
	}
	for(int i=1;i<=vertex_num;i++)
		printf("%d ", pathtmp[i]);
	return 0;
}
int deletemin(Graph p,int *bheap,int size)
{
	int bhsize,minvertex,lastvertex,i,child,tmp,rtmp,ltmp,lasttmp;
	bhsize=size;
	minvertex=bheap[1];
	lastvertex=bheap[bhsize];
	bhsize--;
	lasttmp=p->vertex_array[lastvertex]->tmp;

	for(i=1;2*i<=bhsize;i=child)
	{
		// the min between left child and right child
		child=2*i;
		ltmp=p->vertex_array[bheap[child]]->tmp;
		rtmp=p->vertex_array[bheap[child+1]]->tmp;
		if(child!=bhsize && rtmp<ltmp)
			child++;
		tmp=p->vertex_array[bheap[child]]->tmp;
		
		// for save last element
		if(lasttmp>tmp)
			bheap[i]=bheap[child];
		else
			break;
	}
	bheap[i]=lastvertex; // save the last element

	return minvertex;

}
int inserttobheap(Graph p,int *bheap,int size,int vertex)
{

	int bhsize,i,tmp;
	bhsize=size;
	tmp=p->vertex_array[vertex]->tmp;
	for(i=++bhsize;p->vertex_array[bheap[i/2]]->tmp>=tmp;i/=2)
		bheap[i]=bheap[i/2];
	bheap[i]=vertex;

	return 0;
}
// print graph
void printgraph(Graph p)
{
	// print the graph
	printf("the base graph information:\n");
	printf("node numbers:%d\n",p->vertex_num);
	printf("vertex|weight|adjvertex\n");
	int i=0;
	Node n;
	while(p->vertex_array[++i]!=NULL)
	{
		n=p->vertex_array[i]->adjnext;
		if(n==NULL)
		{
			printf("%d",p->vertex_array[i]->vertex);
			printf("|");
			printf("%d",0);
			printf("|");
			printf("%d\n",0);
			continue;
		}
		while(n!=NULL)
		{
			printf("%d",p->vertex_array[i]->vertex);
			printf("|");
			printf("%d",n->weight);
			printf("|");
			printf("%d",n->vertex);
			printf("\n");

			n=n->adjnext;
		}
	}

	i=0;
	while(p->vertex_array[++i]!=NULL)
	{
		printf("node %d",p->vertex_array[i]->vertex);
		printf(" indegree:%d",p->vertex_array[i]->indegree);
		printf(" outdegree:%d\n",p->vertex_array[i]->outdegree);
	}
	printf("\n");

	// printf("top sort:\n");
	// for(int i=0;i<p->vertex_num;i++)
	// 	printf("%d ", p->top_num[i]);
	// printf("\n");

	// printf("breadth-first search/dijkstra from startv:\n");
	// for(int i=1;i<=p->vertex_num;i++)
	// 	printf("vertex:%d pathlength:%d\n",\
	// 		p->vertex_array[i]->vertex,p->vertex_array[i]->tmp);
	// printf("\n");

	printf("breadth/depth-first search/dijkstra result->path:\n");
	for(int i=1;i<=p->vertex_num;i++)
		printf("%d ",p->path[i]);
	printf("\n");

	// printf("(shortest)path from startv to vertex 1002 is:\n");
	// int end=p->path[1002];
	// int pathstack[p->vertex_num];
	// int size=0;
	// if(end!=-1)
	// {
	// 	while(end!=0)
	// 	{
	// 		pathstack[size++]=end;
	// 		end=p->path[end];
	// 	}
	// 	while(--size>=0)
	// 		printf("%d ",pathstack[size]);
	// 	printf("%d",1002);
	// 	printf("\n");
	// }
	// else
	// 	printf("no path to vertex 5.\n");

	printf("depth-first search from startv:\n");
	for(int i=1;i<=p->vertex_num;i++)
		printf("vertex:%d visited:%d\n",\
			p->vertex_array[i]->vertex,p->vertex_array[i]->tmp);
	printf("\n");

	return;
}
// free graph
void freegraph(Graph p)
{
	// free adjvertex
	Node n,next;
	for(int i=1;i<=p->vertex_num;i++)
	{
		 n=p->vertex_array[i]->adjnext;
		while(n!=NULL)
		{
			next=n->adjnext;
			free(n);
			n=next;
		}
	}
	// free header
	for(int i=0;i<=p->vertex_num;i++)
	{
		free(p->vertex_array[i]);
	}
	// free topnum array;
	free(p->top_num);
	// free vertex array
	free(p->vertex_array);
	// free path
	free(p->path);
	// free graph 
	free(p);

	printf("finished excuted free graph!\n");
	return;
}
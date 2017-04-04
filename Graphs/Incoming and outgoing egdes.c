/**Consider an undirected graph with vertices numbered 0 to N, where N is entered by the user. Every vertex stores an integer,
 which is also supplied by the user. A vertex i is connected to the vertices i-2, i+1, i+2, i+5 and i+10 (if the indices exist).
 Print all the outgoing edges from a vertex i and all the incoming edges to a vertex i.
**/

#include <stdio.h>
#include <stdlib.h>
struct node{
    int dest;
    struct node* next;
};

struct AdjList{
    struct node* head;
};

struct Graph{
    int v;
    struct AdjList* arr;
};

struct Graph* createGraph(int v)
{
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->v = v;
    graph->arr = (struct AdjList*) malloc((v+1)*sizeof(struct AdjList));
    int i;
    for(i=0;i<=v;i++)
    {
        graph->arr[i].head= NULL;
    }
    return graph;
}

struct node* AddNode(int dest)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void AddEdge(struct Graph* graph,int src,int dest)
{
    struct node* newNode = AddNode(dest);
    newNode->next = graph->arr[src].head;
    graph->arr[src].head=newNode;
    /**newNode = AddNode(src);
    newNode->next = graph->arr[dest].head;
    graph->arr[dest].head=newNode;**/
}
void printGraph(struct Graph* graph)
{
    int i;
    for(i=0;i<=graph->v;i++)
    {
        struct node* blah = graph->arr[i].head;
        printf("The Adjacency list of vertex %d\n head", i);
        while(blah!=NULL)
        {
            printf(" -> %d",blah->dest);
            blah=blah->next;
        }
        printf("\n");
    }
}

void outgoing(struct Graph *graph,int u)
{
    struct node *t = graph->arr[u].head;
    printf("All outgoing edges from vertex %d are: \n",u);
    while(t!=NULL)
    {
        printf("%d ",t->dest);
        t=t->next;
    }
}
void incoming(struct Graph *graph,int u)
{
    int i;
    printf("All incoming edges into vertex %d are: \n",u);
    for(i=0;i<=graph->v;i++)
    {
        struct node *t = graph->arr[i].head;
        while(t!=NULL)
        {
            if(t->dest==u)
            printf("%d ",i);
            t=t->next;
        }
    }
}
int main(void) {
    int v,i,v1,flag=0;
    scanf("%d",&v);
    scanf("%d",&v1);
    struct Graph* graph = createGraph(v);
    for(i=0;i<=v;i++)
    {
        if((i-2)<=v&&(i-2)>=0)
        AddEdge(graph,i,i-2);
        if((i+1)<=v)
        AddEdge(graph,i,i+1);
        if((i+2)<=v)
        AddEdge(graph,i,i+2);
        if((i+5)<=v)
        AddEdge(graph,i,i+5);
        if((i+10)<=v)
        AddEdge(graph,i,i+10);
    }
    outgoing(graph,v1);
    printf("\n");
    incoming(graph,v1);
    return 0;
}

#ifndef __GRAPH__
#define __GRAPH__
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Node{
    Data data;
    struct Node* next;
}node;

typedef struct LIST{
    node* head;
    node* cur;
    node* before;
    int size;
}List;

typedef struct Graph{
    int numV;
    int numE;
    List* adjacent;
}graph;

void ListInit(List * plist);
void LInsert(List * plist, Data data);


int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);

void GraphInit(graph* gh);
void insert_vertex(graph* gh,int v);
void insert_edge(graph* gh, int from,int to);

void delete_vertex(graph* gh,int v);
void delete_edge(graph* gh, int from,int to);

int is_empty(graph* gh);
void destroy_graph(graph* gh);
#endif
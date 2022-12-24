#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int visited[MAX] = {0,};
typedef struct GraphType{
    int adj_mat[MAX][MAX];
    int n;
}GraphType;

typedef struct Queue{
    int item;
    struct Queue* llink;
    struct Queue* rlink;
}Queue;

typedef struct Type{
    struct Queue* front, *rear;
}Type;

void init(Type*q){
    q -> front = q -> rear = NULL;
}

int is_empty(Type*q){
    return(q -> front == NULL && q -> rear == NULL);
}

Queue* makenode(int item){
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    if(temp == NULL){
        printf("malloc error\n");
    }
    else{
        temp -> item = item;
        temp -> rlink = NULL;
        temp -> llink = NULL;
        return temp;
    }
}

void enqueue(Type* q, int value){
    Queue* temp;
    temp = makenode(value);
    if(is_empty(q)){
        q -> front = q -> rear = temp;
    }
    else{
        temp -> rlink = q -> front;
        q -> front ->llink = temp;
        q -> front = temp;
    }
}

int dequeue(Type* q){
    int i;
    Queue* temp = q -> rear;
    if(is_empty(q)){
        printf("empty queue\n");
        return -1;
    }
    else if(q -> front == q -> rear){
        i = q -> rear -> item;
        q -> front = q -> rear = NULL;
        free(temp);
        return i;
    }
    else{
        i = q -> rear -> item;
        q -> rear = q -> rear -> llink;
        free(temp);
        return i;
    }
}

void bfs_mat(GraphType *g, int v){
    int w;
    Type q;
    init(&q); 
    visited[v] = 1; 
    printf("%d ", v); 
    enqueue(&q, v); 
    while(!is_empty(&q)){
        v = dequeue(&q); 
        for(w=0; w<g->n; w++) 
            if(g->adj_mat[v][w]==1 && !visited[w]){ 
                visited[w] = 1; 
                printf("%d ", w); 
                enqueue(&q, w); 
            }
    }
}

int main(void){
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    g -> n = 5;

    int test[MAX][MAX] = {{0,1,1,0,1},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,1},{1,0,1,1,0}};

    for(int i = 0; i < 5; i++){
       for(int j = 0; j < 5; j++){
           *(*(g -> adj_mat + i) + j) = *(*(test + i) + j);
       }
    }
    bfs_mat(g, 0);
}
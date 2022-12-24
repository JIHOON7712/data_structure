#include <stdio.h>
#include <stdlib.h>


typedef struct QueueNode{
    struct QueueNode* link;
    int data;
}QueueNode;

typedef struct QueueType{
    QueueNode* front;
    QueueNode* back;
}QueueType;

void eq(QueueType* q,int data){
    if(q->front == NULL && q->back == NULL){
        QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
        new->data = data;
        new->link = NULL;
        q->front = q->back = new;
        return;
    }
    else{
        QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
        new->data = data;
        q->back->link = new;
        new->link = NULL;
        q->back = new;
        return;
    }
}
int dq(QueueType* q){
    int item;
    if(q->front == q->back){
        item = q->front->data;
        free(q->front);
        q->front = q->back = NULL;
        return item;
    }else{
        item = q->front->data;
        QueueNode* tmp = q->front;
        q->front = q->front->link;
        free(tmp);
        return item;
    }
}

int iepty(QueueType* q){
    if(q->back == NULL && q->front == NULL)
        return 1;
    else
    {
        return 0;
    }
    
}

void dfs(int graph[5][5],int v[5],int start){
    v[start] = 1;
    printf("%d ",start);
    for(int w=0;w<5;++w){
        if(!v[w] && graph[start][w]==1) dfs(graph,v,w);
    }

}

void bfs(int graph[5][5],int v[5],int start){
    QueueType* q = (QueueType*)malloc(sizeof(QueueType));
    q->front = q->back = NULL;
    printf("%d ",start);
    v[start]=1;
    eq(q,start);
    while(!iepty(q)){
        int x = dq(q);
        for(int i=0;i<5;++i){
            if(!v[i]&&graph[x][i]==1){
                v[i] = 1;
                printf("%d ",i);
                eq(q,i);
            }
        }
    }

}

int main(void){
    int graph[5][5] = {{0,1,1,0,1}
                      ,{1,0,1,0,0}
                      ,{1,1,0,1,1}
                      ,{0,1,1,0,1}
                      ,{1,0,1,1,0}};
    int v[] = {0,0,0,0,0};
    dfs(graph,v,0);
    printf("\n");
    printf("%d\n", count);
    for(int i=0;i<5;++i){
        v[i] = 0;
    }
    bfs(graph,v,0);
    printf("\n");
}
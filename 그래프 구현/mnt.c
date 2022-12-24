#include <stdio.h>
#define INF 10000000
int number = 6;
int a[6][6] = { {0,2,5,1, INF, INF}, {2,0,3,2, INF, INF}, {5,3,0,3,1,5}, {1,2,3,0,1, INF}, {INF, INF,1,1,0,2}, {INF, INF,5, INF,2,0}};
int v[6] = {0,};
int d[6];

void dijkstra(int start) {
    int cnt = number;
    for(int i = 0; i < number; i++){ 
        d[i] = a[start][i];
    }
    v[start] = 1;
    while(cnt--){
        int k = INF;
        for(int i = 0; i < number; i++){
            if(!v[i] && a[start][i]){
                if(k == INF){
                    k = i;
                }
                else if(a[start][k] > a[start][i]){
                    k = i;
                }                
            }
        }
        if(k == INF){
            return;
        }
        start = k;
        for(int i = 0; i < number; i++){
            if (d[start]+a[start][i] < d[i]){
                d[i] = d[start]+a[start][i];
            }
        }
        v[start] = 1;
    }
}

int main() {
 dijkstra(0);
 for (int i = 0; i < number; i++) {
    printf("%d ", d[i]);
    } 

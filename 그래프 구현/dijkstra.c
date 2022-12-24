#include <stdio.h>
#define INF 10000000
int number = 6;
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
    };
int v[6];
int d[6];


void dijkstra(int start) {
    for(int i=0;i<6;++i){   //첫 번째 distance 초기화
        d[i] = a[start][i];
    }
    for(int i=0; i<6;++i){
        int k = INF;
        for(int j=0;j<6;++j){   //distance배열 중 가장 작은 값 찾기
            if(!v[j]&&k>d[j]){
                start = j;
                k=d[j];
            }
        }
        printf("%d ",start);
        v[start] = 1;
        for(int s=0;s<6;++s){   //distance 배열 갱신
            if(d[s]>(d[start]+a[start][s])){
                d[s] = a[start][s]+d[start];
            }
        }
    }
}


int main() {
    dijkstra(0);
    printf("\n");
    for (int i = 0; i<number;i++) {
    printf("%d ", d[i]);
    }
    printf("\n");
}
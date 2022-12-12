#include<stdio.h>

void main(){
    int i,j,n,source,min=999,u,w;
    printf("enter the number of vertices:\n");
    scanf("%d", &n);

    int path[n+1], cost[n+1][n+1], visited[n+1], d[n+1];

    printf("enter the cost matrix:\n");
    for(i=1;i<=n; visited[i++]=0)
        for(j=1;j<=n;j++)
            scanf("%d", &cost[i][j]);

    printf("\nenter the source node:\n");
    scanf("%d", &source);

    for(i=1;i<=n;path[i++]=source){
        d[i]= cost[source][i];
    }
    visited[source]=1;
    d[source]=0;

    for(j=2;j<=n;j++, min=999){
        for(i=1;i<=n;i++){
            if(!visited[i] && d[i]<min)
                min= d[u=i];
        }
        visited[u]=1;

        for(w=1;w<=n;w++){
            if(!visited[w]){
                if(d[w]> cost[u][w]+d[u]){
                    d[w]=cost[u][w]+d[u];
                    path[w]=u;
                }
            }
        }
    }

    for(i=1;i<=n;i++){
        if(i!=source){
            printf("\nShortest path from %d to %d is %d\nShortest path= %d", source,i,d[i],i);
            j=i;
            do{
                printf("->%d", j=path[j]);
            }while(j!=source);
        }
    }
    printf("\n");
}
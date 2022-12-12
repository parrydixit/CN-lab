#include<stdio.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

void main(){
    int costmat[20][20];
    int nodes, count=0;

    printf("enter the number of nodes:");
    scanf("%d", &nodes);

    printf("enter cost matrix:\n");
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            scanf("%d", &costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }

    do{
       count=0;
       for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                for(int k=0;k<nodes;k++){
                    if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j]){
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }   
                }
            }
       } 
    }while(count!=0);

    for(int i=0;i<nodes;i++){
        printf("\nFor router %d:\n",i+1);
        for(int j=0;j<nodes;j++){
            printf("node %d via %d distance= %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    }
}
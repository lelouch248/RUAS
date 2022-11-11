#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int len,q,w,a,m,o,bred,n,i,j,k,l,nei;
    printf("Enter the no.of nodes: ");
    scanf("%d",&n);
    printf("Enter the length and bredth of the area seperated by spaces: ");
    scanf("%d %d",&len,&bred);
    int dist[n][n];
    int x[n],y[n];
    for (i=1,j=1;i<=n;i++,j++){
        x[i]=1+rand()%len;
        y[j]=1+rand()%bred;
        printf("node-%d(%d,%d) ",i,x[i],y[j]);
    }
    
    printf("\n");
    
    for (k=1;k<=n;k++){
        for (l=1;l<=n;l++){
            dist[k][l]=sqrt(pow((x[k]-x[l]),2)+pow((y[k]-y[l]),2));
        }
    }
    printf("\n");
    for (m=1;m<=n;m++){
        for (o=1;o<=n;o++){
            a=dist[m][o];
            printf("%3d",a);
        }
        printf("\n");
    }
    printf("Enter the distance that is considered as neighbours: ");
    scanf("%d",&nei);
        for (q=1;q<=n;q++){
            printf("Neighbors of node %d are: ",q);
            for (w=1;w<=n;w++){
                if ((q!=w) && (dist[q][w]<=nei)){
                    
                    printf("node-%d ",w);
                }
            }
            printf("\n");
        }
    
    return 0;
}

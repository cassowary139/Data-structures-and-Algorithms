/**
Consider a graph with vertices numbered 0 to N, where N is entered by the user. Every vertex stores an integer, 
which is also supplied by the user. A vertex i is connected to the vertices i-2, i+1, i+2, i+5 and i+10 (if the indices exist). **/
#include <stdio.h>
int main(void) {
    int arr[101][101];
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j==(i-2)||j==(i+1)||j==(i+5)||j==(i+2)||j==(i+10))
            arr[i][j]=arr[j][i]=1;
        }
    }
    printf("The Adjacency matrix is : \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

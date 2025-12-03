#include<stdio.h>
int main(){
    int i , j , x ;
    
    printf("donner x = ");
    scanf("%d",&x);
    
    int T[x][x];
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            printf("T[%d,%d] = ",i,j);
            scanf("%d",&T[i][j]);
        }
    }
    
    for(i=0;i<x;i++){
        printf("\n");
        for(j=0;j<x;j++){
            printf("%4d",T[i][j]);  
        }
    }
    
    int a ;     
    for(i=0;i<x;i++){
        for(j=1;j<x;j++){
            a = T[i][j];
            T[i][j] = T[j][i];
            T[j][i] = a;
        }
    }
    
    printf("\n");
    for(i=0;i<x;i++){
        printf("\n");
        for(j=0;j<x;j++){
            printf("%4d",T[i][j]);  
        }
    }
    return 0;
}

#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int max(int a,int b){
    int m;
    if(a>b){
        m = a ;
    }else{
        m = b ;
    }
    return m ;
}
int average(int a ){
    for(int i=a-1;i>1;i--){
        a=a*i;
    }
    return 0 ;
}
int main(){
    int a,b;
    printf("donner numero 1 = ");
    scanf("%d",&a);
    printf("donner numero 2 = ");
    scanf("%d",&b);
    printf("%d + %d = %d \n",a,b,add(a,b));
    printf("Max = %d \n",max(a,b));
    printf("average %d = %d \n",a,average(a));
    printf("average %d = %d \n",b,average(b));
}

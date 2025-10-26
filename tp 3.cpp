#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *LoadString(int N);
int StringLength(char *str);
void LoadArray(char *p, char arr[]);
void ReverseArray(char arr[], char rev[], int n);
void DisplayArray(char arr[], int n);
int SumStringASCII(char *p);
void ReverseString(char *start, char *end);

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();

    str = LoadString(n);
    int len = StringLength(str);
    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);
    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("\nReversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\nSum of ASCII values (recursive): %d", sum);

    ReverseString(str, str + len - 1);
    printf("\nString reversed recursively: %s\n", str);

    free(str);
    return 0;
}
char *LoadString(int n){
	char *str=(char*)malloc(n*sizeof(char));
	printf("Enter a string : ");
	fgets(str,n,stdin);
	return str;
}
int StringLength(char *str){
	int i=0 ;
	while(*str != '\0'){
	i++ ;
	str++ ;
	}
	return i ;
}
void LoadArray(char *p, char arr[]){
	int i = 0;
	while(p[i] != '\0'){
		arr[i] = p[i];
		i++;
	}
	arr[i] = '\0';
}
void ReverseArray(char arr[], char rev[], int n){
	for(int i=0;i<n;i++){
		rev[i] = arr[n-1-i] ;
	}
	rev[n]='\0';
}
void DisplayArray(char arr[], int n){
	for(int i=0;i<n;i++){
		printf("%c",arr[i]);
	}
}
int SumStringASCII(char *p){
	if(*p == '\0'){
		return 0 ;
	}else{
		return *p + SumStringASCII(p+1);
	}
}
void ReverseString(char *start, char *end){
	if(start >= end){
		return;
	}
	char x = *start;
	*start=*end;
	*end=x;
    ReverseString(start+1, end-1);
}

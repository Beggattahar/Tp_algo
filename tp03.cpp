#include<stdio.h>
#include<stdlib.h>
typedef struct Product{
	int ID ;
	char Nome[20];
	int Price;
}Product;

typedef struct Node{
	Product Prod ;
	struct Node* next ;
}Node;

Node* createList(){
	return NULL;
}
int empty(Node* head){
	if(head == NULL){
		return 0;
	}else{
	    return 1;
	}
}

void insertLast(Product x ,Node**head ){
	Node* list=(Node*)malloc(sizeof(Node));
	Node* tum = *head;
	list->Prod=x;
	if(*head==NULL){
		*head=list;
		list->next=list;
		return;
	}
	while(tum->next != *head){
		tum = tum->next;
	}
	tum->next = list ;
	list->next = *head ;
}
void insertFirst(Product x ,Node**head ){
	Node* list=(Node*)malloc(sizeof(Node));
	Node* tum = *head;
	list->Prod=x;
	if(*head==NULL){
		*head=list;
		list->next=list;
		return;
	}
	while(tum->next != *head){
		tum = tum->next;
	}
	list->next = *head ;
	*head = list ;
	tum->next = list ;
}
void display(Node* head){
	if(head == NULL){
	    printf("List is empty \n");
    	return;
    }
	Node *tum = head ;
	do{
		printf("ID = %d ; Name = %s ; Price = %d \n",tum->Prod.ID,tum->Prod.Nome,tum->Prod.Price);
		tum = tum->next;
	}while(tum != head);
}

int main(){
	Node*head = NULL ;
	Product P1={1,"Milk",450};
	Product P2={2,"Eggs",600};
	Product P3={3,"Sugar",90};
	Product P4={4,"Tomato",300};
	
	insertLast(P1, &head);
	insertFirst(P4, &head);
	insertLast(P2, &head);
	insertFirst(P3, &head);
	
	display(head);
	
}

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
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

bool empty(Node* head){
	if(head == NULL){
		return true;
	}else{
	    return false;
	}
}

Node *insertLast(Product x ,Node *head ){
	Node* list=(Node*)malloc(sizeof(Node));
	Node* tum = head;
	list->Prod=x;
	if(head==NULL){
		head=list;
		list->next=list;
		return head;
	}
	while(tum->next != head){
		tum = tum->next;
	}
	tum->next = list ;
	list->next = head ;
    return head;
}
Node *insertFirst(Product x ,Node*head ){
	Node* list=(Node*)malloc(sizeof(Node));
	Node* tum = head;
	list->Prod=x;
	if(head==NULL){
		head=list;
		list->next=list;
		return head;
	}
	while(tum->next != head){
		tum = tum->next;
	}
	list->next = head ;
	head = list ;
	tum->next = list ;
    return head;
}
void printList(Node* head){
	if(head == NULL){
	    printf("List is empty \n");
    	return;
    }
    Node *tum = head;
    do{
        printf("ID = %d ; Name = %s ; Price = %d\n",tum->Prod.ID, tum->Prod.Nome, tum->Prod.Price);
        tum = tum->next;
    }while(tum != head);
}

int main(){
	Node*head = NULL ;
	
	if(empty(head)){
		printf("List is empty \n");
	}else{
		printf("List is not empty \n");
	}
	
	Product P1={1,"Milk",450};
	Product P2={2,"Eggs",600};
	Product P3={3,"Sugar",90};
	Product P4={4,"Tomato",300};
	
	head=insertLast(P1,head);
	head=insertFirst(P4,head);
	head=insertLast(P2,head);
	head=insertFirst(P3,head);


	printList(head);
	
	if(empty(head)){
		printf("List is empty \n");
	}else{
		printf("List is not empty \n");
	}
	return 0;
}
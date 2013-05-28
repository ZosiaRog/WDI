#include<stdlib.h>
#include<stdio.h>
typedef int typ;

typedef struct Lista{
			typ key;
			struct Lista* next;
			struct Lista* back;
			} Lista;

Lista* create(typ key){
		Lista* nowa;
		nowa = malloc(sizeof(typ));
		nowa->key = key;
		nowa->next = NULL;
		nowa->back = NULL;		
		return nowa;		
}

void insertAfter(Lista* top, typ key){
	if(top == NULL) {
		printf("error !\n");
	} else {
		Lista* nowy;
		nowy = create(key);
		nowy -> back = top;
		nowy -> next = top -> next;
		nowy -> next -> back = nowy;
		top -> next = nowy;
	}
}
void insertBefore(Lista *top, typ key){
	if(top == NULL) {
		printf("error !\n");
	} else {
		Lista* nowy;
		nowy = create(key);
		nowy -> next = top -> next;
		nowy -> back = top;
		top -> next -> back = nowy;
		top -> next = nowy;
	}
}
Lista* usun(Lista* top){
	if(top==NULL){
		printf("error !\n");
		return NULL;
	} else {
		top -> back -> next = top -> next;
		return start;
	}
}	

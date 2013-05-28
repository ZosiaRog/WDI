#include<stdlib.h>
#include<stdio.h>
typedef int typ;

typedef struct Lista{
			typ key;
			struct Lista* next;
			} Lista;

Lista* create(typ klucz){
		Lista* nowa;
		nowa = malloc(sizeof(typ));
		nowa->key = klucz;
		nowa->next = NULL;		
		return nowa;		
}

void insertAfter(Lista* top, typ key){
	if(top == NULL) {
		printf("error !\n");
	} else {
		Lista* nowy;
		nowy = create(key);
		nowy -> next = top -> next;
		top -> next = nowy;
	}
}

Lista* usunPierwszy(Lista* top){
	if(top==NULL){
		printf("error !\n");
		return NULL;
	} else {
		Lista* start;
		start = top -> next;
		free(start);
		return start;
	}
}	
	
Lista* znajdzElement(Lista* top, int k){
	while(k>1){
		top = top->next;
		k--;
	}
}

int main(){
	int a, n;
	a = 2;
	Lista* lista;
	scanf("%d",&n);
	lista = create(n);
	while(a>0){
		scanf("%d",&n);
		insertAfter(lista, n);
		a--;
	}
	
		printf("\n     %d \n", lista->key);
return 0;
}




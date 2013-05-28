#include<stdlib.h>
#include<stdio.h>

typedef struct ListEl{
			int key;
			struct ListEl *prev;
			struct ListEl *next;
			} ListEl;

typedef ListEl *List;

ListEl* create(int klucz){
		ListEl *nowa;
		nowa = malloc(sizeof(int));
		nowa->key = klucz;
		nowa->next = NULL;
		nowa->prev = NULL;		
		return nowa;		
		}


void Wstaw(List* pL, int klucz){
	if(pL == NULL) {
		printf("error - Lista pusta!\n");
	} else {
		List lista = *pL;
		ListEl *nowy;
		nowy = create(klucz);
		nowy->next = lista;
		nowy->prev = lista->prev;
		if(lista->prev!=NULL){
			lista->prev->next = nowy;
		}
		lista->prev = nowy;
		*pL = nowy;
	}
}

void Usun(List *ppL){
	List pL = *ppL;
	if(pL==NULL){
		printf("error - Lista pusta!\n");
	} else {
		if(pL->prev != NULL){
			pL->prev->next = pL->next;
		}
		if(pL->next!=NULL){
			pL->next->prev = pL->prev;		
		}
		*ppL = pL->next;
		free(pL);	
	}	
}
void NaLewo(List *pL){
	List lista = *pL;
	if(lista->prev ==NULL){
		printf("error - Podałeś pierwszy element listy!\n");
	} else {
		*pL = lista->prev;
	}
}

void NaPrawo(List *pL){
	List lista = *pL;
	if(lista->next ==NULL){
		printf("error - Podałeś ostatni element listy!\n");
	} else {
		*pL = lista->next;
	}
}

void Wyswietl(List *ppL){
	List pL = *ppL;
	List temp;
	temp = pL;
	while(temp->prev != NULL){
		temp = temp->prev;
	}
	while(temp != pL){
		printf("%d ", temp->key);
		temp = temp->next;
	}
	printf("[ %d ] ", temp->key);
	temp = temp->next;
	while(temp != NULL){
		printf("%d ", temp->key);
		temp = temp->next;
	}
	printf("\n");
}

List Wczytaj(){
	int m, n;
	List lista;
	scanf("%d %d", &m, &n);
	lista = create(n);
	m--;
	while(m-->0){
		scanf("%d",&n);
		Wstaw(&lista, n);
	}	
	return lista;
}

int main(){
	List moja;
	moja = Wczytaj();
	
	NaPrawo(&moja);	
	Wyswietl(&moja);
	Usun(&moja);
	Wyswietl(&moja);
	NaLewo(&moja);
	Wyswietl(&moja);
	return 0;
}

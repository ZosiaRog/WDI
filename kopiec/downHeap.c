#include<stdlib.h>
#include "downHeap.h"
#include<stdio.h>

int size;
int Heap[MAX];
int lewy(int i){
	return 2*i+1;
}
int prawy(int i){
	return 2*i+2;
}

void downHeap(int i, int size){
	int x, y;
	y = i;
	if (prawy(i) < size){
		if(Heap[prawy(i)] > Heap[lewy(i)]){
			y = prawy(i);
		} else {
			y = lewy(i);
		}
	} else if (lewy(i)+1==size){
			y=lewy(i);	
	}
	
	if(Heap[i] < Heap[y]){
		x = Heap[y];
		Heap[y] = Heap[i];
		Heap[i] = x;
		downHeap(y, size);
	}
}

int main(){
	
	int i, j, a, w;
	scanf("%d", &size);
	
	//wczytywanie
	for(i=0; i<size; i++){
		scanf("%d",&a);
		Heap[i]=a;
	}
	//kopcowanie
	for(i=size/2; i>=0; i--){
		downHeap(i, size);
	}
	//wypisywanie
	for(i=0; i<size; i++){
		printf("%d  ", Heap[i]);
	}
	printf("\n");
	
	//sortowanie
	int x;
		for(j=size; j>0; j--){
		x = Heap[j-1];
		Heap[j-1] = Heap[0];
		Heap[0] = x;
		downHeap(0,j-1);	
	}
	//wypisywanie
	for(i=0; i<size; i++){
		printf("%d  ", Heap[i]);
	}		
	printf("\n");
	return 0;
}




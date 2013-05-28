#include<stdlib.h>
#include<stdio.h>
#define MAX 1000

int size;
int Heap[MAX];
int parent(int i){
	return (i-1)/2;
	}
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

void upHeap(int i){
	int x;
	if (i!=0 && (Heap[parent(i)] < Heap[i])){
		x = Heap[parent(i)];
		Heap[parent(i)] = Heap[i];
		Heap[i] = x;
		printf("rodzic %d ", parent(i));
		upHeap(parent(i));
	}
}

void kopcuj(int size){
	int i;
	for(i=size/2; i>=0; i--){
		downHeap(i, size);
	}
}

void wczytaj(){
	int i, a;
	scanf("%d", &size);

	for(i=0; i<size; i++){
		scanf("%d",&a);
		Heap[i]=a;
	}
}

void wypisz(int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d  ", Heap[i]);
	}
	printf("\n");
}
void sortuj(size){
	int x, j;
	for(j=size; j>0; j--){
		x = Heap[j-1];
		Heap[j-1] = Heap[0];
		Heap[0] = x;
		downHeap(0,j-1);	
	}
}
void Heapsort(size){
	kopcuj(size);
	sortuj(size);
}



int main(){
	wczytaj();
	wypisz(size);
	kopcuj(size);
	wypisz(size);
	Heap[8]=100;
	upHeap(8);
	wypisz(size);
	
return 0;
}










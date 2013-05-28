#include<stdio.h>
#include<stdlib.h>
#define MAXS 1000

static int *queue;
static int alfa;
static int omega;
int Heap[MAXS];
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

void upHeap(int i, int *Heap){
	int x;
	if (i!=0 && (Heap[parent(i)] < Heap[i])){
		x = Heap[parent(i)];
		Heap[parent(i)] = Heap[i];
		Heap[i] = x;
	//	printf("rodzic %d ", parent(i));
		upHeap(parent(i), Heap);
	}
}

//kolejka priorytetowa
void init(){
	queue = malloc(MAXS*sizeof(int));
	omega = 0;
}

void insert(int element, int *queue){
	queue[omega] = element;
	upHeap(omega, queue);
	omega++;
//	printf("q = %d o = %d\n", queue[omega-1], omega);
}

int extractMax(omega){
	if(omega == 0){
		printf("kolejka jest pusta \n");
	} else {
		int x;
		x = queue[0];
		queue[0] = queue[omega-1];
		return x;
	}
}

void increaseKey(int old, int newkey, int *queue){
	if(newkey < queue[old]){
		printf("podaj większy klucz");
	} else {
		queue[old] = newkey;
		upHeap(old, queue);
	}
}
int maximum(){
	return queue[0];
}

int isEmpty(){
	return (omega==0);
}

int isFull(){
	return (omega==MAXS-1);
}

int main(){
	init();
	
	int i, newkey, key;
	for(i=0; i<9; i++){
	scanf("%d", &newkey);
	insert(newkey, queue);
	}
	key = extractMax(omega);
	printf("%d ", key);
return 0;
}


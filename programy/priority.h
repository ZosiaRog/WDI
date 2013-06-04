#include<stdio.h>
#include<stdlib.h>
#define MAXS 1000000

static int *queue;
static int alfa;
static int omega;
int Heap[MAXS];
int parent(int i);
int lewy(int i);
int prawy(int i);

void downHeap(int i, int size);
void upHeap(int i, int *Heap);

//kolejka priorytetowa
void init()
void insert(int element, int *queue);
int extractMax(omega);
void increaseKey(int old, int newkey, int *queue);
int maximum();
int isEmpty();
int isFull();



#include "queue.h"
#include<stdlib.h>

static ElType *queue;
static int alfa;
static int omega;

void init(){
	queue = malloc(MAXS*sizeof(ElType));
	alfa = 0;
	omega = -1;
}

void enqueue(ElType element){
	queue[omega+1] = element;
	omega++;
}

ElType dequeue(){
	return queue[alfa++];
}

int isEmpty(){
	return (omega-alfa==-1);
}

int isFull(){
	return (omega==MAXS);
}

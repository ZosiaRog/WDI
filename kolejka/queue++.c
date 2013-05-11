#include "queue.h"
#include<stdlib.h>
#include<stdio.h>

static ElType *queue;
static int alfa;
static int omega;
static int size;

void init(){
	queue = malloc(MAXS*sizeof(ElType));
	alfa = 0;
	omega = -1;
	size = 0;
}

void enqueue(ElType element){
	omega++;
	if(omega==MAXS){
		omega=0;
	}
	queue[omega] = element;
	size++;
}

ElType dequeue(){
	int starealfa = alfa;
	if(alfa==MAXS-1){
		alfa=0;
	} else {
		alfa++;
	}
	size --;
	return queue[starealfa];
}

int isEmpty(){
	return (size==0);
}
int isFull(){
	printf("size = %d\n", size);
	return (size==MAXS);
}

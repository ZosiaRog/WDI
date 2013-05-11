#include "stack.h"
#include<stdlib.h>

static ElType *stack;
static int count;

void init(){
	stack = malloc(MAXS*sizeof(ElType));
	count = 0;
}

void push(ElType element){
	stack[count] = element;
	count++;
}

ElType pop(){
	count--;
	return stack[count];
}

int isEmpty(){
	return (count==0);
}

int isFull(){
	return (count==MAXS);
}




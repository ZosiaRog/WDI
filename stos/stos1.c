#include<stdio.h>

int stack[1000111];
int count;

void init(){
	count = 0;
}

void push(int element){
	stack[count] = element;
	count++;
}

int pop(){
	count--;
	return stack[count];
}

int isEmpty(){
	return (count==0);
}


int main(){
	
	int n, i, a;
	scanf("%d",&n);
	
	init();
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a!=-1){
			push(a);
		} else {
			if(isEmpty()){
				printf("pusty\n");
			} else {
				printf("%d\n", pop());
			}
		}
	}
	return 0;
}


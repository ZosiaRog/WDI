#include<stdio.h>
#include "queue.h"

int main(){
	
	int n, i;
	ElType a;
	scanf("%d",&n);
	
	init();
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a!=-1){
			if(isFull()){
				printf("kolejka jest pełna\n");
			} else {			
				enqueue(a);
	            printf("wrzucam %d\n", a);
			}	
		} else {
			if(isEmpty()){
				printf("kolejka jest pusta\n");
			} else {
				printf("%d\n", dequeue());
			}
		}
	}
	return 0;
}


#include<stdio.h>
#include "stack.h"

int main(){
	
	int n, i;
	ElType a;
	scanf("%d",&n);
	
	init();
	
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		if(a!=-1){
			push(a);
		} else {
			if(isEmpty()){
				printf("pusty\n");
			} else {
				printf("%lld\n", pop());
			}
		}
	}
	return 0;
}


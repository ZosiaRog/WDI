#include<stdio.h>
#include<stdlib.h>
#include "downHeap.h"

int main(){
	
	int n, i, a, w, tab[MAX];
	scanf("%d %d", &n, &w);
	
	for(i=0; i<n; i++){
		scanf("%d",&a);
		tab[i]=a;
	}
	downHeap(w);
	
	for(i=0; i<n; i++){
		printf("tab[i]");
	}
	printf("\n");
	return 0;
}


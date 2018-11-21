#include <stdio.h>
#include "deque.h"

void main(){
	deque_t *d = deque_alloc();
	if(d==NULL){
		printf("alloc fail\n");
		return;
	}
	deque_push_back_limit(d, "a");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "b");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "c");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "d");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "e");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "f");
	printf("d->size = %d\n",d->size);
	deque_push_back_limit(d, "g");
	printf("d->size = %d\n",d->size);
	foreach(d->head);
	for(int i = 1;i < 9;i++){
		char val[128] = {0};
		deque_pop_back_limit(d, val);
		printf("%d pop val = %s\n", i, val);
	}
}

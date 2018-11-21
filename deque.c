#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

#define DEQUE_SIZE 5

deque_t *deque_alloc(){
	deque_t *d  = malloc(sizeof(deque_t));
	if(d != NULL)
		d->head = d->tail = NULL;
	return d;
}

void *deque_delete(deque_t *d){
	free(d);
}

bool deque_is_empty(deque_t *d){
	return d->head == NULL;
}

void deque_push_front(deque_t *d, char *val){
	struct node_t *n = (struct node_t*)malloc(sizeof(struct node_t));
	assert(n!=NULL);
	strcpy(n->msg,val);
	n->next = d->head;
	n->prev = NULL;
	if(d->tail == NULL){
		d->head = d->tail = n;
	}else{
		d->head->prev = n;
		d->head = n;
	}
	d->size++;
}

void deque_push_back(deque_t *d, char *val){
	struct node_t *n = malloc(sizeof(struct node_t));
	assert(n!=NULL);
	strcpy(n->msg, val);
	n->prev = d->tail;
	n->next = NULL;
	if(d->head == NULL){
		d->head = d->tail = n;
	}else{
		d->tail->next = n;
		d->tail = n;
	}
	d->size++;
}

void deque_pop_front(deque_t *d, char *val){
	strcpy(val, d->head->msg);
	struct node_t *n = d->head;
	if(d->head == d->tail){
		d->head = d->tail = NULL;
	}else{
		n->next->prev = NULL;
		d->head = n->next;
	}
	free(n);
	d->size--;
}

void deque_pop_back(deque_t *d, char *val){
	strcpy(val, d->tail->msg);
	struct node_t *n = d->tail;	
	if(d->head == d->tail){
		d->head = d->tail = NULL;
	}else{
		n->prev->next = NULL;
		d->tail = n->prev;
	}
	free(n);
	d->size--;
}

void deque_push_front_limit(deque_t *d, char *val){
	char tmp[128];
	if(d->size > DEQUE_SIZE - 1)
		deque_pop_back(d, tmp);
	deque_push_front(d, val);
}

void deque_push_back_limit(deque_t *d, char *val){
	char tmp[128];
	if(d->size > DEQUE_SIZE - 1)
		deque_pop_front(d, tmp);
	deque_push_back(d, val);
}

void deque_pop_front_limit(deque_t *d, char *val){
	if(d->size <= 1)
		return;
	deque_pop_front(d, val);
}

void deque_pop_back_limit(deque_t *d, char *val){
	if(d->size <= 1)
		return;
	deque_pop_back(d, val);
}

void foreach(struct node_t *n){
	while(n != NULL){
		printf("%s\n", n->msg);
		n = n->next;
	}
}

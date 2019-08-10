#include <stdio.h>
#include <stdlib.h>

// queue by array

int* head = NULL;
int len = 0;
int size = 0;

int* ph = NULL;
int* pt = NULL;

int create_queue(int sz){
	pt = ph = head = (int*)malloc(sizeof(int) * sz);
	if(head == NULL){
		printf("malloc queue err\n");
		return -1;
	}
	len = 0;
	size = sz;
	return 0;
}

int enqueue(int val){
	if(ph == head+size)
		ph = head;
	if(pt == head+size)
		pt = head;

	if(len == size){
		printf("queue is full\n");
		return -1;
	}

	*pt = val;
	pt++;
	len++;
	return 0;
}

int dequeue(){
	int rc = 0;

	if(ph == head+size)
		ph = head;
	if(pt == head+size)
		pt = head;

	if(len == 0){
		printf("queue is empty\n");
		return -1;
	}

	rc = *ph;
	ph++;
	len--;

	return rc;
}

void display(){
	if(len == 0) return;
	int i = 0;
	int *p = ph;
	for(i=0; i<len; i++){
		if(p == head+size)
			p = head;
		printf("[%d]", *p);
		p++;
	}
	printf("\n");
}

void destory(){
	free(head);
	printf("free(head)\n");
	head = pt = ph = NULL;
	size = len = 0;
}

void main(){
	int rc = -1;
	create_queue(10);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	display();
	rc = dequeue();
	printf("rc: %d\n", rc);
	display();
	destory();
}

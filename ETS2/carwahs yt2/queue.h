#ifndef queue_H
#define queue_H

#include <stdio.h>
#include <conio.h>
#define MAX 20

typedef struct queue{
	int mobil[MAX];
	int head;
	int tail;
} queue;

int isfull(queue Q);
int isempty(queue Q);
void sethead(queue *Q,int fn);
void settali(queue *Q,int fn);
void Delete(queue *Q,int *vmobil);
void initial(queue *Q);
void insert(queue *Q,int vmobil);
void reset(queue *Q);

#endif

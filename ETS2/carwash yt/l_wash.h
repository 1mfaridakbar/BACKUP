#ifndef l_wash_H
#define l_wash_H

#include <stdio.h>
#include <conio.h>
#define MAX 20

typedef struct{
	int mobil[MAX];
	int head;
	int tail;
} list;

int isfull(list L);
int isempty(list L);
void sethead(list *L,int fn);
void settali(list *L,int fn);
void Delete(list *L,int *vmobil);
void initial(list *L);
void insert(list *L,int vmobil);
void reset(list *L);

#endif

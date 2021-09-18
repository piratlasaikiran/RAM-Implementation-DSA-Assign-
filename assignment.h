#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>



extern int a,i,j;
extern int *arr;
extern int *listhead;
extern int listcount;
extern int freehead;

void intilize();
void countelements(int list_num);
void countallnodes();
void deleteelement(int listno, int element);
void printfreelist(int head);
void insertelement(int listnum, int value);
void printalllists();
void createlist(int value);
void defrag();
#endif

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <stdio.h>
typedef struct Node{
    int Power;
    int Coefficient;
    struct Node *next;
}Node,*Polynomial;

Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial Mult(Polynomial P1,Polynomial P2);
void Attach(int c,int e,Polynomial *pRear);

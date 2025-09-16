#include "stdio.h"
#include "stdlib.h"

#define MAX 4

typedef struct
{
    int elem;
    int next;
} cell, heapSpace[MAX];

typedef struct
{
    heapSpace h;
    int avail;
} vHeap;

typedef int List;

void initialize(vHeap *v)
{
    for (int i = 0; i < MAX; i++)
    {
        v->h[i].elem = -1;
        v->h[i].next = i + 1;
        if (i == MAX - 1)
        {
            v->h[i].elem = -1;
        }
    }
    v->avail = 0;
}

int allocSpace(vHeap *v)
{
    int returnVal = -1;
    if (v->avail == -1)
    {
        return returnVal;
    }
    returnVal = 0;
    while (v->h[returnVal].elem != -1)
    {
        returnVal++;
    }
    v->avail = returnVal + 1;
    return returnVal;
}

void deallocSpace(vHeap *v, int index)
{
    int i = 0;
    while (i != index)
    {
        i++;
    }
    v->h[i].next = v->avail;
    v->avail = index;
}

void insertFirst(int *L, vHeap *v, int elem)
{
    int check = -1;
    check = allocSpace(v);
    if (check == -1)
    {
        printf("something went wrong");
        return;
    }
    v->h[check].elem = elem;
    v->h[check].next = *L;
    *L = check;
}

void insertLast(int *L, vHeap *v, int elem)
{
    int check = -1, i = 0;
    check = allocSpace(v);
    if (check == -1)
    {
        printf("something went wrong");
        return;
    }
    while (v->h[i].next != -1)
    {
        i++;
    }
    v->h[i].next = check;
    v->h[check].elem = elem;
    v->h[check].next = -1;
}

void delete(int *L, vHeap *v, int elem)
{
    int i = 0;
    while (v->h[i].elem != elem)
    {
        i++;
    }
    v->h[i - 1].next = v->h[i].next;
    v->h[i].elem = -1;
}

void display(int *L, vHeap *v)
{
    int i = *L;
    while (v->h[i].next != -1)
    {
        printf("ELEMENT : %d || NEXT : %d\n", v->h[i].elem, v->h[i].next);
        i = v->h[i].next;
    }
}

void main()
{
    vHeap *vHeapNew;
    int *L;
    *L = -1;
    initialize(vHeapNew);
    insertFirst(L, vHeapNew, 1);
    insertFirst(L, vHeapNew, 2);
    insertFirst(L, vHeapNew, 3);
    insertFirst(L, vHeapNew, 4);
    insertFirst(L, vHeapNew, 5);
    insertFirst(L, vHeapNew, 6);
    insertFirst(L, vHeapNew, 7);
    insertFirst(L, vHeapNew, 8);
    insertLast(L, vHeapNew, 9);
    delete(L, vHeapNew, 7);
    display(L, vHeapNew);
}

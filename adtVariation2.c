#include "stdio.h"
#include "stdlib.h"

#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} list;

list* thingy;

void initialize(list* x)
{
    x->count = 0;
}

void insertPos(list* x, int data, int pos)
{
    if (x->count > MAX - 1)
    {
        printf("error");
        return;
    }
    if (pos > x->count || pos < 0)
    {
        printf("error");
        return;
    }
    for(int i = count; i > pos; i--)
    {
        x->elem[i] = x->elem[i - 1];
    }
    x->elem[pos] = data;
    x->count++;
}

void deletePos(list* x, int pos)
{
    if (pos > x->count || pos < 0)
    {
        printf("error");
        return;
    }
    for(int i = pos; i < x->count - 1; i++)
    {
        x->elem[i] = x->elem[i + 1];
    }
    x->count--;
}

int locate (list* x, int data)
{
    int returnVal = -1;
    for(int i = 0; i != x->count; i++)
    {
        if (x->elem[i] == data)
        {
            returnVal = i;
            break;
        }
    }
    return returnVal;
}

void insertSorted (list* x, int data)
{
    int pos = 0;
    if (x->count > MAX - 1)
    {
        printf("error");
        return;
    }
    for(int i = 0; i < x->count; i++)
    {
        if (x->elem[i] < data)
        {
            pos = i;
        }
    }
    for(int i = count; i > pos; i--)
    {
        x->elem[i] = x->elem[i - 1];
    }
    x->elem[pos] = data;
    x->count++;
}

void display(list* x)
{
    for(int i = 0; i < x->count; i++)
    {
        printf("index %d: %d\n", i, x->elem[i]);
    }
}

void makeNULL(list* x)
{
    free(x);
}

int main()
{
    int located = 0;
    thingy = (list*)malloc(sizeof(list));
    initialize(thingy);
    display(thingy);
    insertPos(thingy, 1, 0);
    insertPos(thingy, 2, 1);
    insertPos(thingy, 3, 1);
    insertPos(thingy, 4, 1);
    insertSorted(thingy, 3);
    insertSorted(thingy, 5);
    insertSorted(thingy, 7);
    display(thingy);
    deletePos(thingy, 1);
    locate(thingy, 9);
    display(thingy);
    printf("position:%d", located);
}



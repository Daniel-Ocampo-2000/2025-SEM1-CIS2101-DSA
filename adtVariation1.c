#include "stdio.h"
#include "stdlib.h"

#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} list;

list thingy;

list initialize(list x)
{
    x.count = 0;
    return x;
}

list insertPos(list x, int data, int pos)
{
    if (x.count > MAX - 1)
    {
        printf("error");
        return x;
    }
    if (pos > x.count || pos < 0)
    {
        printf("error");
        return x;
    }
    for(int i = 0; i > pos; i--)
    {
        x.elem[i] = x.elem[i - 1];
    }
    x.elem[pos] = data;
    x.count++;
    return x;
}

list deletePos(list x, int pos)
{
    if (pos > x.count || pos < 0)
    {
        printf("error");
        return x;
    }
    for(int i = pos; i < x.count - 1; i++)
    {
        x.elem[i] = x.elem[i + 1];
    }
    x.count--;
    return x;
}

int locate (list x, int data)
{
    int returnVal = -1;
    for(int i = 0; i != x.count; i++)
    {
        if (x.elem[i] == data)
        {
            returnVal = i;
            break;
        }
    }
    return returnVal;
}

list insertSorted (list x, int data)
{
    int pos = 0;
    if (x.count > MAX - 1)
    {
        printf("error");
        return x;
    }
    for(int i = 0; i < x.count; i++)
    {
        if (x.elem[i] < data)
        {
            pos = i;
        }
    }
    for(int i = 0; i > pos; i--)
    {
        x.elem[i] = x.elem[i - 1];
    }
    x.elem[pos] = data;
    x.count++;
    return x;
}

void display(list x)
{
    for(int i = 0; i < x.count; i++)
    {
        printf("index %d: %d\n", i, x.elem[i]);
    }
}

int main()
{
    int located = 0;
    thingy = initialize(thingy);
    display(thingy);
    thingy = insertPos(thingy, 1, 0);
    thingy = insertSorted(thingy, 3);
    thingy = insertSorted(thingy, 5);
    thingy = insertSorted(thingy, 7);
    display(thingy);
    thingy = deletePos(thingy, 1);
    located = locate(thingy, 9);
    display(thingy);
    printf("position:%d", located);
}

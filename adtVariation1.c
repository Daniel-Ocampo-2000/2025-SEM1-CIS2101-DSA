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
    int dataTemp = 0, dataTemp2 = 0;
    if (x.count++ >= MAX)
    {
        printf("error");
        return -1;
    }
    if (pos > x.count)
    {
        printf("error");
        return -1;
    }
    for(int i = 0; i != x.count; i++)
    {
        int j = i++;
        if (i == pos)
        {
            dataTemp = x.elem[i];
            x.elem[i] = data;
        }
        if (i > pos)
        {
            dataTemp2 = x.elem[i];
            x.elem[i] = dataTemp;
            dataTemp = x.elem[j];
        }
    }
    x.count++;
    return x;
}

list deletePos(list x, int pos)
{
    int dataTemp = 0, dataTemp2 = 0;
    if (pos > x.count)
    {
        printf("error");
        return -1;
    }
    for(int i = 0; i != x.count; i++)
    {
        int j = i++;
        if (i == pos)
        {
            x.elem[i] == dataTemp;
        }
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
    int dataTemp = 0, dataTemp2 = 0;
    if (x.count++ >= MAX)
    {
        printf("error");
        return -1;
    }
    for(int i = 0; i != x.count; i++)
    {
        if (data >= x.elem[i])
        {
            dataTemp = x.elem[i];
            x.elem[i] = data;
        }
        if (i > pos)
        {
            x.elem[i] = dataTemp;
        }
    }
    x.count++;
    return x;
}

void display(list x)
{
    for(int i = 0; i != x.count; i++)
    {
        printf("%d\n", x.elem[i]);
    }
}

int main()
{
    int located = 0;
    thingy = initialize(thingy);
    display(thingy);
    thingy = insertPos(thingy, 7, 0);
    thingy = insertSorted(thingy, 9);
    display(thingy);
    thingy = deletePos(thingy, 1);
    located = locate(thingy, 9);
    display(thingy);
}
#include "stdio.h"
#include "stdlib.h"

#define LENGTH 10

typedef struct
{
    int *elem;
    int count;
	int max;
} list;

list thingy;

list initialize(list x)
{
	x.elem = malloc(sizeof(int)*LENGTH);
    x.count = 0;
	x.max = LENGTH;
	return x;
}

list insertPos(list x, int data, int pos)
{
	if (x.count > x.max - 1)
	{
		printf("error");
		return;
	}
	if (pos > x.count || pos > x.max || pos < 0)
	{
		printf("error");
		return;
	}
	for(int i = count; i > pos; i--)
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
		return;
	}
	for(int i = pos; i < x.count; i++)
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
        return;
    }
    for(int i = 0; i < x.count; i++)
    {
        if (x.elem[i] < data)
        {
            pos = i;
        }
    }
    for(int i = count; i > pos; i--)
    {
        x.elem[i] = x.elem[i - 1];
    }
    x.elem[pos] = data;
    x.count++;
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
    thingy = (list*)malloc(sizeof(list));
    list = initialize(thingy);
    display(thingy);
    list = insertPos(thingy, 1, 0);
    list = insertPos(thingy, 2, 1);
    list = insertPos(thingy, 3, 1);
    list = insertPos(thingy, 4, 1);
    list = insertSorted(thingy, 3);
    list = insertSorted(thingy, 5);
    list = insertSorted(thingy, 7);
    display(thingy);
    list = deletePos(thingy, 1);
    located = locate(thingy, 9);
    display(thingy);
    printf("position:%d", located);
}

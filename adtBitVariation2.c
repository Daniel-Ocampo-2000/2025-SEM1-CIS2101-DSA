#include "stdio.h"

#define MAX 8

typedef struct
{
	unsigned int field : MAX;
}set;

void initialize(set *set)
{
	set->field = 0;
}

void insert(set *set, int element)
{
	if (element > MAX - 1)
	{
		return;
	}
	unsigned int mask : MAX;
	mask = 1;
	mask << element;
	set->field = set->field | mask;
}

void delete(set *set, int element)
{
	if (element > MAX - 1)
	{
		return;
	}
	unsigned int mask : MAX;
	mask = 1;
	mask << element;
	set->field = set->field & ~mask;
}

bool find(set set, int element)
{
	return (set->field << element) & 1;
}

void union(set a, set b, set c)
{
	c = a | b;
}
void intersection(set a, set b, set c)
{
	c = a & b;
}
void difference(set a, set b, set c)
{
	c = a & ~b;
}

void display(set set)
{
	for (int i = 0; i < MAX; i++)
	{
		if (set->field & 1)
		{
			printf("%d ", i);
		}
	}
}

int main()
{
	
}

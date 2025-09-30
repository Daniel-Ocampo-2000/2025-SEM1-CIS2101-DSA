#include "stdio.h"

#define MAX 8

typedef bool set[MAX];

void initialize(set set)
{
	for (int i = 0; i < MAX; i++)
	{
		set[i] = 0;
	}
}

void insert(set set, int element)
{
	if (element > MAX - 1)
	{
		return;
	}
	set[element] = 1;
}

void delete(set *set, int element)
{
	if (element > MAX - 1)
	{
		return;
	}
	set[element] = 0;
}

bool find(set set, int element)
{
	if (set[element])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void union(set a, set b, set c)
{
	for (int i = 0; i < MAX; i++)
	{
		if (a[i] || b[i])
		{
			c[i] = 1;
		}
	}
}
void intersection(set a, set b, set c)
{
	for (int i = 0; i < MAX; i++)
	{
		if (a[i] && b[i])
		{
			c[i] = 1;
		}
	}
}
void difference(set a, set b, set c)
{
	for (int i = 0; i < MAX; i++)
	{
		if (a[i] && ~b[i])
		{
			c[i] = 1;
		}
	}
}

void display(set set)
{
	for (int i = 0; i < MAX; i++)
	{
		if (set[i])
		{
			printf("%d ", i);
		}
	}
}

int main()
{
	
}

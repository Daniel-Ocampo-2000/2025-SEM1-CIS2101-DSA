#include "stdio.h"
#include "stdlib.h"

#define LENGTH 10

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct
{
    node *head;
    int count;
} list;

struct node* create(int x)
{
    node* nodeNew = (struct node*)malloc(sizeof(struct node));
    nodeNew->data = x;
    nodeNew->next = NULL;
}

void insertFirst(list *list, int x)
{
    node* nodeNew = create(x);
    nodeNew->next = list->*head;
    list->*head = nodeNew;
    list->count++;
}

void insertLast(list *list, int x)
{
    node* nodeNew = create(x);
    if (list->*head == NULL)
    {
        list->*head = nodeNew;
        return 1;
    }
    while (list->*head != NULL)
    {
        list->head = list->head->next;
    }
    list->*head = nodeNew;
    list->count++;
}

void insertPos(list *list, int x, int pos)
{
    node* nodeNew = create(x);
    node *current = list->head;

}

int retrieve(list *list, int x)
{
    int returnVal = -1;
    if (x > list->count)
    {
        printf("nah");
        return returnVal;
    }
    node *current = list->*head;
    for (int i = 0; i < x; i++)
    {
        current = current->next;
    }
    returnVal = current->data;
    return returnVal;
}

int locate(list *list, int x)
{
    int returnVal = -1;
    if (list->head == NULL)
    {
        return returnVal;
    }
    node *current = list->*head;
    for (int i = 0; current != NULL; i++)
    {
        if (current == x)
        {
            return i;
        }
        else
        {
            current = current->next;
        }
    }
}

void display(list *list)
{
    int count = 0;
    if (list->head == NULL)
    {
        printf("list empty");
        return;
    }
    while (list->head != NULL)
    {
        printf("node # %d : %d", count, list->head->data);
        printf("\n");
        count++;
        list->head = list->head->next;
    }
}

list initialize(list *list)
{
    for (int i = 0; i < LENGTH; i++)
    {
        node *current = list->*head;
        current->data =  -1;
        current = current->next;
    }
    list->count = 0;
}

int main()
{
    list listNew;
    initialize(listNew);
    insertFirst(listNew, 1);
    insertFirst(listNew, 2);
    insertFirst(listNew, 3);
    insertFirst(listNew, 4);
    insertFirst(listNew, 5);
    insertFirst(listNew, 6);
    insertFirst(listNew, 7);
    display(listNew);
}

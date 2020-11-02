// Michael Nath
// Period 10 Systems Level Programming
// Work 09: Construction Work

#include "padre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_padre(struct padre *p)
{
    printf("Details of Padre %s:\nAge: %d\nNumber of Kids:%d\n%s says: %s\n\n", p->name, p->age, p->num_kids, p->name, p->greeting);
}

void print_padre_list(char *padre_name)
{
    printf("%s", padre_name);
}
struct padre *new_padre(int age, char *name, char *greeting, int num_kids)
{
    struct padre *pads;
    // pads represents a pointer that is of type struct padre

    pads = malloc(sizeof(struct padre));
    // assigns space in heap memory to the pads pointer. It gets as much as the size of the padre struct

    // by using the -> notation, assign the attributes of this struct to the parameters given
    pads->age = age;
    pads->num_kids = num_kids;
    strncpy(pads->name, name, sizeof(pads->name) - 1);
    strncpy(pads->greeting, greeting, sizeof(pads->greeting) - 1);
    return pads;
}

void change_padre(struct padre *p)
{
    p->age = rand();
    p->num_kids = rand();
}

struct padre *free_list(struct padre *first)
{
    struct padre *cur = first;
    while (cur)
    {
        struct padre *next = cur->next;
        free(cur);
        cur = next;
    }
    return cur;
}

void print_list(struct padre *first)
{
    printf("[");
    while (first)
    {
        print_padre_list(first->name);
        if ((first->next))
        {
            printf(" ");
        }
        first = first->next;
    }
    printf("]\n");
}

struct padre *remove_node(struct padre *front, char *name)
{
    struct padre *cur = front;
    if (strcmp(cur->name, name) == 0)
    {
        cur = front->next;
        free(front);
        return cur;
    }
    while (cur->next)
    {
        struct padre *next = cur->next;
        if (!strcmp(next->name, name))
        {
            cur->next = next->next;
            free(next);
            return front;
        }
        else
        {
            cur = cur->next;
        }
    }
    return front;
}

struct padre *insert_list(struct padre *front, int age, char *name, char *greeting, int num_kids)
{
    struct padre *np;
    np = new_padre(age, name, greeting, num_kids);
    np->next = front;
    return np;
}
#include "padre.h"
#include <stdio.h>

int main()
{
    struct padre *first = NULL;
    printf("printing empty list...\n");
    print_list(first);
    printf("Adding first person to the list...\n");
    first = new_padre(10, "Juan", "hello", 1);
    print_list(first);
    printf("Adding more people to the list...\n");
    first = insert_list(first, 100, "Chelsea", "Bye", 12);
    first = insert_list(first, 23, "Joaquin", "Boo", 4);
    first = insert_list(first, 77, "Manuel", "hehe", 2);
    print_list(first);
    // printf("Removing Manuel...\n");
    // first = remove_node(first, "Manuel");
    // print_list(first);
    printf("Removing Joaquin...\n");
    first = remove_node(first, "Joaquin");
    print_list(first);
    // printf("Removing Chelsea...\n");
    // first = remove_node(first, "Chelsea");
    // print_list(first);
    printf("Removing Juan...\n");
    first = remove_node(first, "Juan");
    print_list(first);
    printf("Freeing list...\n");
    first = free_list(first);
    printf("printing empty list...\n");
    print_list(first);
}
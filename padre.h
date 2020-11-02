#ifndef PADRE_H
#define PADRE_H
struct padre
{
    int age;
    char name[256];
    char greeting[256];
    int num_kids;
    struct padre *next;
};
struct padre *new_padre(int age, char *name, char *greeting, int num_kids);
void change_padre(struct padre *p);
void print_padre(struct padre *p);
struct padre *free_list(struct padre *first);
void print_list(struct padre *first);
struct padre *remove_node(struct padre *front, char * name);
struct padre *insert_list(struct padre *front, int age, char *name, char *greeting, int num_kids);
#endif
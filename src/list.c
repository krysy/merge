#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define TRUE 1
#define FALSE 0


void listTrim(List* lst){
    for(int i = 0; i < lst->size; i++){
        if (lst->items[i].exists == FALSE) {
            memmove(&lst->items[i], &lst->items[i+1], sizeof(ListItem) * lst->size - i);
            lst->size -= 1;
            lst->items = realloc(lst->items, sizeof(ListItem) * lst->size);
            break;
        }        
    }
} 

void listRemoveAt(List* lst, unsigned int index){
    lst->items[index].exists = FALSE;
    listTrim(lst);
}

void listAddPointer(List* lst, void* obj){
	lst->items = realloc(lst->items, sizeof(ListItem) * (lst->size + 1));//increase size
	//lst->items[lst->size].item = malloc(sizeof(void*));//malloc memory for void*
	lst->items[lst->size].item = obj;//set value
	lst->items[lst->size].exists= TRUE;
	lst->size += 1;
}

void listAddInteger(List* lst, int number){
    lst->items = realloc(lst->items, sizeof(ListItem) * (lst->size + 1));//increase size
    lst->items[lst->size].item = malloc(sizeof(void*));//malloc memory for void*
    *((int *)lst->items[lst->size].item) = number;//set value
    lst->items[lst->size].exists= TRUE;
    lst->size += 1;
}

void listAppendList(List* source, List* destination){
    destination->items = realloc(destination->items,sizeof(ListItem) * ( destination->size + source->size));
    memcpy(&destination->items[destination->size], source->items, sizeof(ListItem) * source->size);
    destination->size += source->size;
}

List* listCreate(){
    List* lst = malloc(sizeof(List));
    lst->size = 0;
    lst->items = malloc(sizeof(ListItem));
    return lst;
}

List* listCreateSize(int size){
    List* lst = calloc(1, sizeof(List));
    lst->size = size;
    lst->items = calloc(size, sizeof(ListItem));
    return lst;
}

int listGetInteger(List* lst, int index){
	return *((int*) lst->items[index].item);
}
void* listGetPointer(List* lst, int index){
	return lst->items[index].item;
}
int voidToInt(void* ptr){
	return *((int*) ptr);
}

void listPrint(List* lst){
    if (lst->size == 0) {
        return;
    }
    printf("[ ");        
    for(int i = 0; i < lst->size; i++){
        if (i >= lst->size - 1) {
            printf("%i ", listGetInteger(lst, i));
        } else {
            printf("%i, ", listGetInteger(lst, i));
        }
    }
    printf("]");        
}

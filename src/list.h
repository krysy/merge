#ifndef H_LIST
#define H_LIST
#define TRUE 1
#define FALSE 0

typedef struct ListItem{
	void* item;
	char exists;
}ListItem;

typedef struct List{
    int size;
    ListItem* items;
}List;

struct listPtr{
    List* ptr;
};

void listTrim(List* lst);
void listRemoveAt(List* lst, unsigned int index);
void listAddPointer(List* lst, void* obj);
void listAddInteger(List* lst, int number);
void listAppendList(List* source, List* destination);
List* listCreate();
List* listCreateSize(int size);
int listGetInteger(List* lst, int index);
void* listGetPointer(List* lst, int index);
int voidToInt(void* ptr);
void listPrint(List* lst);

#endif
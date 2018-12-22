#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "list.h"
#include "config.h"

#define TRUE 1
#define FALSE 0

int totalIterations = 0;
int returnedItems = 0;


List* merge(List* list1, List* list2){
	List* outlist = listCreate();

	if (list2 == 0){
		returnedItems = 1;
		listAppendList(list1, outlist);
		return outlist;
	}

    for(;;){
    	totalIterations++;
        if(list1->size == 0){
        	listAppendList(list2, outlist);
        	break;
        } else if (list2->size == 0) {
        	listAppendList(list1, outlist);
        	break;
        }

        if (listGetInteger(list1, 0) <= listGetInteger(list2, 0)) {
            listAddInteger(outlist, listGetInteger(list1, 0));
            listRemoveAt(list1, 0);
        } else if (listGetInteger(list1, 0) >= listGetInteger(list2, 0)){
            listAddInteger(outlist, listGetInteger(list2, 0));
            listRemoveAt(list2, 0);
        }
    }
    free(list1);
    free(list2);
    returnedItems = 2;
    return outlist;
}

int main(int argc, char *argv[]){
    // Seed pseudorandom generator
    srand(time(NULL));
    List* slist = listCreate();

    for (int i = 0; i < ARR_SIZE; i++) {
		listAddInteger(slist, random() % ARR_MAX_NUMBER);
	}

    listPrint(slist);
    List* lists = listCreate();
    for (int i = 0; i < ARR_SIZE; i++) {
    	List* lst = listCreate();
		listAddInteger(lst, listGetInteger(slist, i));
    	listAddPointer(lists, lst);
	}
    printf("\n");

    for (int i = 0; i < ARR_SIZE; i++) {
		listPrint(lists->items[i].item);
	}

	List* previousMerged = lists;
    for(;;){
    	if (previousMerged->size <= 1) {
			break;
		}
		List* merged = listCreate();
		for(;;){
			if (previousMerged->size < 1) {
				break;
			}
			listAddPointer(merged, merge(listGetPointer(previousMerged, 0), listGetPointer(previousMerged, 1)));
			if (returnedItems == 2) {
				listRemoveAt(previousMerged, 0);
				listRemoveAt(previousMerged, 0);
			} else {
				listRemoveAt(previousMerged, 0);
			}
		}
		printf("\n");
		for (int i = 0; i < merged->size; i++) {
			listPrint(listGetPointer(merged, i));
		}
      
		free(previousMerged);
    	previousMerged = merged;
    }
    fprintf(stderr, "Total iterations: %i\n", totalIterations);

    return 0;
}

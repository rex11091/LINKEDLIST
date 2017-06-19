#include "linklist.h"
#include <stdio.h>

void ListInit(LinkList *list){
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void ListAdd(LinkList *list, Item *item)
{
  if(list->len==0){
    list->head = item;
    list->tail = item;
  }
  else{
    list->tail=item;
  }
    list->len += 1;
    item->next = NULL;
}




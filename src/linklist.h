#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct Item Item;
typedef struct LinkList LinkList;

struct Item{
  Item *next;
  void *data;
};

struct LinkList{
  Item *head;
  Item *tail;
  int len;
  
};

void listInit(LinkList *list);
void ListAdd(LinkList *list, Item *item);
Item *ListRemoveIDEither1stOrByName(LinkList *list, char  *name);

#endif // _LINKLIST_H

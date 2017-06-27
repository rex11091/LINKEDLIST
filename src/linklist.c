#include <stdio.h>
#include "linklist.h"
#include <string.h>
#include "student.h"

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
	list->len = 1;
	item->next = NULL;
  }
  else{
	list->tail->next=item;
    list->tail=item;
    list->len += 1;
    item->next = NULL;
	}
}

Item *ListRemoveIDEither1stOrByName(LinkList *list, char  *name)
{
	Item *TempToPoint1 = NULL ;
	Item *TempToPoint2 = list->head;
	
	if(list->head == NULL)
	return NULL;

	
	else
	{	/*
		*compare to by findding name 
		*temp1---+			temp2---+										*temp1---+		temp2---+
	|			|				   |													|			    |
				|				   |	        ->after finding name such as abu				|			    |
				NULL				  ALi												Ali--------------ABU---NULL
		*/
		while(strcmp(((Student *)TempToPoint2->data)->name,name) != 0)
		{
			TempToPoint1 = TempToPoint2;
			TempToPoint2 = TempToPoint2->next;
		}
		/* here is found and delete the lstdata;
		 * depends on conditions eitheir only 1 data or ...
		 * if one data only init it
		*/
		 if(TempToPoint2 == list->head)
		 {
			 if(list->head == list->tail)
			 {
				 ListInit(list);
			 }
			 else
			 {
				 
				TempToPoint2 = TempToPoint2->next;
				list->head = TempToPoint2;
				list->len--;
			 }
		 }
			//here is delete last data
		else if	(TempToPoint2 == list->tail)
		{
			list->tail = TempToPoint1;
			TempToPoint1->next = NULL;
			list->len--;
		}
		else //delete middle by finding name
		{
			TempToPoint1->next = TempToPoint2->next;
			list->len--;
		}
	}		
}
	


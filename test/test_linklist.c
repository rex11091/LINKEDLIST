#include "unity.h"
#include "linklist.h"
#include "student.h"

void setUp(void)
{
}

void tearDown(void)
{
}



Student ali = {
    "Ali",                  //name
    23,                     //age
    72.35,                  //weight
    1.78                    //height
    };
  Item itemALi = {
    (Item *)-345,        //next
    (void *)&ali,            //data
    
  };
  
  Student Baba = {
    "Baba",                  //name
    24,                     //age
    73.35,                  //weight
    1.88                    //height
    };
  Item itemBABA = {
    (Item *)-345,        //next
    (void *)&Baba,            //data
    
  };
  Student Celina = {
    "Celina",                  //name
    19,                     //age
    55.5,                  //weight
    1.65                    //height
    };
  Item itemCelina = {
    (Item *)-34534346,        //next
    (void *)&Celina,            //data
    
  };
  



void test_listInit_ensure_initialized_to_NULL_and_0(void)
{
  LinkList list = {
    (Item *)-1,
    (Item *)-1,
    10
  };
  
  ListInit(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.len);
}





/**
*           initial                     After adding Ali
*                                 
*           tail----+                     tail------+
*           head----+                     head------+    
*                   |                         
*                  NULL
*
*
*
*
*
* Given an empty linked list . Add Ali(student) . Expect the linked contains Ali.
**/

void test_studentAli(void)
{
  LinkList list;
  

  ListInit(&list);
  ListAdd(&list,&itemALi);
  TEST_ASSERT_EQUAL_PTR(&itemALi,list.head);
  TEST_ASSERT_EQUAL_PTR(&itemALi,list.tail);
  TEST_ASSERT_EQUAL(1,list.len);
  TEST_ASSERT_NULL(itemALi.next);
  TEST_ASSERT_EQUAL_PTR(&ali,itemALi.data);
  
}

void test_studentBaBa(void)
{
  LinkList list;
  list.head=&itemALi;
  list.tail=&itemALi;
  list.len=1;
  itemALi.next=NULL;
  itemALi.next=(Item *)-1;
  
  ListAdd(&list,&itemBABA);
  
  TEST_ASSERT_EQUAL_PTR(&itemALi,list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBABA,list.tail);
  TEST_ASSERT_EQUAL_PTR(&itemBABA,itemALi.next);
  TEST_ASSERT_EQUAL_PTR(&Baba,itemBABA.data);
  TEST_ASSERT_EQUAL(2,list.len);
  TEST_ASSERT_NULL(itemBABA.next);
  
}

void test_studentCelina(void)
{
  LinkList list;
  list.head=&itemALi;
  list.tail=&itemBABA;
  list.len=2;
  itemBABA.next=NULL;
  itemBABA.next=(Item *)-1;
  
  ListAdd(&list,&itemCelina);
  
  TEST_ASSERT_EQUAL_PTR(&itemALi,list.head);
  TEST_ASSERT_EQUAL_PTR(&itemCelina,list.tail);
  TEST_ASSERT_EQUAL_PTR(&itemCelina,itemBABA.next);
  TEST_ASSERT_EQUAL_PTR(&Celina,itemCelina.data);
  TEST_ASSERT_EQUAL(3,list.len);
  TEST_ASSERT_NULL(itemCelina.next);
  TEST_ASSERT_EQUAL_PTR(&Celina,itemCelina.data);
}


void test_student_remove_from_list_which_in_1st_list(void)
{
	
	  LinkList list;
	list.head =&itemALi;
	list.tail=&itemCelina;
	itemALi.next = &itemBABA;
	itemBABA.next= &itemCelina;
	itemCelina.next = NULL;
	list.len=3;
  
  ListRemoveIDEither1stOrByName(&list, "Ali");
  
  TEST_ASSERT_EQUAL_PTR(&itemBABA,list.head);
  TEST_ASSERT_EQUAL_PTR(&itemCelina,list.tail);
  TEST_ASSERT_EQUAL_PTR(&itemCelina,itemBABA.next);
  TEST_ASSERT_EQUAL(2,list.len);
  TEST_ASSERT_NULL(itemCelina.next);
  TEST_ASSERT_EQUAL_PTR(&Celina,itemCelina.data);
}


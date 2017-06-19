#include "unity.h"
#include "linklist.h"
#include "student.h"




Student ali = {
    "Ali",                  //name
    23,                     //age
    72.35,                  //weight
    1.78                    //height
    };
  Item itemALi = {
    (Item *)-34534346,        //next
    (void *)&ali,            //data
    
  };
  
  LinkList list;
  Student Baba = {
    "Baba",                  //name
    24,                     //age
    73.35,                  //weight
    1.88                    //height
    };
  Item itemBABA = {
    (Item *)-34534346,        //next
    (void *)&Baba,            //data
    
  };
  

void setUp(void)
{
}

void tearDown(void)
{
}

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

void test_student(void)
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
  itemALi.next=&itemBABA;
  itemALi.data=(Item *)-1;
  
  ListAdd(&list,&itemBABA);
  
  TEST_ASSERT_EQUAL_PTR(&itemALi,list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBABA,list.tail);
  TEST_ASSERT_EQUAL(2,list.len);
  TEST_ASSERT_NULL(itemBABA.next);
  TEST_ASSERT_EQUAL_PTR(&Baba,itemBABA.data);
  
}


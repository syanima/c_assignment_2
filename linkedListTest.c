#include <stdio.h>
#include <assert.h>
#include "linkedList.h"


void  test_for_create_linkedlist(){
   LinkedList linkedlist = createList();
   assert(linkedlist.head == NULL);
   assert(linkedlist.tail == NULL);
   assert(linkedlist.length == 0);
}

void test_for_add_element_to_list(){
	LinkedList linkedlist = createList();
	int data = 23;
	add_to_list(&linkedlist,&data);
	int value = *(int *)linkedlist.tail->value;
	assert(value == 23); 
} 

void test_for_returns_first_element_in_the_list(){
	LinkedList linkedlist = createList();
	int first_data = 23;
	int second_data = 46;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	int value = *(int *)get_first_element(linkedlist);
	assert(value == 23);
}

void test_for_returns_last_element_in_the_list(){
	LinkedList linkedlist = createList();
	int first_data = 23;
	int second_data = 46;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	int value = *(int *)get_last_element(linkedlist);
	assert(value == 46);
}
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

void square_of(void *item){
	*(int *)item = (*(int *)item)*(*(int *)item);
}

void increment(void *item){
	*(int *)item = (*(int *)item)+1; 
}

void test_for_forEach_using_a_traverse_function_using_integers(){
	LinkedList linkedlist = createList();
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	int number4 = 4;
	int number5 = 5;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	forEach(linkedlist,&square_of);

	assert(*(int *)get_first_element(linkedlist) == 1);
	assert(*(int *)get_last_element(linkedlist) == 25);

	forEach(linkedlist,&increment);

	assert(*(int *)get_first_element(linkedlist) == 2);
	assert(*(int *)get_last_element(linkedlist) == 26);
}

void test_for_checking_forEach_using_a_traverse_function_using_characters(){
	LinkedList linkedlist = createList();
	char character1 = 's';
	char character2 = 'y';
	char character3 = 'a';
	char character4 = 'n';
	char character5 = 'i';

	add_to_list(&linkedlist,&character1);
	add_to_list(&linkedlist,&character2);
	add_to_list(&linkedlist,&character3);
	add_to_list(&linkedlist,&character4);
	add_to_list(&linkedlist,&character5);


	forEach(linkedlist,&increment);

	assert(*(char *)get_first_element(linkedlist) == 't');
	assert(*(char *)get_last_element(linkedlist) == 'j');
}
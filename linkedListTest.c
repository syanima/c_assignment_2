#include <stdio.h>
#include <stdlib.h>
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

void  test_for_get_element_which_returns_the_element_at_defined_position(){
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

	int value = *(int *)getElementAt(linkedlist,2);
	assert(value == 3);
}

void  test_for_index_of_which_returns_the_position_of_element(){
	LinkedList linkedlist = createList();
	int number1 = 11;
	int number2 = 12;
	int number3 = 13;
	int number4 = 14;
	int number5 = 15;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	int value = indexOf(linkedlist,&number3);
	assert(value == 2);
}

void  test_for_returning_the_data_which_deleted_according_to_the_index(){
	LinkedList linkedlist = createList();
	int number1 = 11;
	int number2 = 12;
	int number3 = 13;
	int number4 = 14;
	int number5 = 15;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	int value = *(int *)deleteElementAt(&linkedlist,4);
	assert(value == 15);
}

void  test_for_returning_the_length_of_array_that_contains_specified_no_of_elements(){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	void *destination = (int *)calloc(6,8);
	int countIncluded = asArray(list, destination, 6);
	assert(countIncluded == 6);
}

void test_asArray_copies_address_of_all_the_values_to_the_destination_given () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	void *destination = (int *)calloc(6,8);
	int countIncluded = asArray(list, destination, 6);
	assert(countIncluded == 6);
	for (int i = 0; i < 6; ++i){
		assert(**(int **)destination == array[i]);
		destination+=8;
	}
}

void test_asArray_copies_address_of_the_values_in_the_list_to_the_given_destination_until_the_given_limit () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	void *destination = (int *)calloc(2,8);
	int countIncluded = asArray(list, destination, 2);
	assert(countIncluded == 2);
	for (int i = 0; i < 2; ++i){
		assert(**(int **)destination == array[i]);
		destination+=8;
	}
}

int isDivisible (void* hint, void* item) {
	return (*(int *)item) % (*(int *)hint)==0;
}

int isEven (void* hint, void* item){
	return (*(int *)item)%2 == 0;
}

int isOdd (void *hint,void *item){
	return (*(int *)item)%2 == 1;
}


void test_for_filter_with_isEven(){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6,7,8};
	for(int i = 0;i<8;i++){
		add_to_list(&list,&array[i]);
	}
	LinkedList filterResult = filter(list,isEven,NULL);
	int arrayResult[] = {2,4,6,8};
	void *destination = (int *)calloc(4,8);

	int countIncluded= asArray(filterResult, destination, 4);
	assert(countIncluded== 4);
	for (int i = 0; i < filterResult.length; ++i){
		assert(**(int **)destination == arrayResult[i]);
		destination+=8;
	}
}

void test_for_filter_with_isOdd(){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6,7,8,9};
	for(int i = 0;i<9;i++){
		add_to_list(&list,&array[i]);
	}
	LinkedList filterResult = filter(list,isOdd,NULL);
	int arrayResult[] = {1,3,5,7,9};
	void *destination = (int *)calloc(5,8);

	int countIncluded= asArray(filterResult, destination, 5);
	assert(countIncluded== 5);
	for (int i = 0; i < filterResult.length; ++i){
		assert(**(int **)destination == arrayResult[i]);
		destination+=8;
	}
}

void test_for_filter_with_isDivisible(){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6,7,8,9};
	for(int i = 0;i<9;i++){
		add_to_list(&list,&array[i]);
	}
	int number = 2;
	LinkedList filterResult = filter(list,isDivisible,&number);
	int arrayResult[] = {2,4,6,8};
	void *destination = (int *)calloc(4,8);
	int countIncluded= asArray(filterResult, destination, 4);
	assert(countIncluded== 4);
	for (int i = 0; i < filterResult.length; ++i){
		assert(**(int **)destination == arrayResult[i]);
		destination+=8;
	}
}

void test_for_reverse(){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6,7,8,9};
	for(int i = 0;i<9;i++){
		add_to_list(&list,&array[i]);
	}
	LinkedList result = reverse(list);
	int arrayResult[] = {9,8,7,6,5,4,3,2,1};
	void *destination = (int *)calloc(9,8);

	int countIncluded= asArray(result, destination, 9);
	assert(countIncluded== 9);
	for (int i = 0; i < result.length; ++i){
		assert(**(int **)destination == arrayResult[i]);
		destination+=8;
	}
}

void subtracting_a_value(void* hint, void* sourceItem, void* destinationItem) {
	*(int *)destinationItem = *(int *)sourceItem - *(int *)hint;
}

void test_for_map_that_gives_a_new_list_based_on_the_function() {
	LinkedList list = createList();
	int array[] = {11,12,13,14,15,16};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
		}
	int number = 4;
	LinkedList list_of_result = map(list, subtracting_a_value, &number);
	int arrayResult[] = {7,8,9,10,11,12};
	void *destination = (int *)calloc(6,8);
	int countIncluded = asArray(list_of_result, destination, 6);
	assert(countIncluded == 6);
	for (int i = 0; i < countIncluded; ++i){
		assert(**(int **)destination == arrayResult[i]);
		destination+=8;
	}
}


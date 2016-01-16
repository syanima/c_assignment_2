#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linkedList.h"


void  test_for_create_linkedlist(){
   LinkedList linkedlist = createList();
   assert(linkedlist.head == NULL);
   assert(linkedlist.tail == NULL);
   assert(linkedlist.length == 0);
}

void test_for_add_element_to_list_of_integer_type(){
	LinkedList linkedlist = createList();
	int data = 23;
	add_to_list(&linkedlist,&data);
	int value = *(int *)linkedlist.tail->value;
	assert(value == 23); 
} 

void test_for_add_element_to_list_of_double_type(){
	LinkedList linkedlist = createList();
	double data = 23.63;
	add_to_list(&linkedlist,&data);
	double value = *(double *)linkedlist.tail->value;
	assert(value == 23.63); 
} 

void test_for_add_element_to_list_of_float_type(){
	LinkedList linkedlist = createList();
	float data = 3.6;
	add_to_list(&linkedlist,&data);
	float value = *(float *)linkedlist.tail->value;
	assert(value == 3.6f); 
} 

void test_for_add_element_to_list_of_character_type(){
	LinkedList linkedlist = createList();
	char data = 's';
	add_to_list(&linkedlist,&data);
	char value = *(char *)linkedlist.tail->value;
	assert(value == 's'); 
} 

void test_add_to_list_should_add_two_data_into_a_linkedList_with_an_int_type () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	add_to_list(&list,&data1);
	add_to_list(&list,&data2);
	int value1 = *(int *)list.tail->value;
	int value2 = *(int *)list.head->value;
	assert(value1 == 4);
	assert(value2 == 2);
	assert(list.head->next==list.tail);
}

void test_add_to_list_should_add_two_data_into_a_linkedList_with_an_double_type () {
	double data1 = 29.89, data2 = 48.32;
	LinkedList list = createList();
	add_to_list(&list,&data1);
	add_to_list(&list,&data2);
	double value1 = *(double *)list.tail->value;
	double value2 = *(double *)list.head->value;
	assert(value1 == 48.32);
	assert(value2 == 29.89);
	assert(list.head->next==list.tail);
}

void test_add_to_list_should_add_two_data_into_a_linkedList_with_an_float_type () {
	float data1 = 2.7, data2 = 4.8;
	LinkedList list = createList();
	add_to_list(&list,&data1);
	add_to_list(&list,&data2);
	float value1 = *(float *)list.tail->value;
	float value2 = *(float *)list.head->value;
	assert(value1 == 4.8f);
	assert(value2 == 2.7f);
	assert(list.head->next==list.tail);
}

void test_add_to_list_should_add_two_data_into_a_linkedList_with_an_char_type () {
	char data1 = 's', data2 = 'a';
	LinkedList list = createList();
	add_to_list(&list,&data1);
	add_to_list(&list,&data2);
	char value1 = *(char *)list.tail->value;
	char value2 = *(char *)list.head->value;
	assert(value1 == 'a');
	assert(value2 == 's');
	assert(list.head->next==list.tail);
}

void test_for_returns_first_element_in_the_list_of_two_integer_data(){
	LinkedList linkedlist = createList();
	int first_data = 23;
	int second_data = 46;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	int value = *(int *)get_first_element(linkedlist);
	assert(value == 23);
}

void test_for_returns_first_element_in_the_list_of_two_char_data(){
	LinkedList linkedlist = createList();
	char first_data = 's';
	char second_data = 'a';
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	char value = *(char *)get_first_element(linkedlist);
	assert(value == 's');
}

void test_for_returns_first_element_in_the_list_of_two_float_data(){
	LinkedList linkedlist = createList();
	float first_data = 23.9;
	float second_data = 46.4;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	float value = *(float *)get_first_element(linkedlist);
	assert(value == 23.9f);
}

void test_for_returns_first_element_in_the_list_of_two_double_data(){
	LinkedList linkedlist = createList();
	double first_data = 23.76;
	double second_data = 32.90;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	double value = *(double *)get_first_element(linkedlist);
	assert(value == 23.76);
}

void test_for_returns_last_element_in_the_list_of_two_integer_data(){
	LinkedList linkedlist = createList();
	int first_data = 23;
	int second_data = 46;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	int value = *(int *)get_last_element(linkedlist);
	assert(value == 46);
}

void test_for_returns_last_element_in_the_list_of_two_character_data(){
	LinkedList linkedlist = createList();
	char first_data = 'a';
	char second_data = 's';
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	char value = *(char *)get_last_element(linkedlist);
	assert(value == 's');
}

void test_for_returns_last_element_in_the_list_of_two_double_data(){
	LinkedList linkedlist = createList();
	double first_data = 23.78;
	double second_data = 42.76;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	double value = *(double *)get_last_element(linkedlist);
	assert(value == 42.76);
}

void test_for_returns_last_element_in_the_list_of_two_float_data(){
	LinkedList linkedlist = createList();
	float first_data = 23.3;
	float second_data = 56.7;
	add_to_list(&linkedlist,&first_data);
	add_to_list(&linkedlist,&second_data);
	float value = *(float *)get_last_element(linkedlist);
	assert(value == 56.7f);
}

void square_of_integer(void *item){
	*(int *)item = (*(int *)item)*(*(int *)item);
}

void square_of_double(void *item){
	*(double *)item = (*(double *)item)*(*(double *)item);
}

void square_of_float(void *item){
	*(float *)item = (*(float *)item)*(*(float *)item);
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

	forEach(linkedlist,&square_of_integer);

	assert(*(int *)get_first_element(linkedlist) == 1);
	assert(*(int *)get_last_element(linkedlist) == 25);

	forEach(linkedlist,&increment);

	assert(*(int *)get_first_element(linkedlist) == 2);
	assert(*(int *)get_last_element(linkedlist) == 26);
}

void test_for_forEach_using_a_traverse_function_using_double_values(){
	LinkedList linkedlist = createList();
	double number1 = 11.32;
	double number2 = 11.12;
	double number3 = 11.22;
	double number4 = 11.42;
	double number5 = 11.52;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	forEach(linkedlist,&square_of_double);

	assert(*(double *)get_first_element(linkedlist) == 128.1424);
	assert(*(double *)get_last_element(linkedlist) == 132.7104);
}

void test_for_forEach_using_a_traverse_function_using_float_values(){
	LinkedList linkedlist = createList();
	float number1 = 1.0;
	float number2 = 2.1;
	float number3 = 3.1;
	float number4 = 4.1;
	float number5 = 5.0;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	forEach(linkedlist,&square_of_float);

	assert(*(float *)get_first_element(linkedlist) == 1.0f);
	assert(*(float *)get_last_element(linkedlist) == 25.0f);
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

void  test_for_get_element_which_returns_the_element_at_first_position(){
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

	int value = *(int *)getElementAt(linkedlist,0);
	assert(value == 1);
}

void  test_for_get_element_which_returns_the_element_at_last_position(){
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

	int value = *(int *)getElementAt(linkedlist,4);
	assert(value == 5);
}

void  test_for_get_element_which_returns_the_element_of_float_type_at_defined_position(){
	LinkedList linkedlist = createList();
	float number1 = 1.1;
	float number2 = 2.1;
	float number3 = 3.1;
	float number4 = 4.1;
	float number5 = 5.1;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	float value = *(float *)getElementAt(linkedlist,3);
	assert(value == 4.1f);
}

void  test_for_get_element_which_returns_the_element_of_double_type_at_defined_position(){
	LinkedList linkedlist = createList();
	double number1 = 11.11;
	double number2 = 22.21;
	double number3 = 33.31;
	double number4 = 44.41;
	double number5 = 55.51;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	double value = *(double *)getElementAt(linkedlist,2);
	assert(value == 33.31);
}

void  test_for_get_element_which_returns_the_element_of_char_type_at_defined_position(){
	LinkedList linkedlist = createList();
	char number1 = 'j';
	char number2 = 'a';
	char number3 = 'a';
	char number4 = 'n';
	char number5 = 'u';

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	char value = *(char *)getElementAt(linkedlist,1);
	assert(value == 'a');
}
	
void  test_for_index_of_which_returns_the_position_of_element_of_int_type(){
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

void  test_for_index_of_which_returns_minus_1_when_data_of_int_type_is_not_found(){
	LinkedList linkedlist = createList();
	int number1 = 11;
	int number2 = 12;
	int number3 = 13;
	int number4 = 14;
	int number5 = 15;
	int number6 = 16;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	int value = indexOf(linkedlist,&number6);
	assert(value == -1);
}

void  test_for_index_of_which_returns_0_which_is_the_index_of_first_element_of_int_type(){
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

	int value = indexOf(linkedlist,&number1);
	assert(value == 0);
}

void  test_for_index_of_which_returns_the_position_of_element_of_float_type(){
	LinkedList linkedlist = createList();
	float number1 = 1.1;
	float number2 = 1.2;
	float number3 = 1.3;
	float number4 = 1.4;
	float number5 = 1.5;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	float value = indexOf(linkedlist,&number3);
	assert(value == 2);
}

void  test_for_index_of_which_returns_1_which_is_the_index_of_second_element_of_float_type(){
	LinkedList linkedlist = createList();
	float number1 = 1.1;
	float number2 = 1.2;
	float number3 = 1.3;
	float number4 = 1.4;
	float number5 = 1.5;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	float value = indexOf(linkedlist,&number1);
	assert(value == 0);
}

void  test_for_index_of_which_returns_the_position_of_element_of_char_type(){
	LinkedList linkedlist = createList();
	char number1 = 'j';
	char number2 = 'a';
	char number3 = 'a';
	char number4 = 'n';
	char number5 = 'u';

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	char value = indexOf(linkedlist,&number4);
	assert(value == 3);
}

void  test_for_index_of_which_returns_4_which_is_the_index_of_last_element_of_char_type(){
	LinkedList linkedlist = createList();
	char number1 = 'j';
	char number2 = 'a';
	char number3 = 'a';
	char number4 = 'n';
	char number5 = 'u';

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	char value = indexOf(linkedlist,&number5);
	assert(value == 4);
}

void  test_for_returning_the_data_of_int_type_which_deleted_according_to_the_index(){
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

	int value = *(int *)deleteElementAt(&linkedlist,2);
	assert(value == 13);
}

void  test_for_returning_the_data_of_float_type_which_deleted_according_to_the_index(){
	LinkedList linkedlist = createList();
	float number1 = 1.1;
	float number2 = 1.2;
	float number3 = 1.3;
	float number4 = 1.4;
	float number5 = 1.5;

	add_to_list(&linkedlist,&number1);
	add_to_list(&linkedlist,&number2);
	add_to_list(&linkedlist,&number3);
	add_to_list(&linkedlist,&number4);
	add_to_list(&linkedlist,&number5);

	float value = *(float *)deleteElementAt(&linkedlist,2);
	assert(value == 1.3f);
}

void  test_for_returning_the_data_of_int_type_which_deleted_from_the_first_position(){
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

	int value = *(int *)deleteElementAt(&linkedlist,0);
	assert(value == 11);
}

void  test_for_returning_the_data_of_int_type_which_deleted_from_the_last_position(){
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

void test_for_asArray_copies_address_of_the_values_in_the_list_to_the_given_destination_according_to_the_allocation_of_memory (){
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	for(int i=0;i<6;i++){
		add_to_list(&list,&array[i]);
	}
	void *dest = (int *)calloc(3,8);
	int no_of_ele_added = asArray(list,dest,6);
	for(int i=0;i<no_of_ele_added;i++){
		assert(**(int**)dest == array[i]);
		dest += 8;
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

void *add_all_element(void* hint, void* previousItem, void* item){
  *(int *)item = *(int *)item + *(int *)previousItem;
  return item;
}

void* larger(void* hint, void* previousItem, void* item){
	int previous_number = *(int *)previousItem;
	int current_number = *(int *)item;
	int result = previous_number > current_number ? previous_number : current_number;
	*(int *)previousItem = result;
	return previousItem;
}

void* smaller(void* hint, void* previousItem, void* item){
	int previous_number = *(int *)previousItem;
	int current_number = *(int *)item;
	int result = previous_number < current_number ? previous_number : current_number;
	*(int *)previousItem = result;
	return previousItem;
}

void test_for_reducing_the_list_using_add_all_element(){
	LinkedList list = createList();
	int array[] = {5,6,7,8,9,10};
	for(int i=0;i<6;i++){
		add_to_list(&list,&array[i]);
	}
	int hint = 0;
	int redused_result = *(int *)reduce(list, &add_all_element, &hint, &hint);
	assert(redused_result == 45);
}

void test_for_reducing_the_list_using_smaller(){
	LinkedList list = createList();
	int array[] = {5,6,7,8,9,10};
	for(int i=0;i<6;i++){
		add_to_list(&list,&array[i]);
	}
	int hint = 0;
	int redused_result = *(int *)reduce(list, &smaller, &hint, &hint);
	assert(redused_result == 0);
}

void test_for_reducing_the_list_using_larger(){
	LinkedList list = createList();
	int array[] = {5,6,7,8,9,10};
	for(int i=0;i<6;i++){
		add_to_list(&list,&array[i]);
	}
	int hint = 0;
	int redused_result = *(int *)reduce(list, &larger, &hint, &hint);
	assert(redused_result == 10);
}
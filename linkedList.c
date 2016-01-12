#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList linkedlist;
	linkedlist.length = 0;
	linkedlist.head = NULL;
	linkedlist.tail = NULL;
	return linkedlist;
}

int add_to_list(LinkedList *linkedlist,void *data){
	Node *ptr;
	ptr = (Node *) malloc(sizeof(Node));
	ptr->value = data;
	ptr->next = NULL;

	if(linkedlist->length==0){
		linkedlist->head = ptr;
		linkedlist->tail = ptr;
	}
	else{
		linkedlist->tail->next = ptr;
		linkedlist->tail = ptr;
	}
	linkedlist->length++;
	return 0;
}

void *get_first_element(LinkedList list){
	return list.head->value;
}

void *get_last_element(LinkedList list){
	return list.tail->value;
}

void forEach(LinkedList list, ElementProcessor func){
	 Node *ele = list.head;
	 while(ele != NULL){
	   func(ele ->value);
	   ele = ele -> next;
	 }
};
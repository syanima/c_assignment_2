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

void * getElementAt(LinkedList linkedlist, int index){
	Node *ele = linkedlist.head;
	if(index >= linkedlist.length || index < 0)
		return NULL;
	for (int i = 1; i <= index; ++i) {
		ele = ele->next;
	}
	return ele->value;
}

int indexOf(LinkedList list, void* element){
	int count = 0;
	Node *ele = list.head;
	while(ele != NULL){
		if(ele->value==element)
			return count;
		count++;
		ele = ele->next;
	}
	return -1;
}

void* deleteElementAt(LinkedList *list, int index) {
	int i = 0;
	void* deleted_data = 0;
	Node *ele = list->head;
	Node *pre = NULL;
	if(index < 0 || index >= list->length)
		return 0;
	while(i < index){
		pre = ele;
		ele = ele->next;
		i++;
	}
	deleted_data = ele->value;
	pre ? (pre->next = ele->next) : (list->head = list->head->next);
	ele == list->tail && (list->tail = pre);
	list->length--;
	return deleted_data;
}

int asArray(LinkedList list, void **array,int maxElements){
	int included=0,i;
	Node *ele = list.head;
	int length = (maxElements > list.length) ? list.length : maxElements;
		for(i=0;i<length;i++){
		array[i] = (void*)ele->value;
		included++;
		ele = ele->next;  
	}
	return included;
}

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

void * deleteElementAt(LinkedList *list, int index){
  if(index > list->length || index < 0) return NULL;
    Node *element = list->head;
    Node *deletedElement;
    if(index == 0) {
      deletedElement = list->head;
      list->head = list->head->next;
    }else{
      for(int i = 0;i < index - 1; i++){
        element = element->next;
      };
      if(index == list->length-1){
        deletedElement = element->next;
        list->tail = element;
      }else{
        deletedElement = element->next;
        element->next = element->next->next;
      }
    }
    list->length--;
    free(deletedElement);
    return deletedElement->value;
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

LinkedList filter(LinkedList list, MatchFunc match, void *hint) {
	LinkedList filterResult = createList();
	Node *element = list.head;
	while(element != NULL){
		if(match(hint,element->value))
			add_to_list(&filterResult, element->value);
		element = element->next;
	}
	return filterResult;
}

LinkedList reverse(LinkedList list){
	LinkedList linkedlist = createList();
	int *value;
	for(int i=(list.length-1);i>=0;i--){
		value = getElementAt(list,i);
		add_to_list(&linkedlist,value);
	}
	return linkedlist;
}

LinkedList map(LinkedList list, ConvertFunc convert, void *hint){
  Node *element = list.head;
  LinkedList destination = createList();
  for(int i = 0; i < list.length; i++){
    void *ele;
    ele = (void *)malloc(4);
    convert(hint, element->value, ele);
    element = element->next;
    add_to_list(&destination, ele);
  }
  return destination;
}

void * reduce(LinkedList list, Reducer reduce, void *hint, void *initialValue){
	Node *element = list.head;
	for(int i = 0; i < list.length; i++){
    	initialValue = reduce(hint, initialValue, element->value);
    element = element->next;
  }
  return initialValue;
}
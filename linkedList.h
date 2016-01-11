typedef struct Node{
	void *value;		
	struct Node *next;
} Node;

typedef struct{
	int length;
	struct Node *tail;
	struct Node *head;
}LinkedList;


LinkedList createList(void);
int add_to_list(LinkedList *linkedlist,void *data);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);

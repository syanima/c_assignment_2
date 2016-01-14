typedef struct Node{
	void *value;		
	struct Node *next;
} Node;

typedef struct{
	int length;
	struct Node *tail;
	struct Node *head;
}LinkedList;

typedef void(*ElementProcessor)(void *);
typedef int(MatchFunc)(void *, void *);

LinkedList createList(void);
int add_to_list(LinkedList *linkedlist,void *data);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList ,void **, int);
LinkedList  filter(LinkedList, MatchFunc, void * );
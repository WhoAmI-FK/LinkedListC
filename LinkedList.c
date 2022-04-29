#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// for now only int type
typedef struct{
	int* _size;
	int _val;
	struct item* _next;
}item;

typedef item* node;

node allocate(void)
{
	node ptr;
	ptr = (node)malloc(sizeof(item) * 1);
	if (ptr == NULL) {
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}
	return(ptr);
}

void output(node head) {
	node ptr = head;
	puts("\n");
	while (ptr != NULL) {
		printf("%d ", ptr->_val);
		ptr = ptr->_next;
	}
	puts("\n");
}

void push_back(node head,int val){
	if (head == NULL) {
		head = alloc();
		head->_val = val;
		*(head->_size) = 1;
		return;
	}
	node ptr = head;
	while (ptr != NULL) {
		ptr = ptr->_next;
	}
	ptr = allocate();
	ptr->_val = val;
	*(head->_size) = *(head->_size) + 1;

}

typedef node iterator;
void pop_back(node head) {
	iterator t = head;
	while (t->_next != NULL) {
		t = t->_next;
	}
	if (t == head) {
		free(t);
		head = NULL;
		*(head->_size) = 0;
		return 0;
	}
	iterator temp = t;
	free(t);
	temp = NULL;
	*(head->_size) = *(head->_size) - 1;
}

void push_front(node head, int val) {

}

void pop_front(node head) {

}


typedef unsigned long size_t;

typedef struct {
	node(*alloc)(void); // pointer to the function allocate
	node _head;
	size_t _size;
	void(*print)(void);
	void(*push_back)(node head,int val);
	void(*pop_back)(node head);
	void(*pop_front)(node head);
	void(*push_front)(node head, int val);
}linkedList;

void initLinkeedList(linkedList* l) {
	l->alloc = allocate;
	l->print = output;
	l->push_back = push_back;
	l->_head = NULL;
	l->_size = 0;
	l->_head->_size = l->_size;
}

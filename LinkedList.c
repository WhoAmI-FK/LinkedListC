#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// for now only int type
typedef struct{
	int _val;
	struct item* _next;
}item;

typedef item* node;
typedef node iterator;
node allocate(int* _size)
{
	node ptr;
	(*_size)++;
	ptr = (node)malloc(sizeof(item) * 1);
	if (ptr == NULL) {
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}
	ptr->_next = NULL;
	return(ptr);
}

void output(linkedList* _llist) {
	iterator ptr = _llist->_head;
	puts("\n");
	while (ptr != NULL) {
		printf("%d ", ptr->_val);
		ptr = ptr->_next;
	}
	puts("\n");
}

void push_back(linkedList* _llist,int val){
	node head = _llist->_head;
	if (head == NULL) {
		head = alloc();
		head->_val = val;
		head->_next = NULL;
		return;
	}
	iterator ptr = head;
	while (ptr != NULL) {
		ptr = ptr->_next;
	}
	ptr = allocate(&_llist->_size);
	ptr->_val = val;
}

void pop_back(linkedList* _llist) {
	node head = _llist->_head;
	if (head != NULL) {
		iterator t = head;
		while (t->_next != NULL) {
			t = t->_next;
		}

		if (t == head) {
			free(t);
			head = NULL;
			_llist->_size--;
			return;
		}
		iterator temp = t;
		free(t);
		temp = NULL;
		_llist->_size--;
	}
	else {
		// error
	}
}

void push_front(linkedList* _llist, int val) {
	node head = _llist->_head;
	if (head == NULL) {
		head = allocate(&_llist->_size);
		head->_val = val;
		return;
	}
	iterator temp = head;
	head = allocate(&_llist->_size);
	head->_val = val;
	head->_next = temp;
}

void pop_front(node head) {
/*	if (head == NULL) {
		// error
		exit(1);
	}
	
	iterator temp = head;
	head = head->_next;
	*(temp->_size) = *(temp->_size) - 1;
	free(temp);
*/
}


typedef unsigned long size_t;

typedef struct {
	node(*alloc)(void); // pointer to the function allocate
	node _head;
	size_t _size;
	void(*print)(void);
	void(*push_back)(linkedList* _llist,int val);
	void(*pop_back)(linkedList* _llist);
	void(*pop_front)(linkedList* _llist);
	void(*push_front)(linkedList* _llist, int val);
//	void(*push_back)(int val);

}linkedList;

void initLinkeedList(linkedList* l) {
	l->alloc = allocate;
	l->print = output;
	l->push_back = push_back;
	l->_head = NULL;
	l->_size = 0;
}

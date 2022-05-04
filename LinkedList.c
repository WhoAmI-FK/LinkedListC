#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
/* for now only int type */

struct item {
	int _val;
	struct item* _next;
};



struct linkedList {
	struct item*(*allocate)(void); 
	struct item* _head;
	unsigned long _size;
	void(*print)(void);
	void(*push_back)(struct linkedList* _llist, int val);
	void(*pop_back)(struct linkedList* _llist);
	void(*pop_front)(struct linkedList* _llist);
	void(*push_front)(struct linkedList* _llist, int val);
};
struct item* allocate()
{
	struct item* ptr;
	ptr = (struct item*)malloc(sizeof(struct item) * 1);
	if (ptr == NULL) {
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}
	ptr->_next = NULL;
	return(ptr);
}

void deallocate(struct item* toBeDest) {
	struct item* tmp; 
	tmp = toBeDest;
	free(tmp);
	toBeDest = NULL;
}

void output(struct linkedList* _llist) {
	puts("\n");
	struct item* ptr;
	ptr = _llist->_head;
	while (ptr != NULL) {
		printf("%d ", ptr->_val);
		ptr = ptr->_next;
	}
	puts("\n");
}

void push_back(struct linkedList* _llist,int val){
	struct item* ptr = _llist->_head;
	if (ptr == NULL) {
		(*_llist)._head = allocate();
		_llist->_head->_val = val;
		_llist->_head->_next = NULL;
		return;
	}
	while (ptr->_next != NULL) {
		ptr = ptr->_next;
	}
	ptr->_next = allocate();
	ptr->_next->_val = val;
}

void pop_back(struct linkedList* _llist) {
	struct item* head = _llist->_head;
	if (head != NULL) {
		struct item* t = head;
		while (t->_next != NULL) {
			t = t->_next;
		}

		if (t == head) {
			/*
			free(t);
			head = NULL;
			_llist->_size--;
			*/
			_llist->_size--;
			deallocate(t);
			return;
		}
		/*
		iterator temp = t;
		free(t);
		temp = NULL;
		_llist->_size--;
		*/
		_llist->_size--;
		deallocate(t);

	}
	else {

	}
}

void push_front(struct linkedList* _llist, int val) {
	struct item* temp;
	struct item* head = _llist->_head;
	if (head == NULL) {
		head = allocate();
		head->_val = val;
		return;
	}
	 temp = head;
	head = allocate();
	head->_val = val;
	head->_next = temp;
}

void pop_front(struct linkedList* _llist) {
/*	if (head == NULL) {
		// error
		exit(1);
	}
	
	iterator temp = head;
	head = head->_next;
	*(temp->_size) = *(temp->_size) - 1;
	free(temp);
*/

	struct item* head = _llist->_head;
	if (head == NULL) {
		exit(1);
	}
}


struct linkedList* initLinkedList() {
	struct linkedList* l = (struct linkedList*)malloc(sizeof(struct linkedList));
	l->allocate = allocate;
/*	l->print = output;*/
	l->push_back = push_back;
	l->pop_back = pop_back;
	l->push_front = push_front;
	l->pop_front = pop_front;
	l->_head = NULL;
	l->_size = 0;
	return l;
}


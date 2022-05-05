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
		_llist->_size++;
		return;
	}
	while (ptr->_next != NULL) {
		ptr = ptr->_next;
	}
	ptr->_next = allocate();
	ptr->_next->_val = val;
	_llist->_size++;
}

void pop_back(struct linkedList* _llist) {
	if (_llist->_head != NULL) {
		struct item* prev;
		struct item* ptr = _llist->_head;
		while (ptr->_next != NULL) {
			prev = ptr;
			ptr = ptr->_next;
		}
		
		if (ptr == _llist->_head) {
			/*
			free(t);
			head = NULL;
			_llist->_size--;
			*/
			_llist->_size--;
			deallocate(ptr);
			_llist->_head = NULL;
			return;
		}
		/*
		iterator temp = t;
		free(t);
		temp = NULL;
		_llist->_size--;
		*/
		_llist->_size--;
		deallocate(ptr);
		prev->_next = NULL;
	}
	else {

	}
}

void push_front(struct linkedList* _llist, int val) {
	struct item* ptr;
	if(_llist->_head==NULL){
		(*_llist)._head = allocate();
		_llist->_head->_val = val;
		_llist->_head->_next = NULL;
		_llist->_size++;
		return;
	}
	ptr = allocate();
	ptr->_val = val;
	ptr->_next = _llist->_head;
	_llist->_head = ptr;
	_llist->_size++;
	return;	
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


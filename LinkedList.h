#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* for now only int type */
struct item{
	int _val;
	struct item* _next;
};


typedef unsigned long size_list;
typedef struct item* node;
typedef node iterator;

 struct linkedList {
	struct item*(*allocate)(void); 
	struct item* _head;
	size_list _size;
	void(*print)(void);
	void(*push_back)(struct linkedList* _llist, int val);
	void(*pop_back)(struct linkedList* _llist);
	void(*pop_front)(struct linkedList* _llist);
	void(*push_front)(struct linkedList* _llist, int val);

};
typedef struct linkedList linkedList;
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

void deallocate(struct item* toBeDest,size_list* _size) {
	struct item* tmp; 
	if ((*_size) == 0) {

		exit(1);
	}
	tmp = toBeDest;
	free(tmp);
	toBeDest = NULL;
	(*_size)--;
}

void output(linkedList* _llist) {
	puts("\n");
	while (_llist->_head != NULL) {
		printf("%d ", _llist->_head->_val);
		_llist->_head = _llist->_head->_next;
	}
	puts("\n");
}

void push_back(linkedList* _llist,int val){
	struct item* ptr;
	if (_llist->_head == NULL) {
		(*_llist)._head = allocate();
		_llist->_head->_val = val;
		_llist->_head->_next = NULL;
		return;
	}
	ptr = _llist->_head;
	while (ptr != NULL) {
		ptr = ptr->_next;
	}
	ptr = allocate();
	ptr->_val = val;
}

void pop_back(linkedList* _llist) {
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

			deallocate(t, &_llist->_size);
			return;
		}
		/*
		iterator temp = t;
		free(t);
		temp = NULL;
		_llist->_size--;
		*/
		deallocate(t, &_llist->_size);

	}
	else {

	}
}

void push_front(linkedList* _llist, int val) {
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

void pop_front(linkedList* _llist) {
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


void initLinkedList(linkedList* l) {
	l->allocate = allocate;
/*	l->print = output;*/
	l->push_back = push_back;
	l->pop_back = pop_back;
	l->push_front = push_front;
	l->pop_front = pop_front;
	l->_head = NULL;
	l->_size = 0;
}



#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	linkedList* ll =initLinkedList();
	push_back(ll,10);
	push_back(ll,20);
	output(ll);
	free(ll);
	return 1;
}

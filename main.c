#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	linkedList* ll =initLinkedList();
/*	push_back(ll,10);
	push_back(ll,20);
	push_front(ll,33);

*/

	push_front(ll,10);
	push_front(ll,20);
	printf("%s",search(ll,50)==1 ? "Yes there is" : "No there is no");
	free(ll);
	
	return 1;
}

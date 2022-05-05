typedef struct linkedList linkedList;

struct linkedList* initLinkedList();
void push_back(struct linkedList* _llist,int val);
void output(struct linkedList* _llist);
void pop_back(struct linkedList* _llist);
void push_front(struct linkedList* _llist, int val);
void pop_front(struct linkedList* _llist);
void deleteNode(struct linkedList* _llist, int key);
int at(struct linkedList* _llist, unsigned long index);
void clear(struct linkedList* _llist);

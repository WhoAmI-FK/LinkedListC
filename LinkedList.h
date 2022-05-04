typedef struct linkedList linkedList;

struct linkedList* initLinkedList();
void push_back(struct linkedList* _llist,int val);
void output(struct linkedList* _llist);
void pop_back(struct linkedList* _llist);

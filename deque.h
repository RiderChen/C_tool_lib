typedef int bool;

#define true 1;
#define false 0;
struct node_t{
	struct node_t *next;
	struct node_t *prev;
	char msg[128];
};

typedef struct{
	struct node_t *head;
	struct node_t *tail;
	int size;
}deque_t;

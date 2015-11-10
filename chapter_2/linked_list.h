#define true 1
#define false 0

typedef struct _list_node {

  int value;
  struct _list_node *next;
  struct _list_node *prev; 

} *list_node;

typedef struct _list {

  int size;
  struct _list_node *head;
  struct _list_node *tail;

} *list;

typedef int bool;

list list_create();
list_node list_append(list l, int n);
void list_print(list l);
void list_print_reverse(list l);
void list_rm_dup(list l);
void list_rm_node(list l, list_node n);
void list_print_kth_to_last(list l, int k);
void list_move_node(list l, list_node moving, list_node position);
void list_partition_under_value(list l, int value);
void list_add(list l1, list l2);


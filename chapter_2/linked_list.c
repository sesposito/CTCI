#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linked_list.h"


list list_create(){

  list l;

  l = (list) malloc(sizeof(struct _list));
  l->size = 0;
  return l;

}

list_node list_append(list l, int n){

  list_node node;

  if(l->size == 0){
    node = (list_node) malloc(sizeof(struct _list_node));
    node->prev = NULL;
    node->next = NULL;
    node->value = n;
    l->head = node;
    l->tail = node;
    l->size++;
    return l->tail;
  }

  if(l->size > 0){
    node = (list_node) malloc(sizeof(struct _list_node));
    node->value = n;
    node->next = NULL;
    l->tail->next = node;
    node->prev = l->tail;
    l->tail = node;
    l->size++;
    return l->tail;
  }

  return NULL;

}


void list_print(list l){

  list_node current_node;

  if(l->size == 0){
    printf("List is empty\n");
    return;
  }

  current_node = l->head; 
  printf("List size: %d\n", l->size);
  printf("[%d]", current_node->value);
  current_node = current_node->next;
  
  while(current_node != NULL){

    printf("<->[%d]", current_node->value);
    current_node = current_node->next;  

  }
  
  printf("\n");

}

void list_print_reverse(list l){

  list_node current_node;

  if(l->size == 0){
    printf("List is empty\n");
    return;
  }

  current_node = l->tail; 
  printf("List size: %d\n", l->size);
  printf("[%d]", current_node->value);
  current_node = current_node->prev;
  
  while(current_node != NULL){

    printf("<->[%d]", current_node->value);
    current_node = current_node->prev;  

  }
  
  printf("\n");

}

void list_rm_dup(list l){

  int seen_values_size = 100;
  int seen_nodes = 0;
  int seen_values[seen_values_size];
  int val;
  int i;
  bool found;
  list_node node;
  
  node = l->head;
  while(node != NULL){
    val = node->value;
    found = false;
    for(i = 0; i < seen_nodes; i++){
      if(seen_values[i] == val){
        list_rm_node(l, node);
        found = true;
        break;
      }
    }
    if(found == false){
      seen_values[seen_nodes] = val;
      seen_nodes++;
    }
    node = node->next;
  }
}  

/*Moves nodes with values < n to the left of node with value n*/
void list_partition_under_value(list l, int val){

  list_node current, value_position, next_current;

  if(l->size == 0){
    printf("List is empty\n");
  }

  current = l->head;
  while(current != NULL){
    if(current->value == val){
      value_position = current;
      break;  
    }
    current = current->next;
  }
  
  while(current!= NULL){
    if(current->value < val){
      next_current = current->next;
      list_move_node(l, current, value_position);
      current = next_current;
    }else if(current->value == val){
      next_current = current->next;
      list_move_node(l, current, value_position);
      value_position = value_position->prev;
      current = next_current;
    }else{
      current = current->next;
    }
  }
}


void list_move_node(list l, list_node node, list_node position){

  if(l->size <= 1){
    printf("Cannot move elements from list with size <= 1\n");
  }
  if(position == node) return;

  if(node == l->head){
    l->head = node->next;
    l->head->prev = NULL;
  }else if(node == l->tail){
    l->tail = node->prev;
    node->prev->next = NULL;
  }else{
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  if(position == l->head){
    node->prev = NULL;
    node->next = l->head;  
    l->head = node;
  }else if(position == l->tail){
    node->next = l->tail;
    node->prev = l->tail->prev;
    node->prev->next = node; 
  }else{

    node->prev = position->prev;
    node->next = position;
    position->prev->next = node;
    position->prev = node;

  } 

}

void list_print_kth_to_last(list l, int k){

  int counter = 0;
  list_node current;

  if(l->size == 0){
    printf("List is empty\n");
  }

  current = l->head;
  counter++;
  
  while(current != NULL){
    if(counter == k){
      break;   
    }
    current = current->next;
    counter++;
  }
  
  while(current != NULL){
    if(current->next == NULL){
      printf("[%d]\n", current->value); 
    }else{
      printf("[%d]<->", current->value);
    }
    current = current->next;  
  }
}

void list_rm_node(list l, list_node n){

  if(l->size == 0){
    printf("Cannot remove node from empty list\n");
    return;
  }

  if(l->size == 1 && l->head == n){
    l->head = NULL;
    l->tail = NULL;
    l->size--;
    free(n);
    return;
  }

  if(l->head == n){
    l->head = l->head->next;
    l->head->prev = NULL;
    l->size--;
    free(n);
    return;  
  }

  if(l->tail == n){
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    l->size--;
    free(n);
    return;
  }

  n->next->prev = n->prev;
  n->prev->next = n->next;
  free(n);
  return;  

}

void list_add(list l1, list l2){

  int value_l1, value_l2;
  int decimal_point, result, i, n;
  list_node current;
  char c, str[20];
  list result_list;
  
  value_l1 = 0;
  current = l1->head;
  decimal_point = 1;
  while(current != NULL){
    value_l1 += current->value * decimal_point;
    decimal_point *= 10;
    current = current->next;
  }

  value_l2 = 0;
  current = l2->head;
  decimal_point = 1;
  while(current != NULL){
    value_l2 += current->value * decimal_point;
    decimal_point *= 10;
    current = current->next;
  }

  result = value_l1 + value_l2;
  
  sprintf(str, "%d", result);
  result_list = list_create();
  for(i = strlen(str)-1; i >= 0; i--){
    c = str[i];
    n = c - '0';
    list_append(result_list, n);
  }

  list_print(result_list);

}

void list_add_reverse(list l1, list l2){

  int value_l1, value_l2;
  int decimal_point, result, i, n;
  list_node current;
  char c, str[20];
  list result_list;

  value_l1 = 0;
  current = l1->head;
  decimal_point = pow(10, l1->size-1);
  while(current != NULL){
    value_l1 += current->value * decimal_point;
    decimal_point /= 10;
    current = current->next;
  } 

  value_l2 = 0;
  current = l2->head;
  decimal_point = pow(10, l2->size-1);
  while(current !=NULL){
    value_l2 += current->value * decimal_point;
    decimal_point /= 10;
    current = current->next;
  } 

  result = value_l1 + value_l2;
  
  result_list = list_create();
  sprintf(str, "%d", result);
  for(i = 0; i < strlen(str); i++){
    c = str[i];
    n = c - '0';
    list_append(result_list, n);
  }
  
  list_print(result_list);

}

void list_detect_loop(list l){
  
  list_node current;
  list_node seen_nodes[100];
  int i, n_seen_nodes;
  bool match_found;

  n_seen_nodes = 0;
  current = l->head;
  while(current != NULL){
    match_found = false;
    for(i = 0; i < n_seen_nodes; i++){
      if(current == seen_nodes[i]){
        match_found = true;
        printf("Was found loop at node with value: %d\n", current->value);
        return;
      } 
    }
    if(match_found == false){
      seen_nodes[n_seen_nodes] = current;   
    }
    n_seen_nodes++;
    current = current->next;
  } 
  
  printf("No loop was found\n");
}

void list_is_palindrome(list l){
  
  int seen_count;
  int stop_value;
  list_node left;
  list_node right;

  stop_value = (l->size / 2);
  left = l->head;
  right = l->tail; 
  for(seen_count = 0; seen_count < stop_value; seen_count++){

    if(left->value == right->value){
      left = left->next;
      right = right->prev;
      continue;
    }else{
      printf("The list is not a palindrome\n");
      return;
    }
  }
  printf("The list is a palindrome\n");
}


int main() {

  /*
  list l1 = list_create();
  list l2 = list_create();
  list_node n;

  list_append(l1, 7);
  list_append(l1, 1);
  list_append(l1, 6);

  list_append(l2, 5);
  list_append(l2, 9);
  list_append(l2, 2);

  list_add_reverse(l1, l2);
  */

  list l;
  /*list_node node1, node2;*/

  l = list_create();

  list_append(l, 1);
  list_append(l, 2);
  list_append(l, 3);
  list_append(l, 3);
  list_append(l, 2);
  list_append(l, 1);
  list_print(l);
  list_is_palindrome(l);

  return 0;

}

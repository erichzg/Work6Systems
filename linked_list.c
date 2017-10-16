#include <stdlib.h>
#include <stdio.h>

struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

struct node {
  int i;
  struct node *next;
};

void print_list(struct node * start) {
  while (start) {
    printf("%d\n", start -> i);
    start = start -> next;
  }
}

struct node * insert_front(struct node * start, int value) {
  struct node * retNode = (struct node *) malloc(sizeof(struct node));
  retNode -> i = value;
  retNode -> next = start;
  return retNode;
}

struct node * free_list(struct node * start) {
  if (!start) {
    return 0;
  }
  free_list(start -> next);
  free(start);
  return 0;
}

int main(){
  struct node * start = 0;
  start = insert_front(start, 1);
  print_list(start);
  printf("printing out a single node, should just be 1\n");
  int x = 2;
  while (x <= 5) {
    start = insert_front(start, x);
    x++;
  }
  print_list(start);
  printf("printing the linked list, should be 5 4 3 2 1\n");
  free_list(start);
  print_list(start);
  printf("after freeing, should be nothing\n");
  
}

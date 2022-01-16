#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sonia{

  int data;
  struct sonia *next;

};

struct sonia *add_to_list(struct sonia *first, int n){
  struct sonia *new_node;
  new_node = malloc(sizeof(struct sonia));

  new_node->data = n;

  new_node->next = first;
  first = new_node;

  return first;
}

void display(struct sonia *first){

  while(first != NULL){
    printf("%d -> ", first->data);
    first = first->next;
  }

  printf("NULL\n");
}

bool search(struct sonia *first, int x){
  while(first != NULL){
    if(first->data == x)
      return true;
    first = first->next;
  }
  return false;
}

int main(void){
  struct sonia *list;
  list = NULL; bool y;

  for(int i = 1; i <= 15; i++){
    list = add_to_list (list, i);
  }

  y = search(list, 8);

  display(list);

  if(y){
    printf("Found!\n");
  } else {
    printf("Not found!\n");
  }

  return 0;
}

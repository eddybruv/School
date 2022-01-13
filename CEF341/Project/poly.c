#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Poly_Node {
  int coefficient;
  int index;
  struct Poly_Node *next;
};

void create_poly(struct Poly_Node **);
void display_poly(struct Poly_Node *);
double eval_Poly(struct Poly_Node *, double);

int main(void){
  struct Poly_Node *poly1, *tracker;
  poly1 = tracker = NULL;
  char x;

  printf("Add node to polynomial (y | n)?: ");
  scanf("%c", &x);

  while(x == 'y' || x == 'Y'){
    if(poly1 == NULL){
      create_poly(&poly1);
      tracker = poly1;
    }
    else {
      create_poly (&tracker);
    }

    printf("Add node to polynomial (y | n)?: ");
    scanf(" %c", &x);
  }

  double ans = eval_Poly (poly1, 8.0);
  printf("P(8) = %.2lf \n", ans);
  display_poly(poly1);
  return 0;
}

void create_poly(struct Poly_Node **P){
  struct Poly_Node *newNode;
  newNode = malloc(sizeof(struct Poly_Node));

  printf("Enter coefficient: ");
  scanf("%d", &newNode->coefficient);
  printf("Enter index: ");
  scanf("%d", &newNode->index);

  if(newNode->index < 0){
    printf("Index can not be less than 0, input a correct index: ");
    scanf("%d", &newNode->index);
  }

  if(*P == NULL){
    //first node in the polynomial
    *P = newNode;
    (*P)->next = NULL;
  }

  else {
    (*P)->next = newNode;
    (*P) = (*P)->next;
    (*P)->next = NULL;
  }

}

void display_poly(struct Poly_Node *P){
  if(P == NULL){
    printf("No polynomial to be displayed.\n");
    return;
  }
  
  while(P != NULL){
    if(P->index > 1){
      printf("(%d)x^%d + ", P->coefficient, P->index);
      P = P->next;
    }

    else if(P->index == 1){
      printf(" (%d)x + ", P->coefficient);
      P = P->next;
    }

    else {
      printf(" (%d)", P->coefficient);
      P = P->next;
    }

  }

  printf(" = 0\n");
}

double eval_Poly(struct Poly_Node *P, double x){

  double sum = 0;
  while (P != NULL){
    sum += (double) P->coefficient * (pow(x, (double)P->index));
    P = P->next;
  }


  return sum;
}

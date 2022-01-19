#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1: Linked list
typedef struct info
{
    int code;
    int type;
    char desc[30];
    struct info *next;
} Info;

// 2 :
Info *insert_object(Info *head)
{
    Info *new_object;
    new_object = malloc(sizeof(Info));

    printf("Enter object code: ");
    scanf("%d", &new_object->code);
    printf("Enter object type: ");
    scanf("%d", &new_object->type);
    printf("Enter short description: ");
    scanf(" %[^\n]*s", new_object->desc);

    new_object->next = head;
    head = new_object;

    return head;
}

// 3:
void delete_object(Info *head){
    Info *del, *prev;
    prev = NULL;
    int x;

    printf("Enter code of element to be deleted: ");
    scanf("%d", &x);

    while(head->code != x && head != NULL){
        prev = head;
        head = head->next;
    }
    del = head;
    prev->next = head->next;

    free(del);
}

//4:
bool search(Info *head){
    int x;
    printf("Enter code to search: ");
    scanf("%d", &x);

    while (head != NULL){
        if(head->code == x){
            printf("Found!\n");
            return true;
        }
        head = head->next;
    }

    printf("Not Found!\n");
    return false;
}

void display(Info *head){
    printf("Code    Type  Description\n");
    while(head != NULL){
        printf(" %d       %d    %s\n", head->code, head->type, head->desc);
        head = head->next;
    }
}

Info *merge(Info *head_a, Info *head_b){

}

int main(void){
    Info *head;
    head = NULL;

    for(int i = 0; i < 6;i++){
        head = insert_object(head);
    }

    display(head);
    delete_object(head);
    delete_object(head);
    display(head);
    search(head);

    return 0;
}
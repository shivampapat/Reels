#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
} NODE;

typedef NODE* PNODE;
typedef PNODE* PPNODE;

void insertFirst(PPNODE headPtr, int data){
    PNODE newNode = (PNODE)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    if(*headPtr == NULL){
        *headPtr = newNode;

    }
    else{
        newNode->next = *headPtr;
        *headPtr = newNode;
    }
}

void printLinkedList(PNODE head){

    printf("Linked List Data:\n");
    while(head != NULL){
        printf("%d\n" , head->data);
        head = head->next;
    }
}

int deleteNode(PPNODE head, NODE target){
    if(head == NULL){
        printf("Empty Linked List");
        return -1;
    }

    PNODE curr = *head;
    PNODE prev = NULL;
    while(curr != NULL){
        if(curr->data == target.data){ //you can compare whole data later
            printf("Deleting node with data %d\n", target.data);
            if(prev != NULL){
                prev->next = curr->next;
            }
            else{
                *head = curr->next;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return 1;
}

int proDeleteNode(PPNODE head, NODE target){
    if(head == NULL){
        printf("Empty Linked List");
        return -1;
    }

    PPNODE curr = head;
    while(curr != NULL){
        if((*curr)->data == target.data){
            printf("Deleting node with data %d\n", target.data);
            *curr = (*curr)->next;
            break;
        }
        curr = &((*curr)->next);
    }
    return 1;
}


int main()
{
    PNODE head;

    insertFirst(&head,41);
    insertFirst(&head,31);
    insertFirst(&head,21);
    insertFirst(&head,11);

    printLinkedList(head);

    NODE target;
    target.data = 31;
    target.next = NULL;
    proDeleteNode(&head, target);

    printLinkedList(head);

    return 0;
}

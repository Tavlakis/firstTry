#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("The node is corrupted!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *insertAtHead(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return head;
    }

    newNode->next = head;
    /*
    if(head->data == NULL){
        head->data = newNode->data;
        head->next = NULL;
    }
    else{
        struct node *temp = head;
        head->data = newNode->data;
        head->next = temp->next;
        temp->next = NULL;
    }
        */
    return newNode;
}

struct node *insertAtTail(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    struct node *temp = head;
    if (head == NULL)
    {
        return newNode;
    }
    if (newNode == NULL)
    {
        printf("The node is corrupted!\n");
        return NULL;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node *searchNode(struct node *head, int key)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct node *deleteNode(struct node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *temp = head;
    struct node *temp1 = NULL;
    while (temp != NULL && temp->data != key)
    {
        temp1 = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return head;
    }
    temp1->next = temp->next;
    free(temp);
    return head;
}

void *printList(struct node *head)
{
    struct node *temp = head;
    printf("Data entered in the list:\n");
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;

    head = insertAtTail(head,10);
    head = insertAtTail(head,20);
    head = insertAtTail(head,30);
    head = insertAtHead(head,98);

    printList(head);

    deleteNode(head,20);
    
    printList(head);

    return 0;
}
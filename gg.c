#include <stdio.h>
#include <string.h>
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
        return NULL; // an h lista einai adeia
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
        return NULL;
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
    int value, choise;

state:
    printf("Choose an option:\n1)Insert at head\n2)Insert at Tail\n3)Search for a node\n4)Delete a node\n");
    scanf("%d", &choise);

    while (choise < 1 || choise > 4)
    {
        printf("Wrong choise! Please re-enter your choise!");
        scanf("%d", &choise);
    }
    printf("If you want to change your choise, enter '0'\n");
    printf("If you want to stop the input, type -1\n");

    if (choise == 1 || choise == 2)
    {
        while (1)
        {
            printf("Value: ");
            scanf("%d", &value);

            if (value == -1)
            {
                break;
            }
            if (value == 0)
            {
                goto state;
            }
            if (choise == 1)
            {
                head = insertAtHead(head, value);
            }
            else
            {
                head = insertAtTail(head, value);
            }
        }
    }
    else if (choise == 3)
    {
        char c, v;
        do
        {
            printf("Give a node to search: ");
            int a;
            scanf("%d", &a);
            if (a == 0)
            {
                goto state;
            }
            if (searchNode(head, a) == NULL)
            {
                printf("The node doesn't exist!\n");
            }
            else
            {
                printf("The node you searched for exists!\n");
            }
            printf("Do you want to search for another Node? (y/n)\n");
            scanf("%c", c);
            while (c != 'y' && c != 'n')
            {
                printf("Wrong choise! Try again\n");
                scanf("%c", c);
            }
        } while (c == 'y');
    }
    else if (choise == 4)
    {   
        int b;
        char c;
        do
        {   
        printf("What to delete? : ");
        scanf("%d", b);
        if (b == 0)
        {
            goto state;
        }
        if (deleteNode(head, b) == NULL)
        {
            printf("The node you entered, doesn't exist!\n");
        }
        else
        {
            printf("Node successufully deleted!\n");
        }
        printf("Do you want another node deleted?(y/n)\n");
        scanf("%c", c);
        while (c != 'y' || c != 'n')
        {
            printf("Wrong choise, Try again!\n");
            scanf("%c", c);
        }
            /* code */
        } while (c == 'y');

    }

    printList(head);

    return 0;
}
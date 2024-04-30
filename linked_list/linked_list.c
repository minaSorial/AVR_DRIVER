
#include "STD_TYPES.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void printNode(const struct node *currNode)
{

    printf(" Node ID : %d , Value : %d \n ", currNode->idx, currNode->value);
}

/*
void _hleper_print( const struct node * currNode )
{
    printNode(currNode);
    if( currNode->next != STD_NULL){
        _hleper_print(currNode->next);
    }



};
*/

void printList(const struct linked_list *list)
{

    //_hleper_print(list->head);

    struct node *curr = list->head;
    if (curr == STD_NULL)
    {

        printf("List is empty");
    }

    while (curr != STD_NULL)
    {
        printNode(curr);
        curr = curr->next;
    }

    return;
}

struct node *createNode(void)
{

    return (struct node *)malloc(sizeof(struct node));
}

void append(struct linked_list *list, struct node *currNode)
{

    if (list->head == STD_NULL)
    {

        list->head = currNode;
    }
    else
    {

        struct node *temp = list->tail;

        temp->next = currNode;
        currNode->before = temp;
        currNode->next=STD_NULL;
        list->tail = currNode;
    }

    return;
}

struct node *search(const struct linked_list *list, u8 id)
{

    struct node *result;

    struct node *curr = list->head;
    if (curr == STD_NULL)
    {
        result = STD_NULL;
        printf("List is empty");
    }else{
    while (curr != STD_NULL)
    {
        if (curr->idx == id)
        {
            result = curr;
            break;
        }
        else
        {
            curr = curr->next;
        }
    }
     //printf("Node with such id doesn't exist");
    }

    return result;
}

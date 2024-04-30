#ifndef LINKED_LIST_H
#define LINKED_LIST_H



struct node {

    u8 idx;
    u8 value;
    struct node * before;
    struct node * next;

};

struct linked_list
{

   struct  node * head;
   struct  node* tail ;

};

void printNode( const struct node * currNode );
void printList( const struct linked_list * list );


struct node * createNode(void);

void append( struct linked_list * list ,struct node * currNode );




struct node *search(const struct linked_list *list, u8 id);









#endif // LINKED_LIST_H
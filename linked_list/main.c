#include "STD_TYPES.h"
#include "linked_list.h"
int main(void)
{

    struct linked_list hamo;

    struct  node first ={.idx = 1 , .value =10};
    struct  node sec ={.idx = 2 , .value =20};
    struct  node third ={.idx = 3 , .value =30};

    hamo.head=&first;
    first.before=STD_NULL;
    first.next=&sec;
    
    sec.before=&first;
    sec.next=&third;

    third.before=&sec;
 
    
    //hamo.tail=&third;


  
    struct node * fourth= createNode();
    fourth->idx=4;
    fourth->value=40;
    third.next=fourth;
    fourth->before=&third;
    fourth->next=STD_NULL;

    hamo.tail=fourth;

   

  struct node * five= createNode();
    five->idx=5;
    five->value=50;

    append(&hamo,five);
    printList(&hamo);


 printNode(search(&hamo,3));


    



    return 0;
}
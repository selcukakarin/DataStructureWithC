#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    n * next;
};
typedef n node;

int main(){
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> data =10;
    root -> next = (node *) malloc (sizeof(node));
    root -> next -> data =20;
    root -> next -> next = (node *) malloc (sizeof(node));
    node * iter;
    iter = root;
    printf("%d \n",iter->data);
    iter = iter -> next;
    printf("%d",iter->data);
}

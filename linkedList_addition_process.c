#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n * next;
};
typedef struct n node;

void bastir(node * r){
    while(r!=NULL){
        printf("\n%d ", r -> data);
        r = r -> next;
    }
}

void ekle(node *r, int data){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next =(node *)malloc(sizeof(node));
    r -> next -> data = data;
    r -> next -> next = NULL;
}

int main(){
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> data =500;
    root -> next = NULL;
    int i = 0;

    for(i=0;i<5;i++){
        ekle(root,i*10);
    }

    bastir(root);

    node * iter = root;
    for(i=0;i<3;i++){
        iter = iter -> next;
    }
    node * temp =(node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = 100;
    bastir(root);
}

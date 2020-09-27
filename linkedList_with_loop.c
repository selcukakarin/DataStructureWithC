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
    root -> data =10;
    root -> next = NULL; // eğer diğer açıklama satırları açılacaksa bu satır kapatılır.
    // root -> next = (node *) malloc (sizeof(node));
    // root -> next -> data = 20;
    // root -> next -> next = (node *) malloc (sizeof(node));
    // root -> next -> next -> data = 30;
    // root -> next -> next -> next = NULL;
    node * iter;
    // iter = root;
    // printf("%d \n",iter->data);
    // iter = iter -> next;
    // printf("%d",iter->data);

    iter = root;
    int i = 0;
    // while (iter -> next != NULL){
    //     i++;
    //     printf("\n%d inci eleman : %d",i,iter->data);
    //     iter = iter -> next;
    // }

    for(i=0;i<5;i++){
        ekle(root,i*10);
        // iter -> next = (node *)malloc(sizeof(node));
        // iter = iter -> next;
        // iter -> data = i*10;
        // iter -> next = NULL;
    }

    bastir(root);
}

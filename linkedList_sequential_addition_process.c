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

node * ekleSirali(node * r, int data){
    if(r==NULL){  // linked list boş ise bir node oluşturup içine değer koyuyor
        r=(node *)malloc(sizeof(node));
        r->next=NULL;
        r->data=data;
        return r;
    }
    if(r -> data > data){  // eklenen elemanın ilk elemandan küçük olma durumu - rootun değişme durumu
        node * temp = (node *)malloc(sizeof(node));
        temp -> data = data;
        temp -> next = r;
        return temp;
    }
    node * iter = r;
    while(iter -> next != NULL && iter -> next -> data < data){ // eğer liste boş değilse iteri linked listin datadan büyük ilk elemanına götürüyoruz.
        iter = iter -> next;
    }
    
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = data;
    return r;
}

int main(){
    node * root;
    root = NULL;
    root = ekleSirali(root,400);
    root = ekleSirali(root,500);
    root = ekleSirali(root,10);
    root = ekleSirali(root,1);
    root = ekleSirali(root,50);
    
    bastir(root);
}

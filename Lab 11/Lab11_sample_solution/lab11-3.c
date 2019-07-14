#include<stdio.h>
#include<stdlib.h>
typedef struct ns
{
    int value;
    struct ns* right;
    struct ns* left;
} node;
node* create_node(int);
node* insert_right(node*,int);
node* insert_left(node*,int);
node* move_right(node*);
node* move_left(node*);
node* remove_node(node*);
void print_list(node*);
int iter=-1;
int main(){
    node* list = NULL;
    printf("Functions:(1)insert_left (2)insert_right (3)move_left\n          (4)move_right  (5)remove_node  (6)print_list\n");
    while(1){
        while(1){
            int n=0;
            printf("Select functions:");
            scanf("%d",&n);
            if(n==1){
                int val=0;
                printf("Input the value:");
                scanf("%d",&val);
                list=insert_left(list,val);
            }
            else if(n==2){
                int val=0;
                printf("Input the value:");
                scanf("%d",&val);
                list=insert_right(list,val);
            }
            else if(n==3){
                list=move_left(list);
            }
            else if(n==4){
                list=move_right(list);
            }
            else if(n==5){
                list=remove_node(list);
            }
            else if(n==6){
                print_list(list);
                printf("\n");
            }
            else{
                printf("Invalid function!\n");
                break;
            }
            if(iter>=0){
                printf("Iterator:Node%d  Value:%d\n",iter,list->value);
            }
            printf("\n");
        }

    }

    system("pause");
}
node* create_node(int value)
{
    node* n = (node*)malloc(sizeof(node));
    n->value = value;
    n->right = NULL;
    n->left=NULL;
    return n;
}
node* insert_right(node* n1,int value){
    node* n2=create_node(value);
    if(n1==NULL){
        n1=n2;
        iter=0;
    }
    else{
        if(n1->right==NULL){
            n1->right=n2;
            n2->left=n1;
        }
        else{
            n1->right->left=n2;
            n2->right=n1->right;
            n1->right=n2;
            n2->left=n1;
        }
    }
    return n1;
}
node* insert_left(node* n1,int value){
    node* n2=create_node(value);
    if(n1==NULL){
        n1=n2;
        iter=0;
    }
    else{
        iter+=1;
        if(n1->left==NULL){
            n1->left=n2;
            n2->right=n1;
        }
        else{
            n1->left->right=n2;
            n2->left=n1->left;
            n1->left=n2;
            n2->right=n1;
        }
    }
    return n1;
}
node* move_right(node* n1){
    if(n1==NULL){
        printf("Cannot move to the right node\n");
        return n1;
    }
    else{
        if(n1->right!=NULL){
            n1=n1->right;
            iter+=1;
            return n1;
        }
        else{
            printf("Cannot move to the right node\n");
            return n1;
        }
    }
}
node* move_left(node* n1){
    if(n1==NULL){
        printf("Cannot move to the left node\n");
        return n1;
    }
    else{
        if(n1->left!=NULL){
            n1=n1->left;
            iter-=1;
            return n1;
        }
        else{
            printf("Cannot move to the left node\n");
            return n1;
        }
    }
}
node* remove_node(node* n1)
{
    if(n1==NULL){
        printf("Cannot remove node from empty list\n");
        return n1;
    }
    else{
        if(n1->right==NULL && n1->left==NULL){
            node* tmp=n1;
            n1=NULL;
            iter=-1;
            free(tmp);
            return n1;
        }
        else if(n1->right==NULL){
            node* tmp=n1->left;
            n1->left->right=NULL;
            n1->left=NULL;
            free(n1);
            iter-=1;
            return tmp;
        }
        else if(n1->left==NULL){
            node* tmp=n1->right;
            n1->right->left=NULL;
            n1->right=NULL;
            free(n1);
            return tmp;
        }
        else{
            node* tmp=n1->left;
            n1->left->right=n1->right;
            n1->right->left=n1->left;
            n1->left=NULL;
            n1->right=NULL;
            free(n1);
            iter-=1;
            return tmp;
        }
    }
}

void print_list(node* list)
{
    node* n = list;
    if(n==NULL){
        printf("Empty list\n");
    }
    else{
        while(n->left!=NULL){
            n=n->left;
        }
        printf("List:%d", n->value);
        while (n->right != NULL){
            n = n->right;
            printf("->%d", n->value);
        }
        printf("\n");
    }


}


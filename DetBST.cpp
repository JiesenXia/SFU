#include<iostream>

using namespace std;

struct node{
   int data;
   struct node *left;
   struct node *right;
};


int minValue(struct node *node){
   struct node *current=node;
   while(current->left!=NULL){
       current=current->left;
   }
   return(current->data);
}


int maxValue(struct node *node){
   struct node *current=node;
   while(current->right!=NULL){
       current=current->right;
   }
   return(current->data);
}

int DetBST1(struct node *node){
  
  
   if (node == NULL)
return 1;
  

if (node->left != NULL && node->left->data > node->data)
return 0;
  

if (node->right != NULL && node->right->data < node->data)
return 0;
  

if (!DetBST1(node->left) || !DetBST1(node->right))
return 0;
  
  
return 1;
}


int BSTUtil(struct node *node,int min,int max){
  
  

   if (node==NULL)
return 1;
  
  
if (node->data < min || node->data > max)
return 0;
  

return BSTUtil(node->left, min, node->data-1) && BSTUtil(node->right, node->data+1, max);
}

int DetBST2(struct node *node){
   return(BSTUtil(node,INT_MIN,INT_MAX)) ;
}


void infix(struct node *node){
   if(node==NULL){
       return;
   }
   else{
       infix(node->left);
       cout<<node->data<<" ";
       infix(node->right);
   }
}


int main(){
   struct node *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10,*n11;
   n1=new struct node;
   n2=new struct node;
   n3=new struct node;
   n4=new struct node;
   n5=new struct node;
   n6=new struct node;
   n7=new struct node;
   n8=new struct node;
   n9=new struct node;
   n10=new struct node;
   n11=new struct node;
  
  
   n1->data=1;
   n2->data=2;
   n3->data=3;
   n4->data=4;
   n5->data=5;
   n6->data=6;
   n7->data=7;
   n8->data=8;
   n9->data=9;
   n10->data=10;
   n11->data=11;
  
  
   n1->left=NULL;
   n1->right=NULL;
  
   n2->left=n1;
   n2->right=NULL;
  
   n4->left=NULL;
   n4->right=NULL;
  
   n3->left=n2;
   n3->right=n4;
  
  
  
  
  
   n8->left=NULL;
   n8->right=NULL;
  
   n9->left=n8;
   n9->right=NULL;
  
  
   n6->left=NULL;
   n6->right=NULL;
  
  
   n7->left=n6;
   n7->right=n9;
  
   n11->left=NULL;
   n11->right=NULL;
  
   n10->left=n7;
   n10->right=n11;
  
   // n5 is root
   n5->left=n3;
   n5->right=n10;
  
  
   cout<<"Infix : ";
   infix(n5);
  
   cout<<endl<<"DetBST1 : "<<DetBST1(n5);
   cout<<endl<<"DetBST2 : "<<DetBST2(n5);
  
   cout<<endl;
  
   system("pause");
   return 0;
}

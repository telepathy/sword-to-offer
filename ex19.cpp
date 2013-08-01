#include <cstdio>
struct node
{
  int val;
  node *left,*right;
  node(int x,node* l=NULL,node* r=NULL):val(x),left(l),right(r){}
};
node* createT1();
void desTree(node*);
void wt(node*);
node* mirror(node*);
int main()
{
  node *root=createT1();
  wt(root);
  root=mirror(root);
  wt(root);
  return 0;
}
void wt(node* root)
{
  if(root)
  {
    printf("%d ",root->val);
    wt(root->left);
    wt(root->right);
  }
}
node* mirror(node* root)
{
  if(root)
  {
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    root->left=mirror(root->left);
    root->right=mirror(root->right);
  }
  return root;
}
node* createT1()
{
  node *p1,*p2,*p3,*p4,*p5,*p6,*p7;
  p1=new node(4);
  p2=new node(7);
  p3=new node(2,p1,p2);
  p4=new node(9);
  p5=new node(8,p4,p3);
  p6=new node(7);
  p7=new node(8,p5,p6);
  return p7;
}
void desTree(node *root)
{
  if(root)
  {
    desTree(root->left);
    desTree(root->right);
    delete root;
  }
}
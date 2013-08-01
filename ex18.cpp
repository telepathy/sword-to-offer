#include <cstdio>
struct node
{
  int val;
  node *left,*right;
  node(int x,node* l=NULL,node* r=NULL):val(x),left(l),right(r){}
};
node* createT1();
node* createT2();
void desTree(node*);
bool SubTree(node*,node*);
bool SameTree(node*,node*);
int main()
{
  node *t1=createT1();
  node *t2=createT2();
  printf("%d",SubTree(t1,t2));
  desTree(t1);
  desTree(t2);
  return 0;
}
bool SubTree(node* m,node *s)
{
  if(m==NULL) return false;
  if(s==NULL) return true;
  return SameTree(m,s)||SubTree(m->left,s)||SubTree(m->right,s);
}
bool SameTree(node *t1,node *t2)
{
  if(t1 && t2) //t1!=NULL t2!=NULL
  {
    if(t1->val!=t2->val) return false;
    return (SameTree(t1->left,t2->left))&&(SameTree(t1->right,t2->right));
  }
  else if(t2==NULL) 
    return true;
  else 
    return false;
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
node* createT2()
{
  node *p1,*p2,*p3;
  p1=new node(9);
  p2=new node(2);
  p3=new node(8,p1,p2);
  return p3;
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

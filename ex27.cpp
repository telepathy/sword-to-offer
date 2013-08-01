#include <cstdio>
struct node
{
  int val;
  node *left,*right;
  node(int x,node *l=NULL,node *r=NULL):val(x),left(l),right(r){}
};
void change(node*,node*&);
node* work(node*);
int main()
{
  node p1(4),p2(8),p3(6,&p1,&p2);
  node p4(12),p5(16),p6(14,&p4,&p5);
  node p7(10,&p3,&p6);
  node* h=work(&p7);
  node *p;
  while (h)
  {
    printf("%d ",h->val);
    p=h;
    h=h->right;
  }
  while (p)
  {
    printf("%d ",p->val);
    p=p->left;
  }
  return 0;
}

node* work(node* root)
{
  node* l=NULL;
  change(root,l);
  while(l->left) l=l->left;
  return l;
}
void change(node* r,node *&last)
{
  if(r==NULL) return;
  if (r->left) 
    change(r->left,last);
  r->left=last;
  if(last)
    last=last->right=r;
  else
    last=r;
  if (r->right) 
    change(r->right,last);
}

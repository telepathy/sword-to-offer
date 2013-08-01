#include <cstdio>
#include <deque>
struct node
{
  int val;
  node *left,*right;
  node(int x,node* l=NULL,node* r=NULL):val(x),left(l),right(r){}
};
node* create()
{
  node *p1,*p2,*p3,*p4,*p5,*p6,*p7;
  p1=new node(9);
  p2=new node(11);
  p3=new node(10,p1,p2);
  p4=new node(5);
  p6=new node(7);//
  //p6=NULL;
  p5=new node(6,p4,p6);
  p7=new node(8,p5,p3);
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
int main()
{
  node *root=create();
  std::deque<node*> q;
  q.push_back(root);
  while(!q.empty())
  {
    if(q.front())
    {
      printf("%d ",q.front()->val);
      q.push_back(q.front()->left);
      q.push_back(q.front()->right);
    }
    q.pop_front();
  }
  desTree(root);
  return 0;
}
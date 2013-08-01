#include <cstdio>
#include <vector>
struct node
{
  int val;
  node *left,*right;
  node(int x,node* l=NULL,node* r=NULL):val(x),left(l),right(r){}
};
void solve(std::vector<int>&,node*,int);
void desTree(node*);
node* create();
bool isLeaf(node*);
int main()
{
  std::vector<int> v;
  int x;
  scanf("%d",&x);
  node *tree=create();
  v.push_back(tree->val);
  solve(v,tree,x-tree->val);
  desTree(tree);
}
bool isLeaf(node* r) 
{
  return (!(r->left || r->right));
}
void solve(std::vector<int>& path, node* r,int sum)
{
  if((sum==0)&&(isLeaf(r)))
  {
    for(std::vector<int>::iterator i=path.begin();i!=path.end();++i)
      printf("%d ",*i);
    printf("\n");
    return;
  }
  else if((sum<0)||(r==NULL)) return;
  else
  {
    if(r->left)
    {
      path.push_back(r->left->val);
      solve(path,r->left,sum-r->left->val);
      path.pop_back();
    }
    if(r->right)
    {
      path.push_back(r->right->val);
      solve(path,r->right,sum-r->right->val);
      path.pop_back();
    }
    return;
  }

}
node* create()
{
  node *p1,*p2,*p3,*p4,*p5;
  p1=new node(4);
  p2=new node(7);
  p3=new node(5,p1,p2);
  p4=new node(12);
  p5=new node(10,p3,p4);
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

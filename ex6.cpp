#include <cstdio>
struct BinaryTreeNode
{
  int m_nValue;
  BinaryTreeNode *m_pLeft;
  BinaryTreeNode *m_pRight;
};
BinaryTreeNode* buildTree(int*,int*,int);
void printF(BinaryTreeNode*);
void printM(BinaryTreeNode*);
int main()
{
  int f[]={1,2,4,7,3,5,6,8};
  int m[]={4,7,2,1,5,3,8,6};
  BinaryTreeNode *root=buildTree(f,m,8);
  printF(root);
  printM(root);
  return 0;
}
BinaryTreeNode* buildTree(int* f,int *m,int size)
{
  if (size==0) return NULL;
  int i;
  for(i=0;i<size;++i)
    if (f[0]==m[i]) break;
  if (i==size) return NULL;
  BinaryTreeNode *ret=new BinaryTreeNode();
  ret->m_nValue=f[0];
  ret->m_pLeft=buildTree(f+1,m,i);
  ret->m_pRight=buildTree(f+i+1,m+i+1,size-i-1);
  return ret;
}
void printF(BinaryTreeNode* r)
{
  if (r==NULL) return;
  printf("%d",r->m_nValue);
  printF(r->m_pLeft);
  printF(r->m_pRight);
}
void printM(BinaryTreeNode* r)
{
  if (r==NULL) return;
  printM(r->m_pLeft);
  printf("%d",r->m_nValue);
  printM(r->m_pRight);
}
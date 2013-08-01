#include <cstdio>
struct node{
  int val;
  node *next;
  node(int x):val(x),next(NULL){}
};
void print(node*);
node* reverse(node*);
int main()
{
  node n1(1),n2(2),n3(3),n4(4);
  //n1.next=&n2;
  //n2.next=&n3,n3.next=&n4;
  node *head=&n1;
  print(head);
  head=reverse(head);
  print(head);
  return 0;
}
void print(node *head)
{
  while(head)
  {
    printf("%d ",head->val);
    head=head->next;
  }
  printf("\n");
  return;
}
node* reverse(node* head)
{
  if(head==NULL) return NULL;
  node *pre=NULL,*n=head->next;
  while(n)
  {
    head->next=pre;
    pre=head;
    head=n;
    n=n->next;
  }
  head->next=pre;
  return head;
}
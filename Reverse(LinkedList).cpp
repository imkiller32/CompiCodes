Node* reverse(Node *head)
{
  Node *t1=NULL,*t2;
  while(head->next)
  {
      t2=head->next;
      head->next=t1;
      t1=head;
      head=t2;
  }
  head->next=t1;
  return head;
}

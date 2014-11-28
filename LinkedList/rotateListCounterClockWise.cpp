#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int value;
	node * next;
};

node * createNewNode(int data)
{
	node * p = new node;
	p->value = data;
	p->next = NULL;
	return p;
}

void insertNode(node ** head,int data)
{
	node * p = createNewNode(data);
	if((*head)==NULL)
		(*head) = p;
	else
	{
		node * q = (*head);
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next = createNewNode(data);

	}
}

void rotate(node ** head, int k)
{
	int counter = 1;
	node * p = (*head);
	while(counter < k)
	{
		p = p->next;
		counter++;
	}
	cout<<"\nKth node is:"<<p->value;
	node * kthnode = p;

	while(p->next!=NULL)
		p=p->next;

	cout<<"\nlast node is:"<<p->value<<endl;
	p->next = (*head);
	(*head) = kthnode->next ;
	kthnode->next = NULL;
	//p->next = NULL;
}

void printList(node * head)
{
	while(head)
	{
		cout<<head->value<<" ";
		head = head->next;
	}
}

int main()
{
	int n,d,i;
	cout<<"Enter the no of nodes:";
	cin>>n;
	node * head=NULL;
	for(i=0;i<n;i++)
	{
		cin>>d;
		insertNode(&head,d);
	}
	cout<<"Before Reversal\n";
	printList(head); cout<<endl;
	long long int k;
	cout<<"Enter k:"; cin>>k;
	rotate(&head,k%n);

	printList(head); cout<<endl;
}
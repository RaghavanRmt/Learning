#include<stdio.h>
#include<conio.h>

struct node
{
	int iData;
	struct node *next;
}*Head;

short InsertNode(struct node **in_pHead);
short ReverseList(struct node **in_pHead);
short PrintList(struct node **in_pHead);

int main()
{
	int iChoice = 0;

	do
	{
		printf("\r\n1.Insert node");
		printf("\r\n2.Reverse list");
		printf("\r\n3.Print list");
		printf("\r\n4.Exit");
		printf("\r\nEnter your choice:");

		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1:InsertNode(&Head);
					break;

			case 2:ReverseList(&Head);
					break;

			case 3:PrintList(&Head);
					break;
		}

	}while(iChoice != 4);


	getch();
	return 0;
}

short InsertNode(struct node **in_pHead)
{
	int iData = 0;
	struct node *tmp = NULL, *curr = NULL;

	curr = (struct node*)malloc(sizeof(struct node));
	
	printf("\r\nEnter data:");
	scanf("%d",&iData);

	curr->iData = iData;
	curr->next = NULL;

	tmp = *in_pHead;

	if(tmp == NULL)
	{
		printf("\r\nFirst node");
		*in_pHead = curr;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = curr;
	}

	PrintList(in_pHead);

	return 0;
}

short ReverseList(struct node **in_pHead)
{
	struct node *prev = NULL, *curr = NULL, *next = NULL;

	curr = *in_pHead;

	/*Steps to be carried out
	1.Store the next position
	2.switch the curr node next position to prev node
	3.change the prev node to curr node
	4.switch the curr node to next node
	5.repeat the steps 1-4 until the curr position points out to NULL
	6.make prev as header to reverse the linked list*/
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*in_pHead = prev;

	PrintList(in_pHead);

	return 0;
}

short PrintList(struct node **in_pHead)
{
	struct node *tmp = NULL;

	if(*in_pHead == NULL)
	{
		printf("\r\nList is empty");
		return 0;
	}

	tmp = *in_pHead;

	while(tmp != NULL)
	{
		printf("%d->",tmp->iData);
		tmp = tmp->next;
	}

	return 0;
}







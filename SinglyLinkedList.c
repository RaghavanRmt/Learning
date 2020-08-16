#include<stdio.h>
#include<conio.h>

struct node
{
	int iData;
	struct node *next;

}*HEAD;

short InsertNode(struct node **pHead);
short PrintList(struct node **pHead);
short DeleteNode(struct node **pHead);

int main()
{
	int iChoice = 0;

	do
	{	
		
		printf("\r\n1.Insert");
		printf("\r\n2.Delete");
		printf("\r\n3.Print");
		printf("\r\n4.Exit");

		printf("\r\nEnter your choice:");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1:InsertNode(&HEAD);
					break;

			case 2:DeleteNode(&HEAD);
					break;

			case 3:PrintList(&HEAD);
					break;
		}

	}while(iChoice != 4);

	getch();
	return 0;
}

short InsertNode(struct node **pHead)
{
	int iData = 0;
	struct node *tmp = NULL, *curr = NULL;

	printf("\r\nEnter data:");
	scanf("%d",&iData);

	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->iData = iData;
	tmp->next = NULL;

	if(*pHead == NULL)
	{
		printf("\r\nFirst node");
		*pHead = tmp;
	}
	else
	{
		curr = *pHead;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		
		curr->next = tmp;
	}

	PrintList(pHead);

	return 0;
}

short DeleteNode(struct node **pHead)
{
	int iDelData = 0;
	int iDelFlag = 1;
	struct node *tmp = NULL, *prev = NULL;

	if(*pHead == NULL)
	{
		printf("\r\nNo nodes are available to delete");
		return 0;
	}

	tmp = *pHead;

	printf("\r\nEnter data to delete:");
	scanf("%d",&iDelData);

	if(tmp->iData == iDelData)
	{
		*pHead = tmp->next;
		free(tmp);
		iDelFlag = 1;
	}
	else
	{
		do
		{
			if(tmp->iData == iDelData)
			{
				prev->next = tmp->next;
				free(tmp);
				iDelFlag = 1;
				break;
			}

			prev = tmp;
			tmp = tmp->next;

		}while(tmp != NULL);
	}

	if(iDelFlag == 1)
	{
		printf("\r\nNode deleted successfully");
	}
	else
	{
		printf("\r\nData not available in the list");
	}

	return 0;
}


short PrintList(struct node **pHead)
{
	struct node *tmp = NULL;

	if(*pHead == NULL)
	{
		printf("\r\nList is empty");
		return 0;
	}

	tmp = *pHead;

	do
	{
		printf("%d->",tmp->iData);
		tmp = tmp->next;

	}while(tmp != NULL);


	return 0;
}


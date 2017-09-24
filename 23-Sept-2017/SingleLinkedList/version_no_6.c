#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node 
    {
       int data ;
       struct node *next ;
    } NODE ;
    
    /* Declare head of the list as a Global Variable */
    NODE  *head=NULL;
    NODE  *scanPtr ;
    
    int CreateList()
    {
    	NODE *temp;
    	int value;
    	temp=(NODE*)malloc(sizeof(NODE));
    	
    	if(head==NULL)
			head=temp;
    	else
    	{
    		scanPtr=head;  //scanPtr has the address of the previous node
    		while(scanPtr->next!=NULL)
    		{
    			scanPtr=scanPtr->next;
			}
			scanPtr->next=temp;
		}
    		
		printf("Enter the data to be stored:");
    	scanf("%d",&value);
    	temp->data=value;
    	
    	temp->next=NULL;		
	}
	void DisplayList()
    {
    	NODE *ptr=head;
    	printf("List is ");
    	if(head==NULL)
    		printf("empty");
    	else	
    		{
    			while(ptr->next!=NULL)
    			{
    				printf("%d ",ptr->data);
    				ptr=ptr->next;
				}
				printf("%d ",ptr->data);
			}
    	return;
	}
    void AddNode(int pos)
    {
    	int i,value;
    	NODE *prevNode=head;
    	
    	NODE *currNode,*nextNode;
		currNode=(NODE*)malloc(sizeof(NODE));
		
    	if(pos==1)
    	{
    		printf("Enter the value to be stored:");
			scanf("%d",&value);
			currNode->data=value;
			
    		currNode->next=head;
    		head=currNode;
    		return;
		}
		
    	for(i=1;i<pos-1;i++)
    	{
    		prevNode=prevNode->next;
		}
		if(prevNode==NULL)
		{
			printf("Invalid position\n");
		}
		else
		{
			printf("Enter the value to be stored:");
			scanf("%d",&value);
			currNode->data=value;
			
			nextNode=prevNode->next;
			prevNode->next=currNode;
			currNode->next=nextNode;
		}
		return;
	}
    void DeleteNode()
    {
    	int i,position;
    	NODE *ptr=head;
    	NODE *temp;
    	if(head==NULL)
    	{
    		DisplayList();
    		return;
		}
		printf("Enter the position to be deleted:");
    	scanf("%d",&position);
    	if(position==1)
    	{
    		head=ptr->next;
    		ptr->next=NULL;
    		free(ptr);
    		return;
		}
    	for(i=1;i<position-1;i++)
    	{
    		ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("Invalid position\n");	
		}
		else
		{
			temp=ptr->next;
			ptr->next=temp->next;
			temp->next=NULL;
			free(temp);
			return;
		}
	}
    void DeleteList()
    {
    	
	}
    void SearchList()
    {
    	NODE *ptr=head;
    	int i,value,found;
    	if(head==NULL)
    	{
			DisplayList();
    		return;
    	}
    	else
    	{
			printf("Enter the value to be searched:");
			scanf("%d",&value);	
			for(i=1;ptr->next!=NULL;i++)
			{
				if(ptr->data==value)
				{
					printf("%d is found in the list at position %d\n",value,i);
					found=1;
					ptr=ptr->next;
					continue;
				}
				else
					ptr=ptr->next;
			}
			if(ptr->next==NULL)
			{
				if(ptr->data==value)
					printf("%d is found in the list at position %d\n",value,i);
				else if(found!=1)
					printf("%d is not found in the list\n",value);
			}
		}	
	}
	int DisplayMenu()
    {
    	int ch;
    	printf("----------------------------\n");
    	printf("1.Create List\n");
		printf("2.Add Node\n");
		printf("3.Delete Node\n");
		printf("4.Display List\n");
		printf("5.Delete List\n");
		printf("6.Search List\n");
		printf("7.Exit\n");
		printf("\nOption:");
		scanf("%d",&ch);
		return ch;
	}
    
    int main()
    {
        int flag ;
        int choice ;
        flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  case 1 :
                { 
                	 printf("\n----------------------------\n");
    				 printf("***Create List***\n");
                     CreateList() ;
                     printf("\n----------------------------\n");
                     break ;
                }
                case 2:
                {
                	 printf("\n----------------------------\n");
    				 printf("***Add Node***\n");
    				 int position;
    				 printf("Enter the position:");
    				 scanf("%d",&position);
                     AddNode(position);
                     printf("\n----------------------------\n\n");
                     break ;
                }
                case 3:
                {
                	printf("\n----------------------------\n");
    				printf("***Delete Node***\n");
                    DeleteNode();
                    printf("\n----------------------------\n\n");
                     break ;
                }
                case 4:
                {
                	printf("\n----------------------------\n");
    				printf("***Display List***\n");
                    DisplayList() ;
                    printf("\n----------------------------\n\n");
                    break ;
                }
                case 5:
                {
                     DeleteList() ; /* travese through the list and remove each element by element */
                     break ;
                }
                case 6:
                {
                	printf("\n----------------------------\n");
    				printf("***Search List***\n");
                    SearchList();
                    printf("\n----------------------------\n\n");
                    break ;
                }
                case 7:
                {
                    flag = 0 ;
                    break ;
                }
                default:
                {
                   printf("----------------------------\n");
                   printf("Select a proper option\n");	
                   break ;
                }
             }
        }
    }

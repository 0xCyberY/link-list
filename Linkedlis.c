#include<stdio.h>
#include<malloc.h>
struct node
{
   int data;
   struct node *link;
};
typedef struct node *NODE;
NODE insertFront(int element, NODE first)
{
   NODE temp;
   temp = (NODE*)malloc(sizeof(NODE));
   if(temp!=NULL)
   {
	temp->data = element;
	temp->link = first;
	return temp;
   }
   else
   {
	printf("\n Insufficient Memory");
	exit(0);
   }
}
NODE insertRear(int element, NODE first)
{
   NODE temp = NULL, current = NULL;
   if((temp = (NODE*)malloc(sizeof(NODE))) != NULL)
   {
	temp->data = element;
	temp->link = NULL;
   if(first == NULL)
	return temp;
	current = first;
	while(current->link != NULL)
	current = current->link;
	current->link = temp;
	return first;
   }
   else
   {
	printf("\n Insufficient Memory ");
	exit(0);
   }
}
NODE deleteFront(NODE first)
{
   if(first == NULL)
   {
	printf("\n Nothing to delete");
	return first;
   }
   else
   {
	NODE temp = NULL;
	temp = first;
	temp = temp->link;
	printf("\n NODE deleted is %d ",first->data);
	free(first);
	return temp;
   }
}
NODE deleteRear(NODE first)
{
   if(first == NULL)
   {
	printf("\n List is empty, Nothing to delete");
	return first;
   }
   else if(first->link == NULL)
   {
	printf("\n NODE deleted is %d ",first->data);
	free(first);
	return NULL;
   }
   else
   {
	NODE current = first, previous = NULL;
   while(current->link != NULL)
   {
	previous = current;
	current = current->link;
   }
	previous->link = NULL;
	printf("\n NODE deleted is %d ",current->data);
	free(current);
	return first;
   }
}
void displayLinkedList(NODE first)
{
   NODE current = NULL;
   if(first == NULL)
   {
	printf("\n Nothing to display, Linked list is empty !! \n");
   }
   else
   {
	current = first;
   while(current != NULL)
   {
	printf("%d->",current->data);
	current = current->link;
   }
   }
}
void searchLinkedList(int key, NODE first)
{
   NODE current = NULL;
   current = first;
   int found = 0;
   if(first == NULL)
	printf("\n Linked list is empty \n");
   else
   {
   while(current != NULL)
   {
   if(current->data == key)
   {
	found=1;
	break;
   }
   current = current->link;
}
if(found == 1)
printf("\n Element %d found in the linked list\n",key);
else
printf("\n Element %d could not be found in the linkedlist \n",key);
}
}
int main()
{
   NODE first = NULL;
   int element,choice;
   while(1>0)
   {
	printf("\n LINKED LIST IMPLEMENTATION \n");
	printf("\n 1) Insert at front end \n");
	printf("\n 2) Insert at rear end \n");
	printf("\n 3) Display \n");
	printf("\n 4) Search \n");
	printf("\n 5) Delete at front end \n");
	printf("\n 6) Delete at rear end \n");
	printf("\n 7) Exit \n");
	printf("\n Enter your choice : \n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	   printf("\n Enter the element to be inserted atthe front end of linked list : \n");
	   scanf("%d",&element);
		first = insertFront(element,first);
	break;
	case 2:
	   printf("\n Enter the element to be inserted at the rear end of the linked list : \n");
	   scanf("%d",&element);
		first = insertRear(element,first);
	break;
	case 3:
	   displayLinkedList(first);
	break;
	case 4:
	   printf("\n Enter the element to be searched in the linked list : \n");
	   scanf("%d",&element);
	   searchLinkedList(element,first);
	break;
	case 5:
	   first = deleteFront(first);
	break;
	case 6:
	    first = deleteRear(first);
	break;
	case 7:
	   exit(0);
	break;
	}
   }
}

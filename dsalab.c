#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book
{
	int Book_ID;
	char Title[50];
	char Author[50];
	float Price;
	char Status[10];
};
struct Book*b=NULL;
int n=0;
void create()
{
	int i;
	printf("Enter number of books:");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("\n Invalid number of books!\n");
		n=0;
		return;
	}
	free(b);
	b=(struct Book*)malloc(n*sizeof(struct Book));
	if(b==NULL)
	{
		printf("\nMemory allocation failed!\n");
		n=0;
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("\n Enter details of Book %d\n",i+1);
		printf("Book Id:");
		scanf("%d",&b[i].Book_ID);
		printf("Title:");
		scanf("%49[^\n]",b[i].Title);
		printf("Author:");
		scanf("%49[^\n]",b[i].Author);
		printf("Price:");
		scanf("%f",&b[i].Price);
		strcpy(b[i].Status,"Available");
	}
	printf("\n Book records created sucessfully!\n");
}
void display()
{
	int i;
	if(b==NULL || n==0)
	{
		printf("\n No Book records available!\n");
		return;
	}
	printf("\n-------All Book Records-------\n");
	for(i=0;i<n;i++)
	{
		printf("\nBook ID:%d",b[i].Book_ID);
		printf("\nTitle:%s",b[i].Title);
		printf("\nAuthor:%s",b[i].Author);
		printf("\nPrice:%.2f",b[i].Price);
		printf("\nStatus:%s\n",b[i].Status);
	}
}
void search()
{
	int id,i,found=0;
	if(b==NULL || n==0)
	{
		printf("\n No Book records availabale!\n");
		return;
	}
	printf("\nEnter Book ID to search:");
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(b[i].Book_ID==id)
		{
			printf("\n Book Found:\n");
			printf("Book ID:%d\n",b[i].Book_ID);
			printf("Title:%s\n",b[i].Title);
			printf("Author:%s\n",b[i].Author);
			printf("Price:%.2f\n",b[i].Price);
			printf("Status:%s\n",b[i].Status);
			found=1;
			break;
		}
	}
	if(found==0)
	{
		printf("\nBook not found!\n");
	}
}
void issueBook()
{
	int id,i;
	if(b==NULL || n==0)
	{
		printf("\n No Book recordes available!\n");
		return;
	}
	printf("\nEnter Book ID to issue:");
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(b[i].Book_ID==id)
		{
			if(strcmp(b[i].Status,"Available")==0)
			{
				strcpy(b[i].Status,"Issued");
				printf("\n Book issued sucessfully!\n");
			}
			else
			{
				printf("\nBook is already issued!\n");
			}
			return;
		}
	}
	printf("\nBook not found!\n");
	}
	void returnBook()
	{
		int id,i;
		if(b==NULL || n==0)
		{
			printf("\n No book records available!\n");
			return;
		}
		printf("\nEnter Book ID to return:");
		scanf("%d",&id);
		for(i=0;i<n;i++)
		{
			if(b[i].Book_ID==id)
			{
				if(strcmp(b[i].Status,"Issued")==0)
				{
					strcpy(b[i].Status,"Available");
					printf("\nBook returned sucessfully!\n");
				}
				else
				{
					printf("\n Book is already available!\n");
				}
				return;
			}
		}
		printf("\n Book not found!\n");
	}
	int main()
	{
		int choice;
		do
		{
			printf("\n\n =====LIBRARY MANAGEMENT=====\n");
			printf("1.Add Book records\n");
			printf("2.Display all Book records\n");
			printf("3.Search Book by BookId\n");
			printf("4.Issue a Book\n");
			printf("Return a Book\n");
			printf("Exit\n");
			printf("Enter your choice:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					create();
					break;
					case 2:
						display();
						break;
						case 3:
							search();
							break;
							case 4:
								issueBook();
								break;
								case 5:
									returnBook();
									break;
									case 6:
										printf("\n Program Ended.\n");
										free(b);
										b=NULL;
										break;
										default:
										printf("\nInvalid choice!\n");
			}
		}
		while(choice!=6);
		return 0;
	}


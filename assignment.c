#include "assignment.h"

int listcount=0;
int a,i,j;
int *arr;
int *listhead;
//int listcount;
int freehead;
void intilize()
{
	arr = (int*)malloc(300*sizeof(int));
	for(i=0;i<300;i++)
		arr[i] = 0;
	listhead = (int*)malloc(100*sizeof(int));
	for(i=0;i<300;i++)
		listhead[i] = -10;
}
//peforming defragmentation;
void defrag(){
a=freehead;
int k,z,q,w;
int freenodes=0;
if(freehead==-1000)
exit;
else{
	while(arr[a+1]!=-1)
		{	
			arr[a+2]=-300;
			a=arr[a+1];	
			freenodes=freenodes+1;
		}
			freenodes=freenodes+1;
			arr[a+2]=-300;
			j=3*(100-freenodes);
			i=j;
		a=freehead;
		//printf("%d %d %d",freenodes,a,j);
			
		for(k=0;k<freenodes;k++)
		{
			if(a<j)
			{
				if(arr[i+2]==-300)
					{	while(arr[i+2]==-300)
						i=i+3;
					}
				if(arr[i+2]==-1){
					for(q=0;q<listcount;q++)
					{
						if(listhead[q]==i)
						break;
					}
					if(arr[i+1]==-1)
					{
					w=a;
					z=arr[a+1];
					arr[a]=arr[i];
					arr[a+1]=arr[i+1];
					arr[a+2]=arr[i+2];
					a=z;
					}
					else
					{
					w=a;
					z=arr[a+1];	
					arr[a]=arr[i];
					arr[a+1]=arr[i+1];
					arr[a+2]=arr[i+2];
					arr[arr[i+1]+2]=a;	
					a=z;
					}
					listhead[q]=w;
					arr[i]=-300;
					arr[i+1]=-300;
					arr[i+2]=-300;
					}
				
				else if(arr[i+1]==-1){
				z=arr[a+1];	
				arr[a]=arr[i];
				arr[a+1]=arr[i+1];
				arr[a+2]=arr[i+2];
				arr[arr[i+2]+1]=a;
				a=z;
				}
				
				
				
				else{
				z=arr[a+1];	
				arr[a]=arr[i];
				arr[a+1]=arr[i+1];
				arr[a+2]=arr[i+2];
				arr[arr[i+1]+2]=a;
				arr[arr[i+2]+1]=a;
				a=z;
				}
			}
			else
			a=arr[a+1];
		}
		freehead=j;
		for(i=0;i<freenodes-1;i++)
			{
			arr[j]=0;
			arr[j+1]=j+3;
			arr[j+2]=0;
			j=j+3;
			}
			arr[j]=0;
			arr[j+1]=-1;
			arr[j+2]=j-3;
			}

}






//counting no.of elements in givenlist;
void countelements(int list_num){
i=listhead[list_num-1];
int elementcount=0;
if (i==-5)
printf("\nTotal Number of nodes in given list: 0");
else
	{
	while(arr[i+1]!=-1)
		{
		i=arr[i+1];
		elementcount=elementcount+1;
		}
	printf("\nTotal Number of nodes in given list: %d\n", elementcount+1);
	}
}

//counting all elements in all lists
void countallnodes(){
i=freehead;
j=0;
while(arr[i+1]!=-1)
{
	j=j+1;
	i=arr[i+1];
}
j=j+1;
j=100-j;
printf("\nTotal nodes in all lists are: %d",j);
}


//deleting element;
void deleteelement(int listno, int element){

if(listhead[listno-1]==-5)
	printf("\nList is Empty\n");
else{	
	i=listhead[listno-1];
	j=i;
	if((arr[i+1]==-1) && (element==arr[i]))
		{
		arr[i]=0;
		arr[i+2]=0;
		arr[i+1]=freehead;
		freehead=i;
		listhead[listno-1]=-5;
		}
	else if((arr[i+2]==-1)&&(element==arr[i]))
	{
		arr[arr[i+1]+2]=-1;
		arr[i]=0;
		arr[i+2]=0;
		listhead[listno-1]=arr[i+1];
		arr[i+1]=freehead;
		freehead=i;
	}
	else{
	   while(arr[i+1]!=-1)
		{
	
			if(arr[i]==element)
			{
			arr[arr[i+2]+1]=arr[i+1];
			arr[arr[i+1]+2]=arr[i+2];
			arr[i]=0;
			arr[i+2]=0;
			arr[i+1]=freehead;
			freehead=i;
			break; 
			}	
			else
			{
			i=arr[i+1];
			}	
		  }
		if(arr[i+1]==-1)
		{
			if(arr[i]==element)
			{
			arr[arr[i+2]+1]=-1;
			arr[i]=0;
			arr[i+2]=0;
			arr[i+1]=freehead;
			freehead=i;
			}
			else
			printf("\nFAILURE: ELEMENT NOT FOUND\n");
		}

	   }
	}
}




//displaying free nodes;
void printfreelist(int head){
i=head;
printf("[ %d ",i);
while(arr[i+1]!=-1)
  {
	i=arr[i+1];
	printf("%d ",i);
  }
printf("]");
}

//inserting element
void insertelement(int listnum, int value){
if(freehead==-1000)
	printf("\nFAILURE: MEMORY NOT AVAILABLE\n");
else {
	i=freehead;
	if(arr[freehead+1]==-1)
			freehead=-1000;
	else{
		freehead=arr[freehead+1];
	   }
	arr[i]=value;
	

if(value<arr[listhead[listnum-1]])
	{
	arr[i+2]=-1;
	arr[i+1]=listhead[listnum-1];
	arr[listhead[listnum-1]+2]=i;
	listhead[listnum-1]=i;
	
	}
else
     {  
	j=listhead[listnum-1];
	while(arr[j+1]!=-1)
	{	printf("\n%d  %d",arr[j],value);
		if(arr[j]>value)
		{
			printf("Hello");
			a=arr[j+2];
			arr[a+1]=i;
			arr[i+2]=a;
			arr[i+1]=j;
			arr[j+2]=i;
			break;
   /*return 0; */}
		
	else
		{
		j=arr[j+1];
		}
	}	
      }	

	
     if (arr[j+1]==-1){
	if(arr[j]>value){
			a=arr[j+2];
			arr[a+1]=i;
			arr[i+2]=a;
			arr[i+1]=j;
			arr[j+2]=i;
			}
	else{	arr[j+1]=i;
		arr[i+1]=-1;
		arr[i+2]=j;
		}
		}

	
}
}

//displaying all lists
void printalllists()
{
	for(j=0;j<listcount;j++)
	{
		printf("Elements of %d list are:\n",j+1);
		printf("Key  Next  Prev\n");
		i=listhead[j];
		if(i == -5)
		{
			printf("List %d is Empty\n",j+1);
			continue;
		}
		while(i!=-1)
		{
			printf("%d    ",arr[i]);
			if(arr[i+1]==-1)
				printf("NIL  ");    
			else
				printf("%d    ",arr[i+1]);
			if(arr[i+2]==-1)
				printf("NIL\n");
			else
				printf("%d\n",arr[i+2]);
			i=arr[i+1];
		}
	}
}
//creating a newlist
void createlist(int value){
if(freehead==-1000)
	printf("\nFAILURE: MEMORY NOT AVAILABLE\n");

else       {
	
		listcount=listcount+1;
		listhead[listcount-1]=freehead;
		i=freehead;
		if(arr[freehead+1]==-1)
			freehead=-1000;
		else{
		freehead=arr[freehead+1];
              	    }
		arr[i]=value;
		arr[i+1]=-1;
		arr[i+2]=-1;
	  printf("Your new list number is: %d\n",listcount);
	     }
}



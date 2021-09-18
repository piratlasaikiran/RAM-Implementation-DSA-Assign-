#include "assignment.h"


int a;
int *arr;
int freehead;
int i,j;
int main(){


intilize();
for(a=0;a<99;a++)
	{
	arr[a*3+1]=a*3+3;
	}
   arr[a*3+1]=-1;
freehead=0;

int option=100;
while(option!=0){
printf("Select an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\n9. Press 0 to exit\n");
scanf("%d",&option);
if(option ==1)
{
printf("enter a value for newlist\n");
scanf("%d",&j);
createlist(j);
}

else if(option ==2)
{
printf("List you want to insert in: \n");
scanf("%d",&i);
printf("Enter the key value: \n");
scanf("%d",&j);
insertelement(i,j);
}
else if(option ==6)
{
printalllists();
}
else if(option ==5)
{
printf("Enter List number\n");
scanf("%d",&a);
countelements(a);
}
else if(option ==4)
{
countallnodes();
}
else if(option ==3)
{
printf("List you want to delete from: \n");
scanf("%d",&i);
printf("Enter the key value: \n");
scanf("%d",&j);
deleteelement(i,j);
}
else if(option == 7)
{
printfreelist(freehead);
}

else if(option == 8)
{
defrag();
}

else
exit(0);
}


}

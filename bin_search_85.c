#include<stdio.h>

int binarysearch(int arr[],int size,int search)
{
	int first,last,middle;
	first = 0;
   	last = size - 1;
   	middle = (first+last)/2;
 
   	while (first <= last) {
      		if (arr[middle] < search)
         		first = middle + 1;    
      		else if (arr[middle] == search) {
			return middle+1;
         		break;
      		}
      		else
        		last = middle - 1;
 
      		middle = (first + last)/2;
	}
	if (first > last)
		return -1;	
}

int rec_search(int arr[],int first,int last,int search)
{	
	int middle;
	if(first <= last){	
		middle = (first + last)/2;
		if(arr[middle] == search) return middle+1;
		else if(arr[middle] > search )
			rec_search(arr,first,middle-1,search);
		else if(arr[middle] < search && search <= arr[last])
			rec_search(arr,middle+1,last ,search);
		else return -2;
	}
}

int compare(const void * a,const void * b)
{
	int *A,*B;
	A = (int *)a;
	B = (int *)b;
	return (*A-*B);
}
int sort(int arr[],int size)
{
	qsort(arr, size, sizeof(int), compare);
	return 0;
}

int main()
{

	int array[30],size,i,search,result=-1;
	int first,last,middle;
	printf("\nEnter the size of array");
	scanf("%d",&size);
	printf("\nEnter %d lements :",size);
	for(i = 0 ; i<size ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("\nEnter value to search");
	scanf("%d",&search);
	
	sort(array,size);
	printf("\nSorted Array:");	

	for(i = 0 ; i<size ; i++)
	{
		printf("%d ",array[i]);
	}
	//result = binarysearch(array,size,search);
	first = 0;
	last = size-1;
	result = rec_search(array,first,last,search);	
	if(result>0)
		printf("\n%d found at location %d.\n", search, result);
	else
		printf("\nNot found! %d is not present in the list.\n", search);			
	
return 0;
}

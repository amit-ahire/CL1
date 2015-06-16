#include<stdio.h>
#include<stdlib.h>

int binary_search(int numbers[], int low, int high, int key)
{
    int mid = (low+high)/2;
    int return_value;

    if(key == numbers[mid])
        return mid;
    else if(key < numbers[mid] && key >= numbers[low])
        binary_search(numbers, low, mid-1, key);
    else if(key > numbers[mid] && key <= numbers[high])
        binary_search(numbers, mid+1, high, key);
    else
        return -1;
}


int compare(const void * A, const void * B)
{
    int *a, *b;
    a = (int *) A;
    b = (int *) B;    
    if(*a == *b)
        return 0;
    else if(*a < *b)
        return -1;
    return 1;
}


int main()
{
    int nums[30], low, high, key, size, i, index;
    
    printf("Enter the number of elements ");    
    scanf("%d", &size);

    printf("Enter the numbers in the array ");
    for(i = 0; i < size; i++)
        scanf("%d", &nums[i]);

    printf("Enter the element to search ");
        scanf("%d", &key);

    qsort(nums, size, sizeof(int), compare);

    printf("The sorted array is : ");
    for(i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");

    low = 0;
    high = size-1;
    index = binary_search(nums, low, high, key);

    if(index > 0)
        printf("Number %d found at location %d\n", key, index);
    else
        printf("Number not found or out of bounds!\n");

    return 0;
}

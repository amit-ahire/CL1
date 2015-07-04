#include<iostream>
using namespace std;

class bsearch
{
		int array[20];
		
	public:
		int accept();
		void display(int );		
		int sort(int );
		int rec_search(int ,int ,int );
		void search();
				
};


int bsearch :: accept()
{
	int size;
	cout<<"Enter the size of the array:";
	cin>>size;
	cout<<endl<<"Enter "<<size<<" elements:"<<endl;
	for(int i=0;i<size;i++)
		cin>>array[i];
	
	return size;
}

void bsearch :: display(int size)
{
	for(int i=0;i<size;i++)
		cout<<" "<<array[i];
}

int bsearch :: sort(int size)
{
	int temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
			
	return 0;
}

int bsearch :: rec_search(int first,int last,int search)
{	
	int middle;
	if(first <= last){	
		middle = (first + last)/2;
		if(array[middle] == search) return middle+1;
		else if(array[middle] > search )
			rec_search(first,middle-1,search);
		else if(array[middle] < search && search <= array[last])
			rec_search(middle+1,last ,search);
		else return -1;
	}
}


int main()
{
	int result = -1, first = 0, last, key, size;
	bsearch b1;
	size = b1.accept();
	b1.sort(size);		
	cout<<endl<<"Sorted array:";
	b1.display(size);
	cout<<endl<<endl<<"Enter the element you to search: ";
	cin>>key;
	last = size-1;
	result = b1.rec_search(first,last,key);	
	if(result > 0)
		cout<<endl<<key<<" Found at location "<<result<<endl;
	else
		cout<<endl<<"Not found! "<<key<<" is not present in the list."<<endl;
	
	return 0;

}

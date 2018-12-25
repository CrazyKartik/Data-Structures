#include<iostream>
using namespace std;

void quicksort(int S[],int f,int l)
{
	int f1=f,l1=l,p,temp,p1=l;
	if(f1<l1)
	{
		p=S[l1];
		while(f1<l1)
		{
			while(S[f1]<p)
			f1++;
			while(S[l1]>=p)
			l1--;
			if(f1<l1)
			{
				temp=S[f1];
				S[f1]=S[l1];
				S[l1]=temp;
			}
		}
		S[p1]=S[f1];
		S[f1]=p;
		quicksort(S,f,f1-1);
	    quicksort(S,f1+1,l);
	}
	else return;
}

int main()
{
	int n;
	cout<<"Enter length of array : ";
	cin>>n;
	int S[n];
	cout<<"Enter array elements : ";
	for(int i=0; i<n; i++)
		cin>>S[i];
	quicksort(S,0,n-1);
	for(int i=0; i<n; i++)
		cout<<S[i]<<" ";
}

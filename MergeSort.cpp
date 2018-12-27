#include<iostream>
using namespace std;

void mergesort(int S[],int f1,int l1,int f2,int l2,int B[])
{
	int i,j=f2,k=0;
	for(i=f1; i<=l1 && j<=l2;)
	{
		if(S[i]<=S[j])
		B[k++]=S[i++];
		else
		B[k++]=S[j++];
	}
	
	if(i<=l1)
		while(i<=l1)
			B[k++]=S[i++];
			
	else if(j<=l2)
		while(j<=l2)
			B[k++]=S[j++];
			
	for(i=0; i<k; i++)
    S[f1++]=B[i];
}

void split(int S[],int f,int l,int B[])
{
	if(f>=l) return;
	split(S,f,(f+l)/2,B);
	split(S,(f+l)/2+1,l,B);
	mergesort(S,f,(f+l)/2,(f+l)/2+1,l,B);
}

int main()
{
	int n;
	cout<<"Enter length of array : ";
	cin>>n;
	int S[n],B[n];
	cout<<"Enter array elements : ";
	for(int i=0; i<n; i++)
	cin>>S[i];
	
	split(S,0,n-1,B);
	
	for(int i=0; i<n; i++)
	cout<<S[i]<<" ";
}

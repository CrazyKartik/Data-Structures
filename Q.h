#include<iostream>
#include<cstdlib>
using namespace std;

template<typename t>
class queue
{
	public:
		static int frnt,sz,last;
		t *A;
		queue()
		{
			A=(t*)malloc(sz*sizeof(t));
		}
		
		t front()
		{
			return *(A+frnt);	
		}
		
		void pop()
		{
			if(sz>0)
			{
			frnt++;
			sz--;
			}
		}
		
		void push(int v)
		{
			A=(t*)realloc(A,(sz+1)*sizeof(t));
			sz++;
			*(A+last)=v;
			last++;	
		}
		
		int size()
		{
			return sz;
		}	
};

template<typename t>
int queue<t>::frnt=0;
template<typename t>
int queue<t>::last=0;
template<typename t>
int queue<t>::sz=0;

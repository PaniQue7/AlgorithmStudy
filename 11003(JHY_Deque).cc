#include <cstdio>
#include <utility>
#include <deque>

using namespace std;
deque<pair<int,int>> dq;

int main(void)
{
	int N,L;
	scanf("%d %d",&N,&L);

	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		
		while(!dq.empty() && dq.back().first > a)	
		{
			dq.pop_back();
		}
		
		dq.push_back(make_pair(a,i+(L-1)));
		
		while(dq.front().second < i)
		{
			dq.pop_front();
		}

		printf("%d ",dq.front().first);
	}

	return 0;
}

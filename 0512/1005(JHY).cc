#include <iostream>
#include <utility>
#include <set>
using namespace std;

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int c=0; c<t; c++)
	{
		int n, k;
		scanf("%d %d",&n,&k);

		int b[1001];

		for(int i=0; i<n; i++)
		{
			scanf("%d",&b[i+1]);
		}

		int x,y;
		set<pair<int,int>> s;
		for(int i=0; i<k; i++)
		{
			scanf("%d %d",&x,&y);
			s.insert(make_pair(x,y));
		}
		
		int w;
		scanf("%d",&w);

		int tmp[1001]={0};

		while(!s.empty())
		{
			set<pair<int,int>>::iterator it=s.begin();
			
			int cost_f = b[(*it).first];
			int cost_s = b[(*it).second];
			
			if(tmp[(*it).first]!=0)
				cost_f = tmp[(*it).first];
			if(tmp[(*it).second]!=0)
				cost_s = tmp[(*it).second];

			int cost = cost_f + cost_s;
			//if(tmp[(*it).second] != -1 && tmp[(*it).second] > cost)
			//	tmp[(*it).second] = cost;
			if(tmp[(*it).second] == 0)
			{
				tmp[(*it).second] = cost;
			}
			else
				if(tmp[(*it).second] > cost)
					tmp[(*it).second] = cost;

			s.erase(s.begin());
		}
		
		printf("%d\n",tmp[w]);
		s.clear();
	}
	return 0;
}

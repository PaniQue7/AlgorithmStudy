#include <cstdio>
#include <utility>
#include <vector>

using namespace std;
vector<pair<int,int>> v;

int main(void)
{
	int N,L;
	scanf("%d %d",&N,&L);

	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
        
		while(!v.empty() && v.back().first > a)	
		{
			v.pop_back();
		}
		
		v.push_back(make_pair(a,i+(L-1)));
		
		while(v[0].second < i)
        {
            v.erase(v.begin());
        }

		printf("%d ",v[0].first);
	}

	return 0;
}

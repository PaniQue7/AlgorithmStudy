#include <iostream>
#include <set>
#include <utility>
#include <queue>
using namespace std;

int main(void)
{
	set<int> s;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
	int v, e , w=0;
	cin >> v >> e;
	
	for(int i=0; i<e; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		p.push(make_pair(c,make_pair(a,b)));
	
	}

	while(1)
	{
		pair<int,pair<int,int>> tmp;
		tmp = p.top();
		p.pop();

		w += tmp.first;
	
		s.insert(tmp.second.first);
		
		s.insert(tmp.second.second);

		if(s.size()==v)
			break;
	}

	cout << w;
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

//baekjoon 7576 tomato
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> tomato; //tomato box
	queue<pair<int,int>> Q;
	int M,N;
	cin >> M >> N; // Number of slots , Number of columns
	for(int i=0; i<N; i++)
	{
		vector<int> tmp;
		for(int j=0; j<M; j++)
		{
			int condition;
			cin >> condition;
			if(condition==1)
				Q.push(make_pair(i,j));
			tmp.push_back(condition);
		}
		tomato.push_back(tmp);
	}
	int day=0, s=Q.size(),count=0;
	while(!Q.empty())
	{
		pair<int,int> f;
		f = Q.front();
		Q.pop();
		count++;
		int tmp;
		if(f.second-1>=0)
		{
			tmp = tomato[f.first][f.second-1]; //left
			if(tmp!=1 && tmp!=-1)
			{
				tomato[f.first][f.second-1]=1;
				Q.push(make_pair(f.first,f.second-1));
			}
		}
		if(f.first-1>=0)
		{
			tmp = tomato[f.first-1][f.second]; //up
			if(tmp!=1 && tmp!=-1)
			{
				tomato[f.first-1][f.second]=1;
				Q.push(make_pair(f.first-1,f.second));
			}
		}

		if(f.first+1<N)
		{
			tmp = tomato[f.first+1][f.second]; //down
			if(tmp!=1 && tmp!=-1)
			{
				tomato[f.first+1][f.second]=1;
				Q.push(make_pair(f.first+1,f.second));
			}
		}

		if(f.second+1<M)
		{
			tmp = tomato[f.first][f.second+1]; //right
			if(tmp!=1 && tmp!=-1)
			{
				tomato[f.first][f.second+1]=1;
				Q.push(make_pair(f.first,f.second+1));
			}
		}

		if(count==s)
		{
			day++;
			s=Q.size();
			count=0;
		}


	}
	//find 0 in tomatobox
	int flag=0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(tomato[i][j]==0)
			{
				flag++;
			}
		}
	}

	//output
	if(flag!=0)
		cout << -1 << '\n';
	else
		cout << day-1 <<'\n';
	return 0;
}


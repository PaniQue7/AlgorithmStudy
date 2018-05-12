#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visited[201][201]; // visited[A][B] : A컵의 물의양 A, B컵의 물의양 B인 상태를 check하는 visited array
int A,B,C;
vector<int> ans;

typedef struct Multong
{
	int a, b, c;
}Multong;


void bfs()
{
	queue<Multong> q;
	q.push({ 0,0,C });

	while ( !q.empty() )
	{
		Multong here = q.front();
		q.pop();

		if ( visited[here.a][here.b] )
			continue;
		visited[here.a][here.b] = true;

		if ( here.a == 0 )
			ans.push_back(here.c);

		// A->B, 물이 넘치는경우부터
		if ( here.a + here.b > B )
		{
			int _A = here.a + here.b - B;
			q.push({ _A,B,here.c });
		}
		else
		{
			int _B = here.a + here.b;
			q.push({ 0,_B,here.c });
		}

		// A->C, 물이 넘치는경우부터
		if ( here.a + here.c > C )
		{
			int _A = here.a + here.c - C;
			q.push({ _A,here.b,C });
		}
		else
		{
			int _C = here.a + here.c;
			q.push({ 0,here.b,_C });
		}

		// B->A, 물이 넘치는경우부터
		if ( here.b + here.a > A )
		{
			int _B = here.b + here.a - A;
			q.push({ A,_B,here.c });
		}
		else
		{
			int _A = here.b + here.a;
			q.push({ _A,0,here.c });
		}

		// B->C , 물이 넘치는경우부터
		if ( here.b + here.c > C )
		{
			int _B = here.b + here.c - C;
			q.push({ here.a,_B,C });
		}
		else
		{
			int _C = here.b + here.c;
			q.push({ here.a,0,_C });
		}

		// C->A, 물이 넘치는경우부터
		if ( here.c + here.a > A )
		{
			int _C = here.c + here.a - A;
			q.push({ A,here.b,_C });
		}
		else
		{
			int _A = here.c + here.a;
			q.push({ _A,here.b,0 });
		}

		// C->B, 물이 넘치는경우부터
		if ( here.c + here.b > B )
		{
			int _C = here.c + here.b - B;
			q.push({ here.a,B,_C });
		}
		else
		{
			int _B = here.c + here.b;
			q.push({ here.a,_B,0 });
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B >> C;
	bfs();
	sort(ans.begin(), ans.end());
	for ( auto itr = ans.begin(); itr != ans.end(); itr++ )
	{
		cout << *itr << ' ';
	}
}
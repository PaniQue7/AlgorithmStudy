#include <iostream>
#include <set>
using namespace std;
set<int> s;
int visit[205][205][205]={0};
int a, b, c;

void inst(int aa, int bb, int cc)
{
	if(aa==0)
	{
		s.insert(cc);
	}

	if(visit[aa][bb][cc])
		return;
	visit[aa][bb][cc] = 1;
	//c->a
	if(a != aa && cc!=0)
	{
		if(a>=c)
			inst(cc-aa,bb,0);
		else
			inst(a-aa,bb,cc-(a-aa));
	}
	
	//c->b
	if(b != bb && cc!=0)
	{
		if(b>=c)
			inst(aa,cc-bb,0);
		else
			inst(aa,b-bb,cc-(b-bb));	
	}

	//b->a
	if(a != aa && bb!=0)
	{
		if(a>=b)
			inst(bb-aa,0,cc);
		else
			inst(a-aa,bb-(a-aa),cc);
	}

	//b->c
	if(c != cc && bb!=0)
	{
		if(c>=b)
			inst(aa,0,bb-cc);
		else
			inst(aa,bb-(c-cc),c-cc);
	}

	//a->b
	if(b != bb && aa!=0)
	{
		if(b>=a)
			inst(0,aa-bb,cc);
		else
			inst(aa-(b-bb),b-bb,cc);
	}

	//a->c
	if(c != cc && aa!=0)
	{
		if(c>=a)
			inst(0,bb,aa-cc);
		else
			inst(aa-(c-cc),bb,c-cc);
	}
}

int main(void)
{
	cin >> a>> b>> c;
	
	inst(0,0,c);

	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout << *it <<" ";
	}

	return 0;
}

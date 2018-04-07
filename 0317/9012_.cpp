#include <iostream>
#include <string>
using namespace std;
string str;
int n, num;

int main()
{
	scanf("%d", &n);
	while ( n-- )
	{
		num = 0;
		str = "";
		cin >> str;
		for ( int i = 0; i<str.size(); i++ )
		{
			if ( str[i] == '(' ) num++;
			else if ( str[i] == ')' ) num--;
			if ( num < 0 )
			{
				puts("NO");
				break;
			}
		}
		if ( num == 0 ) puts("YES");
		else if ( num > 0 ) puts("NO");
	}
	return 0;


}
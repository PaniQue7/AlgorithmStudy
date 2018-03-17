#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
int n;


int main()
{
	scanf("%d", &n);
	while ( n-- )
	{
		int i;
		stack<char> st;
		cin >> str;
		for ( i = 0; i < str.size(); i++ )
		{
			if ( str[i] == '(' ) st.push(str[i]);
			else if ( str[i] == ')' )
			{
				if ( !st.empty() && st.top() == '(' )
					st.pop();
				else break;
			}
			else break;
		}
		if ( st.empty() && i == str.size()) puts("YES");
		else puts("NO");
	}
	return 0;
}
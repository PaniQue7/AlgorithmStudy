#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

deque<pair<int, int> > dq;

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);

        while(!dq.empty() && dq.back().first >= x)
            dq.pop_back();

        dq.push_back(make_pair(x,i));
        
        if(dq.front().second<=i-l)
            dq.pop_front();
        
        printf("%d ", dq.front().first);
    }
}


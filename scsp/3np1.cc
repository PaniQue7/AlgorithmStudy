#include <iostream>
#include <stack>
#include <utility>

unsigned long long arr[64];

using namespace std;

unsigned long long tpow(int k)
{
    return (unsigned long long)1 << k;
}

int main(void)
{
    unsigned long long a;
    int c, k;
    cin >> c;

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 8;

    stack<pair<unsigned long long, int> > s;
    s.push(make_pair(16, 4));

    while(!s.empty())
    {
        unsigned long long a = s.top().first;
        int index = s.top().second;
        s.pop();
        if(arr[index] == 0 || arr[index] > a)
        {
            arr[index] = a;
        }

        if(index + 1 < 64)
        {
            if((a - 1) % 3 == 0 && (a - 1) % 2 != 0)
                s.push(make_pair((a-1)/3, index + 1));
            s.push(make_pair(a * 2, index + 1));
        }
    }

    for(int i = 0; i < c; i++)
    {
        cin >> k;
        cout << "Case #" << i + 1 << "\n";
        cout << arr[k] << " " << tpow(k) << "\n";
    }
}



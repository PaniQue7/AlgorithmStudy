#include <iostream>

using namespace std;

int main(void)
{
    long long f, m, c;
    cin >> f >> m;

    if(m == 0)
    {
        c = f - 1;
        cout << c << "\n";
        return 0;
    }
    c = f;
    m--;
    int dir = 1, left, right;
    if(f == 1)
    {
        left = 0;
        right = 7;
    }
    else if(f == 2)
    {
        left = 1;
        right = 5;
    }
    else if(f == 3)
    {
        left = 3;
        right = 3;
    }
    else if(f == 4)
    {
        left = 5;
        right = 1;
    }
    else
    {
        left = 7;
        right = 0;
    }

    while(1){
        if(dir == 1)
        {
            c += right;
            dir = 2;
            if(right == 0)
                continue;
        }
        else if(dir == 2)
        {
            c += left;
            dir = 1;
            if(left == 0)
                continue;
        }

        m--;
        if(m < 0)
            break;
        c++;
    }

    cout << c << "\n";
}
        

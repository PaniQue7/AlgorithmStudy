#include <iostream>
#include <set>

using namespace std;

int arr[5000];
int duos[400001];

void addDuo(int index)
{
    for(int i = 0; i <= index; i++)
    {
        duos[arr[index] + arr[i] + 200000] = 1;
    }
}

bool isGood(int index)
{
    for(int i = index - 1; i >= 0; i--)
    {
        if(duos[arr[index] - arr[i] + 200000] == 1)
            return true;
    }
    return false;
}


int main(void)
{
    int c, g = 0;
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        cin >> arr[i];
        if(i == 0)
            duos[arr[0] + arr[0] + 200000] = 1;
        else
        {
            if(isGood(i))
                g++;
            addDuo(i);
        }
    }

    cout << g << "\n";
}

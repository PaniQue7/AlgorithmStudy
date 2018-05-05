#include <iostream>
#include <string>
#include <vector>

using namespace std;

string result;
vector<string> map;
int size;

void dfs(int x, int y, int width, bool check);

void div(int x, int y, int width)
{
    char found = map[y][x];
    bool same = true;
    for(int i = y; i < y + width; i++)
    {
        for(int j = x; j < x + width; j++)
        {
            if(found != map[i][j])
            {
                dfs(x, y, width, false);
                same = false;
                break;
            }
        }
        if(!same)
            break;
    }
    if(same){
        result += found;
    }
}

void dfs(int x, int y, int width, bool check)
{
    if(check)
    {
        char found = map[y][x];
        bool same = true;
        for(int i = y; i < width; i++)
        {
            for(int j = x; j < width; j++)
            {
                if(found != map[i][j])
                {
                    same = false;
                    break;
                }
            }
            if(!same)
                break;
        }

        if(same)
        {
            result += found;
            return;
        }
    }
    int d = width/2;
    result += "(";
    div(x, y, d);
    div(x + d, y, d);
    div(x, y + d, d);
    div(x + d, y + d, d);
    result += ")";
}

int main(void)
{
    cin >> size;

    map.resize(size);

    for(int i = 0; i < size; i++)
    {
        string tmp;
        cin >> tmp;
        map[i] = tmp;
    }

    dfs(0, 0, size, true);
    cout << result << "\n";
    return 0;
}

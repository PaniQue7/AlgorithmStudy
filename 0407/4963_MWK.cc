#include <cstdio>
#include <vector>

using namespace std;

int count;

void findIsland(int i, int j, bool root, vector<vector<bool> >& map,  vector<vector<bool> >& visited){
    if(map[i][j] == false || visited[i][j])
        return;
    visited[i][j] = true;

    int y = map.size(), x = map[0].size();
    int dx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
    int dy[8] = {1, -1, -1, 1, 0, 0, -1, 1};
    for(int k = 0; k < 8; k++){
        if(i + dy[k] < 0 || i + dy[k] >= y)
            continue;
        if(j + dx[k] < 0 || j + dx[k] >= x)
            continue;
        if(visited[i + dy[k]][j + dx[k]] == true)
            continue;
        if(map[i + dy[k]][j + dx[k]] == false)
            continue;
        findIsland(i + dy[k], j + dx[k], false, map, visited);
    }

    if(root)
        count++;
}

int main(void){
    while(1){
        int x, y;
        count = 0;
        scanf("%d %d", &x, &y);

        if(x == 0 && y == 0)
            return 0;

        vector<vector<bool> > map;
        vector<vector<bool> > visited;
        map.resize(y);
        visited.resize(y);
        for(int i = 0; i < y; i++){
            visited[i].resize(x, 0);
            for(int j = 0; j < x; j++){
                int a;
                scanf("%d", &a);
                if(a == 1)
                    map[i].push_back(true);
                else
                    map[i].push_back(false);
            }
        }

        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                findIsland(i, j, true, map, visited);
            }
        }

        printf("%d\n", count);
    }
}

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<bool> > grid;
int count = 0, n;

void place(int x){
    if(x == n)
        return;
    for(int i = 0; i < n; i++){
        bool flag = true;
        int j;
        for(j = 1; j <= n; j++){
            if(x - j < 0){
                break;
            }
            if(grid[i][x-j]){
                flag = false;
                break;
            }
            if(i - j >= 0)
                if(grid[i - j][x - j]){
                    flag = false;
                    break;
                }
            if(i + j < n)
                if(grid[i + j][x - j]){
                    flag = false;
                    break;
                }
        }
        if(flag){
            grid[i][x] = true;
            if(x == n - 1)
                count++;
            else
                place(x + 1);
            grid[i][x] = false;
        }
    }
}

int main(void){
    scanf("%d", &n);

    if(n == 1){
        printf("1\n");
        return 0;
    }
    // Grid Setup
    grid.resize(n);
    for(int i = 0; i < n; i++){
        grid[i].resize(n, false);
    }
    for(int i = 0; i < n; i++){
        grid[i][0] = true;
        place(1);
        grid[i][0] = false;
    }
    printf("%d\n", count);
}

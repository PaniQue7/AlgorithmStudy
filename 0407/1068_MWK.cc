#include <cstdio>
#include <vector>

using namespace std;

int count;
vector<int> vec;
int dfs(int start){
    int res = 0;
    for(int i = 0; i < count; i++){
        if(i != start && vec[i] == start)
        {
            res += dfs(i);
        }
    }
    if (res == 0)
        return 1;
    else return res;
}

int main(void){
    scanf("%d", &count);
    vector<int> starts;
    vec.resize(count, 0);
    for(int i = 0; i < count; i++){
        int a;
        scanf("%d", &a);
        if(a == -1)
            starts.push_back(i);
        vec[i] = a;
    }
    
    int del;
    scanf("%d", &del);
    vec[del] = -2;
    int sum = 0;

    for(int i = 0; i < starts.size(); i++){
        if(vec[starts[i]] == -1)
            sum += dfs(starts[i]);
    }

    printf("%d\n", sum);
}

#include <cstdio>
#include <vector>

using namespace std;
int main(void) {
    int count, b, c;
    scanf("%d", &count);

    vector<long long> students;
    students.resize(count);
    for(int i = 0; i < count; i++){
        int tmp;
        scanf("%d", &tmp);
        students[i] = tmp;
    }

    scanf("%d %d", &b, &c);
    for(int i = 0; i < count; i++){
        students[i] -= b;
    }

    long long sum = count;
    for(int i = 0; i < count; i++){
        if(students[i] <= 0)
            continue;
        if(students[i] % c == 0)
            sum += students[i] / c;
        else
            sum += students[i] / c + 1;
    }

    printf("%lld\n", sum);
}

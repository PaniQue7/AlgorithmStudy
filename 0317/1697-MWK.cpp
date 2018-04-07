#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <queue>

int main(void) {
	int a, b;
	int bfs[100001] = { 0 };
	std::queue<int> Q;
	std::cin >> a >> b;

	if (a >= b) {
		std::cout << a - b << std::endl;
		return 0;
	}

	Q.push(a);

	while (1) {
		int tmp, x;
		x = Q.front();
		Q.pop();

		tmp = x + 1;
		if (tmp < 100001 && bfs[tmp] == 0) {
			bfs[tmp] = bfs[x] + 1;
			Q.push(tmp);
		}

		tmp = x - 1;
		if (tmp >= 0 && bfs[tmp] == 0) {
			bfs[tmp] = bfs[x] + 1;
			Q.push(tmp);
		}

		tmp = x * 2;
		if (tmp < 100001 && bfs[tmp] == 0) {
			bfs[tmp] = bfs[x] + 1;
			Q.push(tmp);
		}

		if (bfs[b] != 0) {
			break;
		}
	}
	std::cout << bfs[b] << std::endl;
}
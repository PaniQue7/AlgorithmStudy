#include<stdio.h>
#include<math.h>

int printPiramid(char layer[][6144],int x, int y, int lines) {
	int i = 0;
	for (i = 0; i < 5; ++i) {
		layer[x][y+i] = '*';
		if (i % 2 != 0) {
			layer[x - 1][y + i] = '*';
		}
		if (i == 2) {
			layer[x - 2][y + i] = '*';
		}
	}
	layer[x][lines * 2 - 1] = '\0';
	layer[x-1][lines * 2 - 1] = '\0';
	layer[x-2][lines * 2 - 1] = '\0';
	if (lines != 3072) {
		layer[lines][0] = '\0';
	}

	return y + i;
}

void printPattern(char layer[][6144],int k, int x, int y, int lines) {
	if (k == 0) {
		y = printPiramid(layer, x, y, lines);
	}
	else {
		printPattern(layer, k-1, x - 3*pow(2,k-1), y + (3*pow(2,k))/2, lines);
		printPattern(layer, k-1, x, y, lines);
		printPattern(layer, k-1, x, y + (3 * pow(2, k)), lines);
	}
	return;
}

int main(void) {
	int lines, k, i, j, printed=0;
	char (*layer)[6144] = (char*)malloc(3072 * 6144);
	for (i = 0; i < 3072; ++i) {
		for (j = 0; j < 6144; ++j) {
			layer[i][j] = ' ';
		}
	}
	scanf("%d", &lines);
	k = log2(lines / 3);
	printPattern(layer, k, lines-1, 0, lines);
	for (i = 0; i < 3072; ++i) {
		if (layer[i][0] == '\0') {
			break;
		}
		printf("%s\n", layer[i]);
	}
	free(*layer);
	return 0;
}
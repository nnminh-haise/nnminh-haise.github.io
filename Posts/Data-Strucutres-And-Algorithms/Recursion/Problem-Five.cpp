#include <bits/stdc++.h>

using namespace std;

#define SIZE 5

const int dx[8] = {-1, -2, -2, -1, +1, +2, +2, +1};
const int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};

bool inside(int x, int y) {
	return (0 <= x && x < SIZE && 0 <= y && y < SIZE);
}

int chess[SIZE][SIZE];

void reset() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			chess[i][j] = -1;
		}
	}
}

void print() {
    cout << "---\n";
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << setw(2) << chess[i][j] << (j < SIZE - 1 ? " " : "\n");
		}
	}
}

void backTracking(int x, int y, int step, int& counter) {
	chess[x][y] = step;
	if (step == SIZE * SIZE - 1) {
		print();
		++counter;
	}
	else {
		for (int k = 0; k < 8; ++k) {
			int new_x = x + dx[k];
			int new_y = y + dy[k];
			if (inside(new_x, new_y) && chess[new_x][new_y] == -1) {
				backTracking(new_x, new_y, step + 1, counter);
                chess[new_x][new_y] = -1;
			}
		}
	}
}

int main() {
    int counter = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			reset();
			backTracking(i, j, 0, counter);
		}
	}
	cout << "---\n";
	cout << "Number of traversal: " << counter << endl;
    return 0;
}
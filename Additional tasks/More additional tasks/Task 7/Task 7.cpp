
#include <iostream>

void sortPoints(int n, Point* P) {
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		Point Min = P[i];
		for (int j = i + 1; j < n; j++) {
			if (P[j].x < Min < x || P[j].x == Min.x) {
				if (P[j].y < Min.y) {
					Min = P[j];
					k = j;
				}
			}
			P[k] = P[i];
			P[i] = Min;
		}
	}
}

int main() {

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

#define MAX_AREA 100
#define MAX_HEIGHT 100

int map[MAX_AREA][MAX_AREA];
int area[MAX_AREA][MAX_AREA];
int area_size = MAX_AREA;

int get_map() {
	int i, j, count = 0;
	for (i=0; i<area_size; i++) {
		for (j=0; j<area_size; j++) {
			count += scanf("%d", &map[i][j]);
		}
	}
	return count;
}

void get_range(int *min, int *max) {
	int i, j;
	for (i=0; i<area_size; i++) {
		for (j=0; j<area_size; j++) {
			*min = MIN(*min, map[i][j]);
			*max = MAX(*max, map[i][j]);
		}
	}
}

void split_area(int x, int y, int height, int id) {
	if (x < 0 || x >= area_size) return;
	else if (y < 0 || y >= area_size) return;
	else if (map[x][y] > height && area[x][y] == 0) {
		area[x][y] = id;
	}
	else return;
	
	split_area(x-1, y, height, id);
	split_area(x, y-1, height, id);
	split_area(x+1, y, height, id);
	split_area(x, y+1, height, id);
}

int get_solution(int min, int max) {
	if (min == max) return 1;
	int i, j, k, result = 0;
	for (i=min; i<max; i++) {
		for (j=0; j<area_size; j++) {
			for (k=0; k<area_size; k++) {
				area[j][k] = 0;
			}
		}
		int count = 1;
		for (j=0; j<area_size; j++) {
			for (k=0; k<area_size; k++) {
				if (map[j][k] > i && area[j][k] == 0) {
					split_area(j, k, i, count);
					count++;
				}
			}
		}
		result = MAX(result, count-1);
	}
	return result;
}

int main(int argc, char *args) {
	scanf("%d", &area_size);

	get_map();
	
	int min = MAX_HEIGHT, max = 1;
	get_range(&min, &max);
	
	int count = get_solution(min, max);
	printf("%d", count);

	exit(EXIT_SUCCESS);
}
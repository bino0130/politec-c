//#include <stdio.h>
//#include <windows.h>
//
//int main() {
//	int cnt, inputNumber;
//	
//	printf("369 369! 369 369!\n");
//	printf("범위를 입력하세요 : ");
//	scanf("%d", &inputNumber);
//	
//	for (int i = 1; i < inputNumber + 1; i++) {
//		cnt = 0;
//		int num = i;
//		
//		while (num > 0) {
//			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
//				cnt++;
//			}
//			num /= 10;
//		}
//		
//		if (cnt == 0) {
//			printf("%d\n", i);
//			Sleep(1000);
//		} else {
//			for (int j = 0; j < cnt; j++) {
//				printf("짝 ");
//				Sleep(1000);	
//			}
//			printf("\n");
//		}
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//
//int main() {
//	srand(time(NULL));
//	
//	int i = 0;
//	while (i != 3) {
//		i = rand() % 10;
//		printf("%d\n",i);
//	}
//}

//#include <stdio.h>
//
//int main() {
//	char input;
//	
//	do {
//	printf("문자를 입력하세요 : ");
//	scanf("%c", &input);
//	getchar();
//	} while (input != 'q');
//	
//	return 0;
//}

#include <stdio.h>

int main() {
	int input, x = 0, y = 0, cnt = 1, d = 1;
	
	printf("입력 : ");
	scanf("%d", &input);
	int arr[input][input];
	
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	while(cnt < input * input) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(nx < 0 || nx >= input || ny < 0 || ny >= input || arr[nx][ny] > 0) {
			d = (d + 1) % 4;
			continue;
		}
		arr[x][y] = cnt;
		cnt++;
		x = nx;
		y = ny;
	}
	
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

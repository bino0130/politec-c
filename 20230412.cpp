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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	srand(time(NULL));
	
	int i = 0;
	while (i != 3) {
		i = rand() % 10;
		printf("%d\n",i);
	}
}

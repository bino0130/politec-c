//#include <stdio.h>
//#include <windows.h>
//
//int main() {
//	int cnt, inputNumber;
//	
//	printf("369 369! 369 369!\n");
//	printf("������ �Է��ϼ��� : ");
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
//				printf("¦ ");
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
//	printf("���ڸ� �Է��ϼ��� : ");
//	scanf("%c", &input);
//	getchar();
//	} while (input != 'q');
//	
//	return 0;
//}

#include <stdio.h>

int max;

int  main()
{
  int dal[50][50];
  int i;
  int x=0;
  int y=-1;
  int t=1;
  int p;
  int cnt=1;
  int jmax;

  printf("�迭 ���ڸ� �Է��ϼ��� nXn: ");
  scanf("%d",&p);
  max=p;
  
  jmax=max;
  while(0<=jmax)
  {
    for(i=0;i<jmax;i++) //�� ǥ��
    {
      y=y+t;
      dal[x][y]=cnt;
      cnt++;
    }
    jmax--;
    for(i=0;i<jmax;i++)// �� ǥ��
    {
      x=x+t;
      dal[x][y]=cnt;
      cnt++;
    }
    
    t=t*-1;
  }
  for(x=0;x<max;x++)// ��� �κ�
  {    
    for(y=0;y<max;y++)
    {
      printf("%-4d",dal[x][y]);
    }
    printf("\n");
  }
  
  return 0;
}

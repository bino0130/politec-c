#include <stdio.h>
#include <time.h> 

// ȯ���ϱ� 
//int main() {
//	int inputMoney, choiceMenu, changedMoney, change, oneThousandBill, oneHundredCoin, tenCoin;
//	double usdChangeRate = 1319.83;
//	double jpyChangeRate = 9.98;
//	double eurChangeRate = 1439.45;
//	double cnyChangeRate = 191.97;
//	double gbpChangeRate = 1638.34;
//	
//	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
//	scanf("%d", &inputMoney);
//	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
//	scanf("%d", &choiceMenu);
//	
//	switch (choiceMenu) {
//		case 1 :
//		changedMoney = (int)(inputMoney / usdChangeRate);
//		change = (inputMoney - (int)(changedMoney * usdChangeRate)) / 10 * 10;
//		if (change > 999) {
//			oneThousandBill = change / 1000;
//			change = change % 1000; 
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		} else if (change < 1000) {
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		}
//		
//		change = oneThousandBill * 1000 + oneHundredCoin * 100 + tenCoin * 10;
//		printf("���� ȯ�� : %.2f\n", usdChangeRate);
//		printf("ȯ�� ���\n");
//		printf("�޷� : %d�޷�\n", changedMoney);
//		printf("�Ž����� : %d��\n", (int)change);
//		printf("õ�� : %d��\n", oneThousandBill);
//		printf("��� : %d��\n", oneHundredCoin);
//		printf("�ʿ� : %d��\n", tenCoin);
//		break;
//		
//		case 2 :
//		changedMoney = (int)(inputMoney / jpyChangeRate);
//		change = (inputMoney - (int)(changedMoney * jpyChangeRate)) / 10 * 10;
//		if (change > 999) {
//			oneThousandBill = change / 1000;
//			change = change % 1000; 
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		} else if (change < 1000) {
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		}
//		
//		change = oneThousandBill * 1000 + oneHundredCoin * 100 + tenCoin * 10;
//		printf("���� ȯ�� : %.2f\n", jpyChangeRate);
//		printf("ȯ�� ���\n");
//		printf("�� : %d��\n", changedMoney);
//		printf("�Ž����� : %d��\n", (int)change);
//		printf("õ�� : %d��\n", oneThousandBill);
//		printf("��� : %d��\n", oneHundredCoin);
//		printf("�ʿ� : %d��\n", tenCoin);
//		break;
//		
//		case 3:
//		changedMoney = (int)(inputMoney / eurChangeRate);
//		change = (inputMoney - (int)(changedMoney * eurChangeRate)) / 10 * 10;
//		if (change > 999) {
//			oneThousandBill = change / 1000;
//			change = change % 1000; 
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		} else if (change < 1000) {
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		}
//		
//		change = oneThousandBill * 1000 + oneHundredCoin * 100 + tenCoin * 10;
//		printf("���� ȯ�� : %.2f\n", eurChangeRate);
//		printf("ȯ�� ���\n");
//		printf("���� : %d����\n", changedMoney);
//		printf("�Ž����� : %d��\n", (int)change);
//		printf("õ�� : %d��\n", oneThousandBill);
//		printf("��� : %d��\n", oneHundredCoin);
//		printf("�ʿ� : %d��\n", tenCoin);
//		break;
//		
//		case 4:
//		changedMoney = (int)(inputMoney / cnyChangeRate);
//		change = (inputMoney - (int)(changedMoney * cnyChangeRate)) / 10 * 10;
//		if (change > 999) {
//			oneThousandBill = change / 1000;
//			change = change % 1000; 
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		} else if (change < 1000) {
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		}
//		
//		change = oneThousandBill * 1000 + oneHundredCoin * 100 + tenCoin * 10;
//		printf("���� ȯ�� : %.2f\n", cnyChangeRate);
//		printf("ȯ�� ���\n");
//		printf("���� : %d����\n", changedMoney);
//		printf("�Ž����� : %d��\n", (int)change);
//		printf("õ�� : %d��\n", oneThousandBill);
//		printf("��� : %d��\n", oneHundredCoin);
//		printf("�ʿ� : %d��\n", tenCoin);
//		break;
//		
//		case 5:
//		changedMoney = (int)(inputMoney / gbpChangeRate);
//		change = (inputMoney - (int)(changedMoney * gbpChangeRate)) / 10 * 10;
//		if (change > 999) {
//			oneThousandBill = change / 1000;
//			change = change % 1000; 
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		} else if (change < 1000) {
//			oneHundredCoin = change / 100;
//			change = change % 100;
//			tenCoin = change / 10;
//		}
//		
//		change = oneThousandBill * 1000 + oneHundredCoin * 100 + tenCoin * 10;
//		printf("���� ȯ�� : %.2f\n", gbpChangeRate);
//		printf("ȯ�� ���\n");
//		printf("�Ŀ�� : %d\n�Ŀ��", changedMoney);
//		printf("�Ž����� : %d��\n", (int)change);
//		printf("õ�� : %d��\n", oneThousandBill);
//		printf("��� : %d��\n", oneHundredCoin);
//		printf("�ʿ� : %d��\n", tenCoin);
//		break;
//	}
//}

// ���ϱ��� �� ���� ���ϱ� 
//int main() {
//	struct tm*t;
//	time_t base = time(NULL);
//	
//	t = localtime(&base);
//	
//	// tm_year�� ���� �⵵ - 1900�� ��, tm_mon�� 0~11���� ǥ�� 
//	printf("���ó�¥ %d�� %d�� %d��\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); 
//	
//	int birthYear, birthMonth, birthDay, age;
//	long long socialNumber;
//	
// 	printf("�ֹι�ȣ�� �Է��ϼ��� : ");
//    scanf("%lld", &socialNumber);
//    
//	birthYear = socialNumber / 100000000000 + 1900;
//	birthMonth = (socialNumber / 1000000000) - (birthYear - 1900) * 100;
//	birthDay = (socialNumber / 10000000) - (birthYear - 1900) * 10000 - birthMonth * 100;
//	
//	age = t->tm_year + 1900 - birthYear; // �⺻ ����
//	
//	if (birthMonth - (t->tm_mon + 1) < 0) { // �¾ ���� ���� �޺��� ���� ��� 
//		printf("�� ���� : %d\n", age); // �⺻ ���� �״�� ��� 
//	} else if (birthMonth - (t->tm_mon + 1) > 0) { // �¾ ���� ���� �޺��� ���� ��� 
//		printf("�� ���� : %d\n", age - 1); // ������ ���������Ƿ� �⺻ ���� -1 
//	} else { // �¾ ���� ���� �ް� ���ٸ� 
//		if (birthDay - (t->tm_mday) < 0) { // �¾ ���� �� 
//			printf("�� ���� : %d\n", age);
//		} else {
//			printf("�� ���� : %d\n", age - 1);
//		}
//	}
//	return 0;
//}

// ���� ������ 
//int main() {
//	int result;
//	int data;
//	
//	data = 5;
//	
//	result = data > 5 ? 10 : 200;
//	
//	printf("%d", result);
//} 

// �ݺ���
//int main() {
////	int inputNumber;
////	printf("�� ���� ���ðڽ��ϱ�? : ");
////	scanf("%d", &inputNumber);
////	for (int i = 1; i < 10; i++) {
////		printf("\n%d * %d = %d", inputNumber, i, inputNumber * i);
////		printf("\t%d * %d = %d", inputNumber + 1, i, (inputNumber + 1) * i);
////		printf("\t%d * %d = %d\n", inputNumber + 2, i, (inputNumber + 2) * i);
////	}
//	
//	int inputNumber;
//	printf("�� �ٿ� �? : ");
//	scanf("%d", &inputNumber);
//	for (int i = 2; i < 10; i += inputNumber) {
//		int cnt = 0;
//		for (int j = 1; j < 10; j++) {
//			int minus = 
//			if (inputNumber - 1 > j) {
//				printf("%d * %d = %d\t", (i + cnt), j, ((i + cnt) * j));	
//			} else {
//				
//			}
//			}
//			
//			if(cnt % inputNumber == 0) {
//				printf("\n");
//		}
////		printf("\n");
//	}
//} 

// ��,�� �Է¹޾Ƽ� �޷����
int isLeapYear(int inputYear) {
	if ((inputYear != 0) && (inputYear % 4 == 0) && (inputYear % 100 != 0) || (inputYear % 400 == 0)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int inputYear, inputMonth, lastyear, day;
	int totalday[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	printf("����� �޷��� ��,���� �Է��ϼ���");
	scanf("%d %d", &inputYear, &inputMonth);
	if(inputMonth == 2 && isLeapYear(inputYear) == 1) {
		totalday[2]=29;
	}
	
	lastyear = inputYear - 1;
	
	day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7; // ���� ���� ���ϴ� ���� 
	
	for (int i = 1; i < inputMonth; i++) {
		day += totalday[i];
	}
	
	day %= 7;
	
	printf("\n%11s%d�� %d��\n"," ", inputYear,inputMonth);
	printf("\n  ��  ��  ȭ  ��  ��  ��  ��");
	
	for (int i = -day; i < totalday[inputMonth]; i++) {
		if ((i + day) % 7 == 0) {
			printf("\n");
		}
		if (i < 0) {
			printf("%4s", " ");
		} else {
			printf("%4d", i + 1);
		}
	}
	printf("\n\n");
	
	return 0;
} 



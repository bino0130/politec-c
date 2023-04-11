#include <stdio.h>
#include <time.h> 

// 환전하기 
//int main() {
//	int inputMoney, choiceMenu, changedMoney, change, oneThousandBill, oneHundredCoin, tenCoin;
//	double usdChangeRate = 1319.83;
//	double jpyChangeRate = 9.98;
//	double eurChangeRate = 1439.45;
//	double cnyChangeRate = 191.97;
//	double gbpChangeRate = 1638.34;
//	
//	printf("환전을 원하는 금액을 입력하세요(원화) : ");
//	scanf("%d", &inputMoney);
//	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
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
//		printf("기준 환율 : %.2f\n", usdChangeRate);
//		printf("환전 결과\n");
//		printf("달러 : %d달러\n", changedMoney);
//		printf("거스름돈 : %d원\n", (int)change);
//		printf("천원 : %d장\n", oneThousandBill);
//		printf("백원 : %d개\n", oneHundredCoin);
//		printf("십원 : %d개\n", tenCoin);
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
//		printf("기준 환율 : %.2f\n", jpyChangeRate);
//		printf("환전 결과\n");
//		printf("엔 : %d엔\n", changedMoney);
//		printf("거스름돈 : %d원\n", (int)change);
//		printf("천원 : %d장\n", oneThousandBill);
//		printf("백원 : %d개\n", oneHundredCoin);
//		printf("십원 : %d개\n", tenCoin);
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
//		printf("기준 환율 : %.2f\n", eurChangeRate);
//		printf("환전 결과\n");
//		printf("유로 : %d유로\n", changedMoney);
//		printf("거스름돈 : %d원\n", (int)change);
//		printf("천원 : %d장\n", oneThousandBill);
//		printf("백원 : %d개\n", oneHundredCoin);
//		printf("십원 : %d개\n", tenCoin);
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
//		printf("기준 환율 : %.2f\n", cnyChangeRate);
//		printf("환전 결과\n");
//		printf("위안 : %d위안\n", changedMoney);
//		printf("거스름돈 : %d원\n", (int)change);
//		printf("천원 : %d장\n", oneThousandBill);
//		printf("백원 : %d개\n", oneHundredCoin);
//		printf("십원 : %d개\n", tenCoin);
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
//		printf("기준 환율 : %.2f\n", gbpChangeRate);
//		printf("환전 결과\n");
//		printf("파운드 : %d\n파운드", changedMoney);
//		printf("거스름돈 : %d원\n", (int)change);
//		printf("천원 : %d장\n", oneThousandBill);
//		printf("백원 : %d개\n", oneHundredCoin);
//		printf("십원 : %d개\n", tenCoin);
//		break;
//	}
//}

// 생일기준 만 나이 구하기 
int main() {
	struct tm*t;
	time_t base = time(NULL);
	
	t = localtime(&base);
	
	// tm_year는 현재 년도 - 1900한 값, tm_mon는 0~11까지 표현 
	printf("오늘날짜 %d년 %d월 %d일\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); 
	
	int birthYear, birthMonth, birthDay, age;
	long long socialNumber;
	
 	printf("주민번호를 입력하세요 : ");
    scanf("%lld", &socialNumber);
    
	birthYear = socialNumber / 100000000000 + 1900;
	birthMonth = (socialNumber / 1000000000) - (birthYear - 1900) * 100;
	birthDay = (socialNumber / 10000000) - (birthYear - 1900) * 10000 - birthMonth * 100;
	
	age = t->tm_year + 1900 - birthYear; // 기본 나이
	
	if (birthMonth - (t->tm_mon + 1) < 0) { // 태어난 달이 현재 달보다 빠른 경우 
		printf("만 나이 : %d\n", age); // 기본 나이 그대로 출력 
	} else if (birthMonth - (t->tm_mon + 1) > 0) { // 태어난 달이 현재 달보다 느린 경우 
		printf("만 나이 : %d\n", age - 1); // 생일이 안지났으므로 기본 나이 -1 
	} else { // 태어난 달이 현재 달과 같다면 
		if (birthDay - (t->tm_mday) < 0) { // 태어난 날로 비교 
			printf("만 나이 : %d\n", age);
		} else {
			printf("만 나이 : %d\n", age - 1);
		}
	}
	return 0;
}

// 삼항 연산자 
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

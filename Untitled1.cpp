#include <stdio.h>

int main() {
	int inputMoney, choiceMenu, changedMoney, change;
	double usdChangeRate = 1319.83;
	double jpyChangeRate = 9.98;
	double eurChangeRate = 1439.45;
	double cnyChangeRate = 191.97;
	double gbpChangeRate = 1638.34;
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputMoney);
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &choiceMenu);
	
	switch (choiceMenu) {
		case 1 :
		changedMoney = (int)(inputMoney / usdChangeRate);
		change = (inputMoney - (int)(changedMoney * usdChangeRate)) / 10 * 10;
		printf("기준 환율 : %.2f\n", usdChangeRate);
		printf("환전 결과\n");
		printf("달러 : %d달러\n", changedMoney);
		printf("거스름돈 : %d원\n", (int)change);
		break;
		
		case 2 :
		changedMoney = (int)(inputMoney / jpyChangeRate);
		change = (inputMoney - (int)(changedMoney * jpyChangeRate)) / 10 * 10;
		printf("기준 환율 : %.2f\n", jpyChangeRate);
		printf("환전 결과\n");
		printf("엔 : %d엔\n", changedMoney);
		printf("거스름돈 : %d원\n", (int)change);
		break;
		
		case 3:
		changedMoney = (int)(inputMoney / eurChangeRate);
		change = (inputMoney - (int)(changedMoney * eurChangeRate)) / 10 * 10;
		printf("기준 환율 : %.2f\n", eurChangeRate);
		printf("환전 결과\n");
		printf("유로 : %d유로\n", changedMoney);
		printf("거스름돈 : %d원\n", (int)change);
		break;
		
		case 4:
		changedMoney = (int)(inputMoney / cnyChangeRate);
		change = (inputMoney - (int)(changedMoney * cnyChangeRate)) / 10 * 10;
		printf("기준 환율 : %.2f\n", cnyChangeRate);
		printf("환전 결과\n");
		printf("위안 : %d위안\n", changedMoney);
		printf("거스름돈 : %d원\n", (int)change);
		break;
		
		case 5:
		changedMoney = (int)(inputMoney / gbpChangeRate);
		change = (inputMoney - (int)(changedMoney * gbpChangeRate)) / 10 * 10;
		printf("기준 환율 : %.2f\n", gbpChangeRate);
		printf("환전 결과\n");
		printf("파운드 : %d\n파운드", changedMoney);
		printf("거스름돈 : %d원\n", (int)change);
		break;
	}
}

#include <stdio.h>

int main() {
	int inputMoney, choiceMenu, changedMoney, change;
	double usdChangeRate = 1319.83;
	double jpyChangeRate = 9.98;
	double eurChangeRate = 1439.45;
	double cnyChangeRate = 191.97;
	double gbpChangeRate = 1638.34;
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputMoney);
	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &choiceMenu);
	
	switch (choiceMenu) {
		case 1 :
		changedMoney = (int)(inputMoney / usdChangeRate);
		change = (inputMoney - (int)(changedMoney * usdChangeRate)) / 10 * 10;
		printf("���� ȯ�� : %.2f\n", usdChangeRate);
		printf("ȯ�� ���\n");
		printf("�޷� : %d�޷�\n", changedMoney);
		printf("�Ž����� : %d��\n", (int)change);
		break;
		
		case 2 :
		changedMoney = (int)(inputMoney / jpyChangeRate);
		change = (inputMoney - (int)(changedMoney * jpyChangeRate)) / 10 * 10;
		printf("���� ȯ�� : %.2f\n", jpyChangeRate);
		printf("ȯ�� ���\n");
		printf("�� : %d��\n", changedMoney);
		printf("�Ž����� : %d��\n", (int)change);
		break;
		
		case 3:
		changedMoney = (int)(inputMoney / eurChangeRate);
		change = (inputMoney - (int)(changedMoney * eurChangeRate)) / 10 * 10;
		printf("���� ȯ�� : %.2f\n", eurChangeRate);
		printf("ȯ�� ���\n");
		printf("���� : %d����\n", changedMoney);
		printf("�Ž����� : %d��\n", (int)change);
		break;
		
		case 4:
		changedMoney = (int)(inputMoney / cnyChangeRate);
		change = (inputMoney - (int)(changedMoney * cnyChangeRate)) / 10 * 10;
		printf("���� ȯ�� : %.2f\n", cnyChangeRate);
		printf("ȯ�� ���\n");
		printf("���� : %d����\n", changedMoney);
		printf("�Ž����� : %d��\n", (int)change);
		break;
		
		case 5:
		changedMoney = (int)(inputMoney / gbpChangeRate);
		change = (inputMoney - (int)(changedMoney * gbpChangeRate)) / 10 * 10;
		printf("���� ȯ�� : %.2f\n", gbpChangeRate);
		printf("ȯ�� ���\n");
		printf("�Ŀ�� : %d\n�Ŀ��", changedMoney);
		printf("�Ž����� : %d��\n", (int)change);
		break;
	}
}

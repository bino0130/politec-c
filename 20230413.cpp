// �Ե����� ��ǥ��
// ������ �Է¹޴´�. (�ְ���, �߰���)
// �ֹε�Ϲ�ȣ�� �Է� �޴´�. (�ֹι�ȣ�� Ȱ���Ͽ� ���̸� �ڵ�����Ѵ�.)
// �ֹ� ������ �Է¹޴´�.
// �������� �Է¹޴´�. (����, �����, ����������, ���ڳ�, �ӻ��)
// ���� �Է��� �ݺ��� ������ ������ ������ �����.
// ���Ḧ �ϰԵǸ� ���ݱ��� �ֹ� ������ ��� ��µȴ�.
// ���� ���α׷� ���Ḧ �ϰ� �Ǹ� ��������� ���� ������ ���Ϸ� �����Ѵ�

// �߰�����  
 
#include <stdio.h>
int inputSocialNumber() { // �ֹε�Ϲ�ȣ �Է� �� ���̰��
	int birthYear, birthMonth, birthDay, age;
	char socialNumber[20];
	
	printf("�ֹι�ȣ�� �Է��ϼ���\n");
    scanf("%s", &socialNumber); // 123456-1234567
    
    if(socialNumber[7] == '1' || socialNumber[7] == '2') {
    	birthYear = 1900 + ((socialNumber[0] - '0') * 10 + (socialNumber[1] - '0'));
	} else {
		birthYear = 2000 + ((socialNumber[0] - '0') * 10 + (socialNumber[1] - '0'));
	}
	
	age = 2023 - birthYear + 1;
	
	printf("%���� : %d��\n", age);
	return age;
} 

int choiceNumber() { // ���� ���� 
	int selectNumber;
	
	printf("������ �����ϼ���.\n") ;
	printf("1. �ְ���\n");
	printf("2. �߰���\n");
	scanf("%d", &selectNumber);
	
	return selectNumber;
}

int dayNight() { // �ְ��� or �߰��� 
	int adultPrice, teenPrice, kidsPrice, babyPrice, adultNightPrice, 
	teenNightPrice, kidsNightPrice, babyNightPrice;
	
	int result = choiceNumber(); // choiceNumber ȣ�� 
	if(result == 1) {
		adultPrice = 59000;
		teenPrice = 52000;
		kidsPrice = 46000;
		babyPrice = 15000;
	} else if (result == 2) {
		adultNightPrice = 47000;
		teenNightPrice = 41000;
		kidsNightPrice = 35000;
		babyNightPrice = 15000;
	} else {
		printf("�߸� �Է��ϼ̽��ϴ�.");
	}
}

int countNumber() {
	int numberOfOrders;
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
    scanf("%d", &numberOfOrders);
    if (numberOfOrders > 10) {
    	printf("�ֹ� ���� ������ 1�δ� �ִ�  10�� �Դϴ�.\n");
	}
	
	return numberOfOrders;
} 

int main() {
	
	int specificCase, price, selectContinue;
	
	while(1) {
	///////////////////////////////////////// ���� ���� 
	
	///////////////////////////////////////// �ֹε�Ϲ�ȣ �Է� �� ���̰�� 
	inputSocialNumber();
    
    ///////////////////////////////////////// ���� ī��Ʈ 
    countNumber();
    
    ///////////////////////////////////////// ������ & ���ݰ�� 
    // ����� 40%
	// ���������� 50%
	// ���ڳ� 20%
	// �ӻ�� 15%
	// �ְ� : � 59 , û�ҳ� 52, ��� 46, ���� 15 
	// �߰� : � 47 , û�ҳ� 41, ��� 35, ���� 15 
    printf("�������� �����ϼ���.\n");
    printf("1. ���� (���� ���� �ڵ�ó��)\n"); // 65�� �̻��� ��� ��ݰ� �����ϰ� ó�� 
    printf("2. �����\n");
    printf("3. ����������\n");
    printf("4. ���ڳ�\n");
    printf("5. �ӻ��\n");
    scanf("%d", &specificCase);
    
//  adultPrice = adultPrice;
//	teenPrice = teenPrice;
//	kidsPrice = kidsPrice;
//	babyPrice = babyPrice;
    if (selectNumber == 1) { // �ְ����� �� 
    	if (specificCase == 1 && age >= 65) { //���x, ��� 
    		price = kidsPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 20 && age <= 64) { // ���x, � 
			price = adultPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 13 && age <= 19) { //���x, û�ҳ� 
			price = teenPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 3 && age <= 12) { //���x, ���� 
			price = kidsPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}  else if (specificCase == 1 && age <=  2) { //���x, ���� 
			price = babyPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 65) { //�����, ��� 
    		price = (int)(kidsPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 20 && age <= 64) { // �����, � 
			price = (int)(adultPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 13 && age <= 19) { //�����, û�ҳ� 
			price = (int)(teenPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 3 && age <= 12) { //�����, ���� 
			price = (int)(kidsPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}  else if (specificCase == 2 && age <= 2) { //�����, ���� 
			price = (int)(babyPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 65) { //����������, ���
			price = (int)(kidsPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 20 && age <= 64) { // ����������, � 
			price = (int)(adultPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 13 && age <= 19) { //����������, û�ҳ� 
			price = (int)(teenPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 3 && age <= 12) { //����������, ���� 
			price = (int)(kidsPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age <= 2) { //����������, ���� 
			price = (int)(babyPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 65) { //���ڳ�, ��� 
			price = (int)(kidsPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 20 && age <= 64) { // ���ڳ�, � 
			price = (int)(adultPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 13 && age <= 19) { //���ڳ�, û�ҳ� 
			price = (int)(teenPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 3 && age <= 12) { //���ڳ�, ���� 
			price = (int)(kidsPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age <= 2) { //���ڳ�, ���� 
			price = (int)(babyPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 5 && age >= 20 && age <= 64) { // �ӻ�� 
			price = (int)(adultPrice * 0.85) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}
	} else if (selectNumber == 2) {
		if (specificCase == 1 && age >= 65) { //���x, ��� 
    		price = kidsNightPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 20 && age <= 64) { // ���x, � 
			price = adultNightPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 13 && age <= 19) { //���x, û�ҳ� 
			price = teenNightPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 1 && age >= 3 && age <= 12) { //���x, ���� 
			price = kidsNightPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}  else if (specificCase == 1 && age <= 2) { //���x, ���� 
			price = babyNightPrice * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 65) { //�����, ��� 
    		price = (int)(kidsNightPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 20 && age <= 64) { // �����, � 
			price = (int)(adultNightPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 13 && age <= 19) { //�����, û�ҳ� 
			price = (int)(teenNightPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 2 && age >= 3 && age <= 12) { //�����, ���� 
			price = (int)(kidsNightPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}  else if (specificCase == 2 && age <= 2) { //�����, ���� 
			price = (int)(babyNightPrice * 0.6) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 65) { //����������, ���
			price = (int)(kidsNightPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 20 && age <= 64) { // ����������, � 
			price = (int)(adultNightPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 13 && age <= 19) { //����������, û�ҳ� 
			price = (int)(teenNightPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age >= 3 && age <= 12) { //����������, ���� 
			price = (int)(kidsNightPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 3 && age <= 2) { //����������, ���� 
			price = (int)(babyNightPrice * 0.5) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 65) { //���ڳ�, ��� 
			price = (int)(kidsNightPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 20 && age <= 64) { // ���ڳ�, � 
			price = (int)(adultNightPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 13 && age <= 19) { //���ڳ�, û�ҳ� 
			price = (int)(teenNightPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age >= 3 && age <= 12) { //���ڳ�, ���� 
			price = (int)(kidsNightPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 4 && age <= 2) { //���ڳ�, ���� 
			price = (int)(babyNightPrice * 0.8) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		} else if (specificCase == 5 && age >= 20 && age <= 64) { // �ӻ�� 
			price = (int)(adultNightPrice * 0.85) * numberOfOrders;
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
		}
	}
	
   printf("��� �߱� �Ͻðڽ��ϱ�?\n");
   printf("1. Ƽ�� �߱�\n");
   printf("2. ����\n");
   scanf("%d", &selectContinue);
   if (selectContinue == 2) {
   		printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n");
		break;   		
   } else if (selectContinue == 1){
   		continue;
   } 
 }
}

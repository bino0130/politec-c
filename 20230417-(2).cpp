#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �Ե����� �����̿�� ��� ���ϱ�
 
int choiceDayNight();
int inputSocialNumber(int selectTicket);
char getAgeGroup(int age);
char* judgeFemale(char* socialNumber);
int countNumber();
double treatment();
int calculPrice(int selectTicket, char ageGroup, char* gender);

int main() {
	int selectContinue = 0, price = 0;
	
	while(1) {
		price = choiceDayNight();
		printf("������ %d�� �Դϴ�.\n", price);
		printf("\n��� �߱� �Ͻðڽ��ϱ�?\n");
		printf("1. Ƽ�� �߱�\n");
		printf("2. ����\n");
		scanf("%d", &selectContinue);
		if (selectContinue == 2) {
			printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n");
			break;
		} else if (selectContinue == 1) {
			continue;
		} else {
			printf("error");
			exit(1);
		}
	}
}

int choiceDayNight() { // �ְ���/�߰��� ����
    int selectTicket;

    printf("������ �����ϼ���.\n");
    printf("1. �ְ���\n");
    printf("2. �߰���\n");
    scanf("%d", &selectTicket);
    if (selectTicket < 1 || selectTicket > 2) {
        printf("�ٽ� �����ϼ���.\n");
        exit(1);
    }
    return inputSocialNumber(selectTicket);
}

int inputSocialNumber(int selectTicket) { // �ֹε�Ϲ�ȣ �Է� -> ���̰��
    int birthYear = 0, birthMonth, birthDay, age;

    char ageGroup;
	char* gender;

	printf("�ֹε�Ϲ�ȣ�� �Է��ϼ���\n");
	char socialNumber[14]; // 123456-1234567���� '-' ���� �Է�
	scanf("%s", socialNumber);

	if (strlen(socialNumber) == 13) {
    	int yearPreFix = (socialNumber[0] - '0') * 10 + (socialNumber[1] - '0');
    	int genderDigit = (int)socialNumber[6] - '0';
    	if (genderDigit == 1 || genderDigit == 2) {
	        birthYear = 1900 + yearPreFix;
	    } else {
    	    birthYear = 2000 + yearPreFix;
    	}
	} else {
    	printf("�ֹε�Ϲ�ȣ�� 13�ڸ��Դϴ�.\n");
    	exit(1);
	}	

	age = 2023 - birthYear + 1; // ���̰��
	if (age < 1 || age > 105) {
    	printf("�߸��� �����Դϴ�.\n");
    	exit(1);
	}
	printf("���� : %d��\n", age);

	ageGroup = getAgeGroup(age);
	gender = judgeFemale(socialNumber);
	return calculPrice(selectTicket, ageGroup, gender);
}

char getAgeGroup(int age) { // ���� �޾Ƽ� ���ɴ� ����
    if (age >= 65) {
        return 'a'; // ���� 
    } else if (age >= 20 && age <= 64) {
        return 'b'; // ���� 
    } else if (age >= 13 && age <= 19) {
        return 'c'; // û�ҳ� 
    } else if (age >= 3 && age <= 12) {
        return 'd'; // ��� 
    } else if (age >= 1 && age <= 2) {
        return 'e'; // ���� 
    } else {
        return '0';
    }
}

char* judgeFemale(char* socialNumber) { // ���� Ȯ�� 
    char* gender = "";
    int genderDigit = socialNumber[6] - '0';
    if (genderDigit == 2 || genderDigit == 4) {
        gender = "woman";
        return gender;
    } else if (genderDigit == 1 || genderDigit == 3) {
        gender = "man";
    }
    return "";
}

int countNumber() { // Ƽ�� ���� 
    printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
    int numberOfOrders;
    scanf("%d", &numberOfOrders); 
    if (numberOfOrders > 10 || numberOfOrders < 0) {
        printf("�ֹ� ���� ������ 1�δ� 1������ �ִ� 10�� �Դϴ�.\n");
        exit(1);
    }
    return numberOfOrders;
}

double treatment() { // ������
		int specificCase;
		double discount;

		printf("�������� �����ϼ���.\n");
		printf("1. ���� (���� ���� �ڵ�ó��)\n"); // 65�� �̻��� ��� ��ݰ� �����ϰ� ó��
		printf("2. �����\n");
		printf("3. ����������\n");
		printf("4. ���ڳ�\n");
		printf("5. �ӻ��\n");
		scanf("%d", &specificCase);
		if (specificCase < 1 || specificCase > 5) {
			printf("�������� 1������ 5�� ���̷� ����ּ���");
			exit(1);
		}

		switch (specificCase) {
		case 1:
			discount = 1; // ����
			return discount;
		case 2:
			discount = 0.6; // �����
			return discount;
		case 3:
			discount = 0.5; // ����������
			return discount;
		case 4:
			discount = 0.8; // ���ڳ�
			return discount;
		case 5:
			discount = 0.85; // �ӻ��
			return discount;
		}
		return 0;
}

int calculPrice(int selectTicket, char ageGroup, char* gender) { // ���� ���� ��� 
	int ticketNumbers, temporaryPrice = 0, finalPrice;
	// temporaryPrice = �ְ���/�߰���, ����, ������ 3���� ���
	// finalPrice = temporaryPrice�� Ƽ�� ��� ������ 
	double discountTicket;

	ticketNumbers = countNumber();
	discountTicket = treatment();

	if (discountTicket == 0.85) {
    	if (ageGroup != 'b' || strcmp(gender, "woman") != 0) {
        	printf("�ӻ�� �������� ���� �������Ը� ����˴ϴ�.");
        	exit(1);
    	}
	}
	
	switch (selectTicket) {
		case 1: // �ְ��� 
			switch (ageGroup) {
			case 'a': // ���� 
				if (discountTicket == 1) { // ������ ���� 
					temporaryPrice = 46000;
				} else if (discountTicket == 0.6) { // ������ ����� 
					temporaryPrice = (int) (46000 * discountTicket); 
				} else if (discountTicket == 0.5) { // ������ ���������� 
					temporaryPrice = (int) (46000 * discountTicket); 
				} else if (discountTicket == 0.8) { // ������ ���ڳ� 
					temporaryPrice = (int) (46000 * discountTicket);
				}
				break;
			case 'b': // ���� 
				if (discountTicket == 1) { // ������ ���� 
					temporaryPrice = 59000;
				} else if (discountTicket == 0.6) { // ������ ����� 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.5) { // ������ ���������� 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.8) { // ������ ���ڳ� 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.85) { // ������ �ӻ�� 
					temporaryPrice = (int) (59000 * discountTicket);
				}
				break;
			case 'c': // û�ҳ� 
				if (discountTicket == 1) { // ������ ���� 
					temporaryPrice = 52000;
				} else if (discountTicket == 0.6) { // ������ �����
					temporaryPrice = (int) (52000 * discountTicket);
				} else if (discountTicket == 0.5) { // ������ ����������
					temporaryPrice = (int) (52000 * discountTicket);
				} else if (discountTicket == 0.8) { // ������ ���ڳ�
					temporaryPrice = (int) (52000 * discountTicket);
				}
				break;
			case 'd': // ��� 
				if (discountTicket == 1) { // ������ ���� 
					temporaryPrice = 46000;
				} else if (discountTicket == 0.6) { // ������ �����
					temporaryPrice = (int) (46000 * discountTicket);
				} else if (discountTicket == 0.5) { // ������ ����������
					temporaryPrice = (int) (46000 * discountTicket);
				} else if (discountTicket == 0.8) { // ������ ���ڳ�
					temporaryPrice = (int) (46000 * discountTicket);
				}
				break;
			case 'e': // ���� 
				if (discountTicket == 1) { // ������ ���� 
					temporaryPrice = 15000;
				} else if (discountTicket == 0.6) { // ������ �����
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.5) { // ������ ����������
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.8) { // ������ ���ڳ�
					temporaryPrice = (int) (15000 * discountTicket);
				}
				break;
			}
			break;
		case 2: // �߰��� 
			switch (ageGroup) {
			case 'a': // ���� 
				if (discountTicket == 1) {
					temporaryPrice = 35000;
				} else if (discountTicket == 0.6) {
					temporaryPrice = (int) (35000 * discountTicket);
				} else if (discountTicket == 0.5) {
					temporaryPrice = (int) (35000 * discountTicket);
				} else if (discountTicket == 0.8) {
					temporaryPrice = (int) (35000 * discountTicket);
				}
				break;
			case 'b': // ���� 
				if (discountTicket == 1) {
					temporaryPrice = 47000;
				} else if (discountTicket == 0.6) {
					temporaryPrice = (int) (47000 * discountTicket);
				} else if (discountTicket == 0.5) {
					temporaryPrice = (int) (47000 * discountTicket);
				} else if (discountTicket == 0.8) {
					temporaryPrice = (int) (47000 * discountTicket);
				} else if (discountTicket == 0.85) {
					temporaryPrice = (int) (47000 * discountTicket);
				}
				break;
			case 'c': // û�ҳ� 
				if (discountTicket == 1) {
					temporaryPrice = 41000;
				} else if (discountTicket == 0.6) {
					temporaryPrice = (int) (41000 * discountTicket);
				} else if (discountTicket == 0.5) {
					temporaryPrice = (int) (41000 * discountTicket);
				} else if (discountTicket == 0.8) {
					temporaryPrice = (int) (41000 * discountTicket);
				}
				break;
			case 'd': // ��� 
				if (discountTicket == 1) {
					temporaryPrice = 35000;
				} else if (discountTicket == 0.6) {
					temporaryPrice = (int) (35000 * discountTicket);
				} else if (discountTicket == 0.5) {
					temporaryPrice = (int) (35000 * discountTicket);
				} else if (discountTicket == 0.8) {
					temporaryPrice = (int) (35000 * discountTicket);
				}
				break;
			case 'e': // ���� 
				if (discountTicket == 1) {
					temporaryPrice = 15000;
				} else if (discountTicket == 0.6) {
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.5) {
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.8) {
					temporaryPrice = (int) (15000 * discountTicket);
				}
				break;
			}
			break;
		}
		finalPrice = temporaryPrice * ticketNumbers; // ���� ���� = �ӽ� ���ݿ� Ƽ�� ��� ������ 
		return finalPrice;
}

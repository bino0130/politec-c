#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 롯데월드 자유이용권 요금 구하기
 
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
		printf("가격은 %d원 입니다.\n", price);
		printf("\n계속 발권 하시겠습니까?\n");
		printf("1. 티켓 발권\n");
		printf("2. 종료\n");
		scanf("%d", &selectContinue);
		if (selectContinue == 2) {
			printf("티켓 발권을 종료합니다. 감사합니다.\n");
			break;
		} else if (selectContinue == 1) {
			continue;
		} else {
			printf("error");
			exit(1);
		}
	}
}

int choiceDayNight() { // 주간권/야간권 선택
    int selectTicket;

    printf("권종을 선택하세요.\n");
    printf("1. 주간권\n");
    printf("2. 야간권\n");
    scanf("%d", &selectTicket);
    if (selectTicket < 1 || selectTicket > 2) {
        printf("다시 선택하세요.\n");
        exit(1);
    }
    return inputSocialNumber(selectTicket);
}

int inputSocialNumber(int selectTicket) { // 주민등록번호 입력 -> 나이계산
    int birthYear = 0, birthMonth, birthDay, age;

    char ageGroup;
	char* gender;

	printf("주민등록번호를 입력하세요\n");
	char socialNumber[14]; // 123456-1234567에서 '-' 빼고 입력
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
    	printf("주민등록번호는 13자리입니다.\n");
    	exit(1);
	}	

	age = 2023 - birthYear + 1; // 나이계산
	if (age < 1 || age > 105) {
    	printf("잘못된 나이입니다.\n");
    	exit(1);
	}
	printf("나이 : %d살\n", age);

	ageGroup = getAgeGroup(age);
	gender = judgeFemale(socialNumber);
	return calculPrice(selectTicket, ageGroup, gender);
}

char getAgeGroup(int age) { // 나이 받아서 연령대 리턴
    if (age >= 65) {
        return 'a'; // 노인 
    } else if (age >= 20 && age <= 64) {
        return 'b'; // 성인 
    } else if (age >= 13 && age <= 19) {
        return 'c'; // 청소년 
    } else if (age >= 3 && age <= 12) {
        return 'd'; // 어린이 
    } else if (age >= 1 && age <= 2) {
        return 'e'; // 유아 
    } else {
        return '0';
    }
}

char* judgeFemale(char* socialNumber) { // 성별 확인 
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

int countNumber() { // 티켓 개수 
    printf("몇개를 주문하시겠습니까? (최대 10개)\n");
    int numberOfOrders;
    scanf("%d", &numberOfOrders); 
    if (numberOfOrders > 10 || numberOfOrders < 0) {
        printf("주문 가능 개수는 1인당 1개에서 최대 10개 입니다.\n");
        exit(1);
    }
    return numberOfOrders;
}

double treatment() { // 우대사항
		int specificCase;
		double discount;

		printf("우대사항을 선택하세요.\n");
		printf("1. 없음 (나이 우대는 자동처리)\n"); // 65세 이상은 어린이 요금과 동일하게 처리
		printf("2. 장애인\n");
		printf("3. 국가유공자\n");
		printf("4. 다자녀\n");
		printf("5. 임산부\n");
		scanf("%d", &specificCase);
		if (specificCase < 1 || specificCase > 5) {
			printf("우대사항은 1번에서 5번 사이로 골라주세요");
			exit(1);
		}

		switch (specificCase) {
		case 1:
			discount = 1; // 없음
			return discount;
		case 2:
			discount = 0.6; // 장애인
			return discount;
		case 3:
			discount = 0.5; // 국가유공자
			return discount;
		case 4:
			discount = 0.8; // 다자녀
			return discount;
		case 5:
			discount = 0.85; // 임산부
			return discount;
		}
		return 0;
}

int calculPrice(int selectTicket, char ageGroup, char* gender) { // 최종 가격 계산 
	int ticketNumbers, temporaryPrice = 0, finalPrice;
	// temporaryPrice = 주간권/야간권, 나이, 우대사항 3가지 계산
	// finalPrice = temporaryPrice에 티켓 장수 곱해줌 
	double discountTicket;

	ticketNumbers = countNumber();
	discountTicket = treatment();

	if (discountTicket == 0.85) {
    	if (ageGroup != 'b' || strcmp(gender, "woman") != 0) {
        	printf("임산부 우대사항은 성인 여성에게만 적용됩니다.");
        	exit(1);
    	}
	}
	
	switch (selectTicket) {
		case 1: // 주간권 
			switch (ageGroup) {
			case 'a': // 노인 
				if (discountTicket == 1) { // 우대사항 없음 
					temporaryPrice = 46000;
				} else if (discountTicket == 0.6) { // 우대사항 장애인 
					temporaryPrice = (int) (46000 * discountTicket); 
				} else if (discountTicket == 0.5) { // 우대사항 국가유공자 
					temporaryPrice = (int) (46000 * discountTicket); 
				} else if (discountTicket == 0.8) { // 우대사항 다자녀 
					temporaryPrice = (int) (46000 * discountTicket);
				}
				break;
			case 'b': // 성인 
				if (discountTicket == 1) { // 우대사항 없음 
					temporaryPrice = 59000;
				} else if (discountTicket == 0.6) { // 우대사항 장애인 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.5) { // 우대사항 국가유공자 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.8) { // 우대사항 다자녀 
					temporaryPrice = (int) (59000 * discountTicket);
				} else if (discountTicket == 0.85) { // 우대사항 임산부 
					temporaryPrice = (int) (59000 * discountTicket);
				}
				break;
			case 'c': // 청소년 
				if (discountTicket == 1) { // 우대사항 없음 
					temporaryPrice = 52000;
				} else if (discountTicket == 0.6) { // 우대사항 장애인
					temporaryPrice = (int) (52000 * discountTicket);
				} else if (discountTicket == 0.5) { // 우대사항 국가유공자
					temporaryPrice = (int) (52000 * discountTicket);
				} else if (discountTicket == 0.8) { // 우대사항 다자녀
					temporaryPrice = (int) (52000 * discountTicket);
				}
				break;
			case 'd': // 어린이 
				if (discountTicket == 1) { // 우대사항 없음 
					temporaryPrice = 46000;
				} else if (discountTicket == 0.6) { // 우대사항 장애인
					temporaryPrice = (int) (46000 * discountTicket);
				} else if (discountTicket == 0.5) { // 우대사항 국가유공자
					temporaryPrice = (int) (46000 * discountTicket);
				} else if (discountTicket == 0.8) { // 우대사항 다자녀
					temporaryPrice = (int) (46000 * discountTicket);
				}
				break;
			case 'e': // 유아 
				if (discountTicket == 1) { // 우대사항 없음 
					temporaryPrice = 15000;
				} else if (discountTicket == 0.6) { // 우대사항 장애인
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.5) { // 우대사항 국가유공자
					temporaryPrice = (int) (15000 * discountTicket);
				} else if (discountTicket == 0.8) { // 우대사항 다자녀
					temporaryPrice = (int) (15000 * discountTicket);
				}
				break;
			}
			break;
		case 2: // 야간권 
			switch (ageGroup) {
			case 'a': // 노인 
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
			case 'b': // 성인 
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
			case 'c': // 청소년 
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
			case 'd': // 어린이 
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
			case 'e': // 유아 
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
		finalPrice = temporaryPrice * ticketNumbers; // 최종 가격 = 임시 가격에 티켓 장수 곱해줌 
		return finalPrice;
}

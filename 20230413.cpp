// 롯데월드 매표소
// 권종을 입력받는다. (주간권, 야간권)
// 주민등록번호를 입력 받는다. (주민번호를 활용하여 나이를 자동계산한다.)
// 주문 개수를 입력받는다.
// 우대사항을 입력받는다. (없음, 장애인, 국가유공자, 다자녀, 임산부)
// 위의 입력을 반복할 것인지 종료할 것인지 물어본다.
// 종료를 하게되면 지금까지 주문 내역이 모두 출력된다.
// 완전 프로그램 종료를 하게 되면 현재까지의 매출 내역을 파일로 저장한다

// 야간권은  
 
#include <stdio.h>
int inputSocialNumber() { // 주민등록번호 입력 후 나이계산
	int birthYear, birthMonth, birthDay, age;
	char socialNumber[20];
	
	printf("주민번호를 입력하세요\n");
    scanf("%s", &socialNumber); // 123456-1234567
    
    if(socialNumber[7] == '1' || socialNumber[7] == '2') {
    	birthYear = 1900 + ((socialNumber[0] - '0') * 10 + (socialNumber[1] - '0'));
	} else {
		birthYear = 2000 + ((socialNumber[0] - '0') * 10 + (socialNumber[1] - '0'));
	}
	
	age = 2023 - birthYear + 1;
	
	printf("%나이 : %d살\n", age);
	return age;
} 

int choiceNumber() { // 권종 선택 
	int selectNumber;
	
	printf("권종을 선택하세요.\n") ;
	printf("1. 주간권\n");
	printf("2. 야간권\n");
	scanf("%d", &selectNumber);
	
	return selectNumber;
}

int dayNight() { // 주간권 or 야간권 
	int adultPrice, teenPrice, kidsPrice, babyPrice, adultNightPrice, 
	teenNightPrice, kidsNightPrice, babyNightPrice;
	
	int result = choiceNumber(); // choiceNumber 호출 
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
		printf("잘못 입력하셨습니다.");
	}
}

int countNumber() {
	int numberOfOrders;
	printf("몇개를 주문하시겠습니까? (최대 10개)\n");
    scanf("%d", &numberOfOrders);
    if (numberOfOrders > 10) {
    	printf("주문 가능 개수는 1인당 최대  10개 입니다.\n");
	}
	
	return numberOfOrders;
} 

int main() {
	
	int specificCase, price, selectContinue;
	
	while(1) {
	///////////////////////////////////////// 권종 선택 
	
	///////////////////////////////////////// 주민등록번호 입력 후 나이계산 
	inputSocialNumber();
    
    ///////////////////////////////////////// 개수 카운트 
    countNumber();
    
    ///////////////////////////////////////// 우대사항 & 가격계산 
    // 장애인 40%
	// 국가유공자 50%
	// 다자녀 20%
	// 임산부 15%
	// 주간 : 어른 59 , 청소년 52, 어린이 46, 유아 15 
	// 야간 : 어른 47 , 청소년 41, 어린이 35, 유아 15 
    printf("우대사항을 선택하세요.\n");
    printf("1. 없음 (나이 우대는 자동처리)\n"); // 65세 이상은 어린이 요금과 동일하게 처리 
    printf("2. 장애인\n");
    printf("3. 국가유공자\n");
    printf("4. 다자녀\n");
    printf("5. 임산부\n");
    scanf("%d", &specificCase);
    
//  adultPrice = adultPrice;
//	teenPrice = teenPrice;
//	kidsPrice = kidsPrice;
//	babyPrice = babyPrice;
    if (selectNumber == 1) { // 주간권일 때 
    	if (specificCase == 1 && age >= 65) { //우대x, 경로 
    		price = kidsPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 20 && age <= 64) { // 우대x, 어른 
			price = adultPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 13 && age <= 19) { //우대x, 청소년 
			price = teenPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 3 && age <= 12) { //우대x, 아이 
			price = kidsPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}  else if (specificCase == 1 && age <=  2) { //우대x, 유아 
			price = babyPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 65) { //장애인, 경로 
    		price = (int)(kidsPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 20 && age <= 64) { // 장애인, 어른 
			price = (int)(adultPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 13 && age <= 19) { //장애인, 청소년 
			price = (int)(teenPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 3 && age <= 12) { //장애인, 아이 
			price = (int)(kidsPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}  else if (specificCase == 2 && age <= 2) { //장애인, 유아 
			price = (int)(babyPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 65) { //국가유공자, 경로
			price = (int)(kidsPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 20 && age <= 64) { // 국가유공자, 어른 
			price = (int)(adultPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 13 && age <= 19) { //국가유공자, 청소년 
			price = (int)(teenPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 3 && age <= 12) { //국가유공자, 아이 
			price = (int)(kidsPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age <= 2) { //국가유공자, 유아 
			price = (int)(babyPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 65) { //다자녀, 경로 
			price = (int)(kidsPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 20 && age <= 64) { // 다자녀, 어른 
			price = (int)(adultPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 13 && age <= 19) { //다자녀, 청소년 
			price = (int)(teenPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 3 && age <= 12) { //다자녀, 아이 
			price = (int)(kidsPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age <= 2) { //다자녀, 유아 
			price = (int)(babyPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 5 && age >= 20 && age <= 64) { // 임산부 
			price = (int)(adultPrice * 0.85) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}
	} else if (selectNumber == 2) {
		if (specificCase == 1 && age >= 65) { //우대x, 경로 
    		price = kidsNightPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 20 && age <= 64) { // 우대x, 어른 
			price = adultNightPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 13 && age <= 19) { //우대x, 청소년 
			price = teenNightPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 1 && age >= 3 && age <= 12) { //우대x, 아이 
			price = kidsNightPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}  else if (specificCase == 1 && age <= 2) { //우대x, 유아 
			price = babyNightPrice * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 65) { //장애인, 경로 
    		price = (int)(kidsNightPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 20 && age <= 64) { // 장애인, 어른 
			price = (int)(adultNightPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 13 && age <= 19) { //장애인, 청소년 
			price = (int)(teenNightPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 2 && age >= 3 && age <= 12) { //장애인, 아이 
			price = (int)(kidsNightPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}  else if (specificCase == 2 && age <= 2) { //장애인, 유아 
			price = (int)(babyNightPrice * 0.6) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 65) { //국가유공자, 경로
			price = (int)(kidsNightPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 20 && age <= 64) { // 국가유공자, 어른 
			price = (int)(adultNightPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 13 && age <= 19) { //국가유공자, 청소년 
			price = (int)(teenNightPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age >= 3 && age <= 12) { //국가유공자, 아이 
			price = (int)(kidsNightPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 3 && age <= 2) { //국가유공자, 유아 
			price = (int)(babyNightPrice * 0.5) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 65) { //다자녀, 경로 
			price = (int)(kidsNightPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 20 && age <= 64) { // 다자녀, 어른 
			price = (int)(adultNightPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 13 && age <= 19) { //다자녀, 청소년 
			price = (int)(teenNightPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age >= 3 && age <= 12) { //다자녀, 아이 
			price = (int)(kidsNightPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 4 && age <= 2) { //다자녀, 유아 
			price = (int)(babyNightPrice * 0.8) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		} else if (specificCase == 5 && age >= 20 && age <= 64) { // 임산부 
			price = (int)(adultNightPrice * 0.85) * numberOfOrders;
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
		}
	}
	
   printf("계속 발권 하시겠습니까?\n");
   printf("1. 티켓 발권\n");
   printf("2. 종료\n");
   scanf("%d", &selectContinue);
   if (selectContinue == 2) {
   		printf("티켓 발권을 종료합니다. 감사합니다.\n");
		break;   		
   } else if (selectContinue == 1){
   		continue;
   } 
 }
}

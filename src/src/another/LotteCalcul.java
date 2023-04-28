package another;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class LotteCalcul {
	List<OrderList> data = new ArrayList<OrderList>();
	int totalCost = 0;

	String calculDayNightTicket(int inputSelectTicket) throws Exception { // 권종 선택
		String ticketType = "";

		if (inputSelectTicket < 1 || inputSelectTicket > 2) {
			throw new Exception(LanguagePrintClass.getMsg("dayNightTicketCalculError")); // 예외 처리
		}

		if (inputSelectTicket == 1) {
			ticketType = LanguagePrintClass.getMsg("dayTicketCalcul");
			return ticketType;
		} else if (inputSelectTicket == 2) {
			ticketType = LanguagePrintClass.getMsg("nightTicketCalcul");
			return ticketType; // 주간권/야간권 리턴
		}
		return "";
	}

	String[] calculSocialNumber(String socialNumber) throws Exception { // 주민번호 입력받아 나이,성별 구하기
		LotteOutput lo = new LotteOutput();
		int birthYear = 0, age;

		if (socialNumber.length() == 13) {
			String ageGroup = null, gender = null;
			int yearPreFix = Integer.parseInt(socialNumber.substring(0, 2));
			int genderDigit = Character.getNumericValue(socialNumber.charAt(6));
			if (genderDigit == 1 || genderDigit == 2) {
				birthYear = 1900 + yearPreFix;
			} else {
				birthYear = 2000 + yearPreFix;
			}
		} else {
			throw new Exception(LanguagePrintClass.getMsg("socialNumberCalculError")); // 예외 처리
		}

		age = 2023 - birthYear + 1; // 나이계산
		if (age < 1 || age > 105) {
			throw new Exception(LanguagePrintClass.getMsg("ageError")); // 예외 처리
		}

		lo.printAge(age); // 나이 출력

		String ageGroup = getAgeGroup(age);
		String gender = judgeFemale(socialNumber);
		String[] ageGender = { ageGroup, gender };
		return ageGender; // 연령대, 성별 리턴
	}

	String getAgeGroup(int age) { // 나이 받아서 연령대 리턴

		if (age >= 65) {
			return LanguagePrintClass.getMsg("getAgeGroup1");
		} else if (age >= 20 && age <= 64) {
			return LanguagePrintClass.getMsg("getAgeGroup2");
		} else if (age >= 13 && age <= 19) {
			return LanguagePrintClass.getMsg("getAgeGroup3");
		} else if (age >= 3 && age <= 12) {
			return LanguagePrintClass.getMsg("getAgeGroup4");
		} else if (age >= 1 && age <= 2) {
			return LanguagePrintClass.getMsg("getAgeGroup5");
		} else {
			return LanguagePrintClass.getMsg("getAgeGroup6");
		}

	}

	String judgeFemale(String socialNumber) { // 성별 판단
		String gender = "";
		int genderDigit = Character.getNumericValue(socialNumber.charAt(6));

		if (genderDigit == 2 || genderDigit == 4) {
			gender = LanguagePrintClass.getMsg("femaleJudge");
			return gender;
		} else if (genderDigit == 1 || genderDigit == 3) {
			gender = LanguagePrintClass.getMsg("maleJudge");
			return gender;
		}
		return "";
	}

	int calculCountNumbers(int numberOfOrders) throws Exception { // 티켓 개수 계산

		if (numberOfOrders > 10 || numberOfOrders < 0) {
			throw new Exception(LanguagePrintClass.getMsg("countNumbersCalculError")); // 예외 처리
		}
		return numberOfOrders;
	}

	double calculTreatment(int specificCase) throws Exception { // 우대사항
		double discount = 0;

		if (specificCase < 1 || specificCase > 5) {
			throw new Exception(LanguagePrintClass.getMsg("treatmentCalculError")); // 예외 처리
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
		return discount;
	}

	int calculPrice() throws Exception { // 권종, 연령대, 성별, 티켓 개수 리턴받아 최종 가격 계산
		LotteInput li = new LotteInput();
		LotteTicketPrice ltp = new LotteTicketPrice();
		LotteOutput lo = new LotteOutput();
		String ticketType, ageGroup, gender, choiceLanguage;
		String[] ageGender;
		int ticketNumbers, temporaryPrice = 0, finalPrice;
		double discountRate;

		choiceLanguage = li.choiceLanguage();
		ticketType = li.choiceDayNight(); // 권종
		li.removeEnter();
		ageGender = li.inputSocialNumber(); // 배열 ageGender (연령대, 성별포함)
		ticketNumbers = li.countNumber(); // 티켓 수
		discountRate = li.treatment(); // 우대사항
		ageGroup = ageGender[0]; // 연령대
		gender = ageGender[1]; // 성별

		if (discountRate == 0.85) { // 임산부 예외처리
			if (!ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup2").toString())
					|| !gender.equals(LanguagePrintClass.getMsg("femaleJudge").toString())) {
				throw new Exception(LanguagePrintClass.getMsg("pregnantError")); // 예외 처리
			}
		}

		if (ticketType.equals(LanguagePrintClass.getMsg("dayTicketCalcul"))) {
			if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup1"))) { // 주간권 노인
				if (discountRate == 1) {
					temporaryPrice = ltp.getDayold();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getDayold() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getDayold() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getDayold() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup2"))) { // 주간권 성인
				if (discountRate == 1) {
					temporaryPrice = ltp.getDayadult();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
				} else if (discountRate == 0.85) {
					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup3").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getDayteen();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup4").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getDaykids();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup5").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getDaybaby();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
				}
			}
		} else if (ticketType.equals(LanguagePrintClass.getMsg("nightTicketCalcul").toString())) {
			if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup1").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getNightold();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getNightold() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getNightold() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getNightold() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup2").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getNightadult();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
				} else if (discountRate == 0.85) {
					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup3").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getDayteen();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup4").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getNightkids();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
				}
			} else if (ageGroup.equals(LanguagePrintClass.getMsg("getAgeGroup5").toString())) {
				if (discountRate == 1) {
					temporaryPrice = ltp.getNightbaby();
				} else if (discountRate == 0.6) {
					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
				} else if (discountRate == 0.5) {
					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
				} else if (discountRate == 0.8) {
					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
				}
			}
		}
//		switch (ticketType) {
//		case "주간권":
//			switch (ageGroup) {
//			case "노인":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getDayold();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getDayold() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getDayold() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getDayold() * discountRate);
//				}
//				break;
//			case "성인":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getDayadult();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
//				} else if (discountRate == 0.85) {
//					temporaryPrice = (int) (ltp.getDayadult() * discountRate);
//				}
//				break;
//			case "청소년":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getDayteen();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getDayteen() * discountRate);
//				}
//				break;
//			case "어린이":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getDaykids();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getDaykids() * discountRate);
//				}
//				break;
//			case "유아":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getDaybaby();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getDaybaby() * discountRate);
//				}
//				break;
//			}
//			break;
//		case "야간권":
//			switch (ageGroup) {
//			case "노인":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getNightold();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getNightold() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getNightold() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getNightold() * discountRate);
//				}
//				break;
//			case "성인":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getNightadult();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
//				} else if (discountRate == 0.85) {
//					temporaryPrice = (int) (ltp.getNightadult() * discountRate);
//				}
//				break;
//			case "청소년":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getNightteen();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getNightteen() * discountRate);
//				}
//				break;
//			case "어린이":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getNightkids();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getNightkids() * discountRate);
//				}
//				break;
//			case "유아":
//				if (discountRate == 1) {
//					temporaryPrice = ltp.getNightbaby();
//				} else if (discountRate == 0.6) {
//					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
//				} else if (discountRate == 0.5) {
//					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
//				} else if (discountRate == 0.8) {
//					temporaryPrice = (int) (ltp.getNightbaby() * discountRate);
//				}
//				break;
//			}
//			break;
//		}
		finalPrice = temporaryPrice * ticketNumbers; // 최종 가격 = 임시가격 * 티켓 개수

		totalCost += finalPrice; // 토탈 가격 = 최종가격 누적합
		saveData(ticketType, ageGroup, gender, ticketNumbers, discountRate, finalPrice, totalCost); // savedata에
																									// parameter 전달

		return lo.printPrice(finalPrice);
	}

	int decideContinue(int selectContinue) throws Exception {
		LotteOutput lo = new LotteOutput();
		if (selectContinue < 1 && selectContinue > 2) {
			throw new Exception(LotteTicketPrice.getDecidecontinueexception()); // 예외 처리
		}
		return lo.printEnd(selectContinue); // LotteOutput의 PrintEnd에 selecContinue를 parameter로 리턴
	}

	void saveData(String ticketType, String ageGroup, String gender, int amount, double option, int cost,
			int totalCost) {

		// 6개의 변수를 parameter로 받는 OrderList 객체 ol 선언
		OrderList ol = new OrderList(ticketType, ageGroup, amount, option, cost, totalCost);
		data.add(ol); // data에 ol 추가
	}

	List<OrderList> deliverData() throws FileNotFoundException {
		LotteOutput lo = new LotteOutput();
		return lo.output(data, totalCost);
	}

	void makeCsv(List<OrderList> data) throws IOException {
		LotteOutput lo = new LotteOutput();
		String filePath = "C:\\Users\\Bino\\Desktop\\user.csv";
		String charsetName = "UTF-8"; // 인코딩 방식 설정
		File file = new File(filePath);
		boolean isFileExists = file.exists() && file.isFile();
		try (BufferedWriter writer = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(filePath, true), charsetName))) {
			if (!isFileExists) { // 파일이 새로 생성된 것이라면 header를 작성합니다.
				System.out.println("starting write user.csv file: " + filePath);
				writer.write("ticketType,ageGroup,amount,cost,discount\n");
			}
			writeCsv(writer, data);
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("starting read user.csv file");
		lo.readCsv(filePath);
	}

	void writeCsv(Writer writer, List<OrderList> data) throws IOException {

//			writer.write("ticketType,ageGroup,amount,cost,discount\n");
		for (OrderList csvList : data) {
			double option = csvList.getOption();
			String discount = null;
			if (option == 1) {
				discount = LanguagePrintClass.getMsg("discount1");
			} else if (option == 0.6) {
				discount = LanguagePrintClass.getMsg("discount2");
			} else if (option == 0.5) {
				discount = LanguagePrintClass.getMsg("discount3");
			} else if (option == 0.8) {
				discount = LanguagePrintClass.getMsg("discount4");
			} else if (option == 0.85) {
				discount = LanguagePrintClass.getMsg("discount5");
			}

			writer.write(csvList.getTicketType() + ",");
			writer.write(csvList.getAgeGroup() + ",");
			writer.write(csvList.getAmount() + ",");
			writer.write(csvList.getCost() + ",");
			writer.write(discount + "\n");
//			writer.write( + "\n");
		}
	}
}
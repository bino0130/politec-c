package another;

public class LotteTicketPrice {

	// 연령별 주간권 가격
	private final static int DayOld = 46000;
	private final static int DayAdult = 59000;
	private final static int DayTeen = 52000;
	private final static int DayKids = 46000;
	private final static int DayBaby = 15000;

	// 연령별 야간권 가격
	private final static int NightOld = 35000;
	private final static int NightAdult = 47000;
	private final static int NightTeen = 41000;
	private final static int NightKids = 35000;
	private final static int NightBaby = 15000;

	public static final String KOREAN = "1";
	public static final String ENGLISH = "2";
//	public static final String ITALY = "3";

	public static final String LANGUAGE_KR = "KR";
	public static final String LANGUAGE_US = "US";

	private static String choiceDayNightKR1 = "권종을 선택하세요.";
	private static String choiceDayNightKR2 = "1. 주간권";
	private static String choiceDayNightKR3 = "2. 야간권";

	private final static String choiceDayNightUs1 = "Choose Ticket Type.";
	private final static String choiceDayNightUs2 = "1. Day Type";
	private final static String choiceDayNightUs3 = "2. Night Type";

	private final static String inputSocialNumberKR = "주민등록번호를 입력하세요.\n";
	private final static String inputSocialNumberUS = "Input Your SocialNumber\n";

	private final static String countNumberKR = "몇 개를 주문하시겠습니까? (최대 10개)\n";
	private final static String countNumberUS = "How many Tickets do you want to order?\n";

	private final static String treatmentKR1 = "우대사항을 선택하세요.\n";
	private final static String treatmentKR2 = "1. 없음 (나이 우대는 자동처리)\n";
	private final static String treatmentKR3 = "2. 장애인\n";
	private final static String treatmentKR4 = "3. 국가유공자\n";
	private final static String treatmentKR5 = "4. 다자녀\n";
	private final static String treatmentKR6 = "5. 임산부\n";

	private final static String treatmentUS1 = "Choose your treatment\n";
	private final static String treatmentUS2 = "1. X (Age treatment is auto)\n";
	private final static String treatmentUS3 = "2. Disabled person\n";
	private final static String treatmentUS4 = "3. A man of national merit\n";
	private final static String treatmentUS5 = "4. Multi-Child\n";
	private final static String treatmentUS6 = "5. Pregnant\n";

	private final static String guideCommentKR1 = "\n계속 발권 하시겠습니까?\n";
	private final static String guideCommentKR2 = "1. 티켓 발권\n";
	private final static String guideCommentKR3 = "2. 종료\n";

	private final static String guideCommentUS1 = "\nDo you want to continue?\n";
	private final static String guideCommentUS2 = "1. Select Ticket\n";
	private final static String guideCommentUS3 = "2. End\n";

	public static final String calculDayNightTicketExceptionKR = "다시 선택하세요.";
	public static final String calculDayNightTicketExceptionUS = "Choose Again..";

	public static final String ticketTypeDayKR = "주간권";
	public static final String ticketTypeDayUS = "Day Ticket";

	public static final String ticketTypeNightKR = "야간권";
	public static final String ticketTypeNightUS = "Night Ticket";

	public static final String calculSocialNumberKR = "주민등록번호는 13자리입니다.";
	public static final String calculSocialNumberUS = "The resident registration number is 13 digits.";

	public static final String calculSocialNumberExceptionKR = "잘못된 나이입니다.";
	public static final String calculSocialNumberExceptionUS = "Wrong age";

	public static final String ageGroupKR1 = "노인";
	public static final String ageGroupKR2 = "성인";
	public static final String ageGroupKR3 = "청소년";
	public static final String ageGroupKR4 = "어린이";
	public static final String ageGroupKR5 = "유아";
	public static final String ageGroupKR6 = "error";

	public static final String ageGroupUS1 = "Old";
	public static final String ageGroupUS2 = "Adult";
	public static final String ageGroupUS3 = "Teen";
	public static final String ageGroupUS4 = "Kids";
	public static final String ageGroupUS5 = "Baby";
	public static final String ageGroupUS6 = "error";

	public static final String genderKR1 = "여성";
	public static final String genderKR2 = "남성";

	public static final String genderUS1 = "Woman";
	public static final String genderUS2 = "Man";

	public static final String countNumbersExceptionKR = "주문 가능 개수는 1인당 1개에서 최대 10개 입니다.";
	public static final String countNumbersExceptionUS = "The number of orders is 1 to 10 per person.";

	public static final String treatmentExceptionKR = "우대사항은 1번에서 5번 사이로 골라주세요.";
	public static final String treatmentExceptionUS = "Please choose between 1 and 5.";

	public static final String pregnantExceptionKR = "임산부 우대사항은 성인 여성에게만 적용됩니다.";
	public static final String pregnantExceptionUS = "Pregnant women's preferential treatment is only for adult women.";

	public static final String decideContinueException = "error";

	public static final String writeCsvIOExceptionKR1 = "우대적용 없음";
	public static final String writeCsvIOExceptionKR2 = "장애인 우대적용";
	public static final String writeCsvIOExceptionKR3 = "국가유공자 우대적용";
	public static final String writeCsvIOExceptionKR4 = "다자녀 우대적용";
	public static final String writeCsvIOExceptionKR5 = "임산부 우대적용";

	public static final String writeCsvIOExceptionUS1 = "No Discount";
	public static final String writeCsvIOExceptionUS2 = "Disabled Man Discount";
	public static final String writeCsvIOExceptionUS3 = "A man of national merit Discount";
	public static final String writeCsvIOExceptionUS4 = "Multi-Child Discount";
	public static final String writeCsvIOExceptionUS5 = "Pregnant Discount";

	public static final String printAgeKR = "나이 : %d살\n";
	public static final String printAgeUS = "Age : %d years old\n";

	public static final String printPriceKR = "가격은 %d원 입니다.\n";
	public static final String printPriceUS = "The Price is %dWon\n";

	public static final String printEndKR = "티켓발권을 종료합니다. 감사합니다.\n";
	public static final String printEndUS = "End ticket issuance. Thank you.\n";

	public static final String outputDiscountKR1 = "우대적용 없음";
	public static final String outputDiscountKR2 = "장애인 우대적용";
	public static final String outputDiscountKR3 = "국가유공자 우대적용";
	public static final String outputDiscountKR4 = "다자녀 우대적용";
	public static final String outputDiscountKR5 = "임산부 우대적용";
	public static final String outputDiscountKR6 = "\n입장료 총액은 %d원 입니다.\n";

	public static final String outputDiscountUS1 = "No Discount";
	public static final String outputDiscountUS2 = "Disabled Man Discount";
	public static final String outputDiscountUS3 = "A man of national merit Discount";
	public static final String outputDiscountUS4 = "Multi-Child Discount";
	public static final String outputDiscountUS5 = "Pregnant Discount";
	public static final String outputDiscountUS6 = "\nTotal Fee is %d Won.\n";

	private String LANGUAGE = ""; // kor : 0, eng : 1

	public String TICKET_TYPE_QUESTION;

	public void startLanguage() throws Exception {
		LotteCalcul lc = new LotteCalcul();
		LotteInput li = new LotteInput();
		WriteDB wd = new WriteDB();
		try {
			while (true) {
				lc.calculPrice();
				int continueBreak = li.guideComment();
				if (continueBreak == 1) {
					continue;
				} else if (continueBreak == 2) {
					lc.deliverData();
					lc.makeCsv(lc.data);
					wd.writeToDB(lc.data);
					break;
				}

			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static String getChoiceDayNightKR1() {
		return choiceDayNightKR1;
	}

	public static void setChoiceDayNightKR1(String choiceDayNightKR1) {
		LotteTicketPrice.choiceDayNightKR1 = choiceDayNightKR1;
	}

	public static String getChoiceDayNightKR2() {
		return choiceDayNightKR2;
	}

	public static void setChoiceDayNightKR2(String choiceDayNightKR2) {
		LotteTicketPrice.choiceDayNightKR2 = choiceDayNightKR2;
	}

	public static String getChoiceDayNightKR3() {
		return choiceDayNightKR3;
	}

	public static void setChoiceDayNightKR3(String choiceDayNightKR3) {
		LotteTicketPrice.choiceDayNightKR3 = choiceDayNightKR3;
	}

	public String getLANGUAGE() {
		return LANGUAGE;
	}

	public void setLANGUAGE(String lANGUAGE) {
		LANGUAGE = lANGUAGE;
	}

	public String getTICKET_TYPE_QUESTION() {
		return TICKET_TYPE_QUESTION;
	}

	public void setTICKET_TYPE_QUESTION(String tICKET_TYPE_QUESTION) {
		TICKET_TYPE_QUESTION = tICKET_TYPE_QUESTION;
	}

	public static int getDayold() {
		return DayOld;
	}

	public static int getDayadult() {
		return DayAdult;
	}

	public static int getDayteen() {
		return DayTeen;
	}

	public static int getDaykids() {
		return DayKids;
	}

	public static int getDaybaby() {
		return DayBaby;
	}

	public static int getNightold() {
		return NightOld;
	}

	public static int getNightadult() {
		return NightAdult;
	}

	public static int getNightteen() {
		return NightTeen;
	}

	public static int getNightkids() {
		return NightKids;
	}

	public static int getNightbaby() {
		return NightBaby;
	}

	public static String getKorean() {
		return KOREAN;
	}

	public static String getEnglish() {
		return ENGLISH;
	}

	public static String getLanguageKr() {
		return LANGUAGE_KR;
	}

	public static String getLanguageUs() {
		return LANGUAGE_US;
	}

	public static String getChoicedaynightus1() {
		return choiceDayNightUs1;
	}

	public static String getChoicedaynightus2() {
		return choiceDayNightUs2;
	}

	public static String getChoicedaynightus3() {
		return choiceDayNightUs3;
	}

	public static String getInputsocialnumberkr() {
		return inputSocialNumberKR;
	}

	public static String getInputsocialnumberus() {
		return inputSocialNumberUS;
	}

	public static String getCountnumberkr() {
		return countNumberKR;
	}

	public static String getCountnumberus() {
		return countNumberUS;
	}

	public static String getTreatmentkr1() {
		return treatmentKR1;
	}

	public static String getTreatmentkr2() {
		return treatmentKR2;
	}

	public static String getTreatmentkr3() {
		return treatmentKR3;
	}

	public static String getTreatmentkr4() {
		return treatmentKR4;
	}

	public static String getTreatmentkr5() {
		return treatmentKR5;
	}

	public static String getTreatmentkr6() {
		return treatmentKR6;
	}

	public static String getTreatmentus1() {
		return treatmentUS1;
	}

	public static String getTreatmentus2() {
		return treatmentUS2;
	}

	public static String getTreatmentus3() {
		return treatmentUS3;
	}

	public static String getTreatmentus4() {
		return treatmentUS4;
	}

	public static String getTreatmentus5() {
		return treatmentUS5;
	}

	public static String getTreatmentus6() {
		return treatmentUS6;
	}

	public static String getGuidecommentkr1() {
		return guideCommentKR1;
	}

	public static String getGuidecommentkr2() {
		return guideCommentKR2;
	}

	public static String getGuidecommentkr3() {
		return guideCommentKR3;
	}

	public static String getGuidecommentus1() {
		return guideCommentUS1;
	}

	public static String getGuidecommentus2() {
		return guideCommentUS2;
	}

	public static String getGuidecommentus3() {
		return guideCommentUS3;
	}

	public static String getCalculdaynightticketexceptionkr() {
		return calculDayNightTicketExceptionKR;
	}

	public static String getCalculdaynightticketexceptionus() {
		return calculDayNightTicketExceptionUS;
	}

	public static String getTickettypedaykr() {
		return ticketTypeDayKR;
	}

	public static String getTickettypedayus() {
		return ticketTypeDayUS;
	}

	public static String getTickettypenightkr() {
		return ticketTypeNightKR;
	}

	public static String getTickettypenightus() {
		return ticketTypeNightUS;
	}

	public static String getCalculsocialnumberkr() {
		return calculSocialNumberKR;
	}

	public static String getCalculsocialnumberus() {
		return calculSocialNumberUS;
	}

	public static String getCalculsocialnumberexceptionkr() {
		return calculSocialNumberExceptionKR;
	}

	public static String getCalculsocialnumberexceptionus() {
		return calculSocialNumberExceptionUS;
	}

	public static String getAgegroupkr1() {
		return ageGroupKR1;
	}

	public static String getAgegroupkr2() {
		return ageGroupKR2;
	}

	public static String getAgegroupkr3() {
		return ageGroupKR3;
	}

	public static String getAgegroupkr4() {
		return ageGroupKR4;
	}

	public static String getAgegroupkr5() {
		return ageGroupKR5;
	}

	public static String getAgegroupkr6() {
		return ageGroupKR6;
	}

	public static String getAgegroupus1() {
		return ageGroupUS1;
	}

	public static String getAgegroupus2() {
		return ageGroupUS2;
	}

	public static String getAgegroupus3() {
		return ageGroupUS3;
	}

	public static String getAgegroupus4() {
		return ageGroupUS4;
	}

	public static String getAgegroupus5() {
		return ageGroupUS5;
	}

	public static String getAgegroupus6() {
		return ageGroupUS6;
	}

	public static String getGenderkr1() {
		return genderKR1;
	}

	public static String getGenderkr2() {
		return genderKR2;
	}

	public static String getGenderus1() {
		return genderUS1;
	}

	public static String getGenderus2() {
		return genderUS2;
	}

	public static String getCountnumbersexceptionkr() {
		return countNumbersExceptionKR;
	}

	public static String getCountnumbersexceptionus() {
		return countNumbersExceptionUS;
	}

	public static String getTreatmentexceptionkr() {
		return treatmentExceptionKR;
	}

	public static String getTreatmentexceptionus() {
		return treatmentExceptionUS;
	}

	public static String getPregnantexceptionkr() {
		return pregnantExceptionKR;
	}

	public static String getPregnantexceptionus() {
		return pregnantExceptionUS;
	}

	public static String getDecidecontinueexception() {
		return decideContinueException;
	}

	public static String getWritecsvioexceptionkr1() {
		return writeCsvIOExceptionKR1;
	}

	public static String getWritecsvioexceptionkr2() {
		return writeCsvIOExceptionKR2;
	}

	public static String getWritecsvioexceptionkr3() {
		return writeCsvIOExceptionKR3;
	}

	public static String getWritecsvioexceptionkr4() {
		return writeCsvIOExceptionKR4;
	}

	public static String getWritecsvioexceptionkr5() {
		return writeCsvIOExceptionKR5;
	}

	public static String getWritecsvioexceptionus1() {
		return writeCsvIOExceptionUS1;
	}

	public static String getWritecsvioexceptionus2() {
		return writeCsvIOExceptionUS2;
	}

	public static String getWritecsvioexceptionus3() {
		return writeCsvIOExceptionUS3;
	}

	public static String getWritecsvioexceptionus4() {
		return writeCsvIOExceptionUS4;
	}

	public static String getWritecsvioexceptionus5() {
		return writeCsvIOExceptionUS5;
	}

	public static String getPrintagekr() {
		return printAgeKR;
	}

	public static String getPrintageus() {
		return printAgeUS;
	}

	public static String getPrintpricekr() {
		return printPriceKR;
	}

	public static String getPrintpriceus() {
		return printPriceUS;
	}

	public static String getPrintendkr() {
		return printEndKR;
	}

	public static String getPrintendus() {
		return printEndUS;
	}

	public static String getOutputdiscountkr1() {
		return outputDiscountKR1;
	}

	public static String getOutputdiscountkr2() {
		return outputDiscountKR2;
	}

	public static String getOutputdiscountkr3() {
		return outputDiscountKR3;
	}

	public static String getOutputdiscountkr4() {
		return outputDiscountKR4;
	}

	public static String getOutputdiscountkr5() {
		return outputDiscountKR5;
	}

	public static String getOutputdiscountkr6() {
		return outputDiscountKR6;
	}

	public static String getOutputdiscountus1() {
		return outputDiscountUS1;
	}

	public static String getOutputdiscountus2() {
		return outputDiscountUS2;
	}

	public static String getOutputdiscountus3() {
		return outputDiscountUS3;
	}

	public static String getOutputdiscountus4() {
		return outputDiscountUS4;
	}

	public static String getOutputdiscountus5() {
		return outputDiscountUS5;
	}

	public static String getOutputdiscountus6() {
		return outputDiscountUS6;
	}
}

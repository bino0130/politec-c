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
	
	private final static String choiceDayNightKR1 = "권종을 선택하세요.\n";
	private final static String choiceDayNightKR2 = "1. 주간권\n";
	private final static String choiceDayNightKR3 = "2. 야간권\n";
	
	private final static String choiceDayNightUs1 = "Choose Ticket Type.\n";
	private final static String choiceDayNightUs2 = "1. Day Type\\n";
	private final static String choiceDayNightUs3 = "2. Night Type\n";
	
	private final static String choiceDayNightES1 = "Elija la campana.\n";
	private final static String choiceDayNightES2 = "1. billete semanal\\n";
	private final static String choiceDayNightES3 = "2. billete de noche\n";
	
	private final static String inputSocialNumberKR = "주민등록번호를 입력하세요.\n";
	private final static String inputSocialNumberUS = "Input Your SocialNumber\n";
	private final static String inputSocialNumberES = "Introduzca su número de registro de residente.\n";
	
	private final static String countNumberKR = "몇 개를 주문하시겠습니까? (최대 10개)\n";
	private final static String countNumberUS = "How many Tickets do you want to order?\n";
	private final static String countNumberES = "¿Cuántos quieres pedir? (Hasta 10)\n";
	
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
	
	private final static String treatmentES1 = "Elija un trato preferencial.\n";
	private final static String treatmentES2 = "1. Ninguna (autoprocesamiento de bandas de edad)\n";
	private final static String treatmentES3 = "2. discapacitado\n";
	private final static String treatmentES4 = "3. persona de mérito nacional\n";
	private final static String treatmentES5 = "4. muchos hijos\n";
	private final static String treatmentES6 = "5. mujer embarazada\n";
	
	private final static String guideCommentKR1 = "\n계속 발권 하시겠습니까?\n";
	private final static String guideCommentKR2 = "1. 티켓 발권\n";
	private final static String guideCommentKR3 = "2. 종료\n";
	
	private final static String guideCommentUS1 = "\nDo you want to continue?\n";
	private final static String guideCommentUS2 = "1. Select Ticket\n";
	private final static String guideCommentUS3 = "2. End\n";
	
	private final static String guideCommentES1 = "\n¿Quiere seguir emitiendo billetes?\n";
	private final static String guideCommentES2 = "1. billete\n";
	private final static String guideCommentES3 = "2. terminación\n";
	
	public static final String KOREAN = "1";
	public static final String ENGLISH = "2";
	public static final String LANGUAGE_KR = "kr";
	public static final String LANGUAGE_US = "us";
	
	public static final String calculDayNightTicketExceptionKR = "다시 선택하세요.";
	public static final String calculDayNightTicketExceptionUS = "Choose Again..";
	public static final String calculDayNightTicketExceptionES = "Por favor, elija De nuevo.";
	
	public static final String ticketTypeDayKR = "주간권";
	public static final String ticketTypeDayUS = "Day Ticket";
	public static final String ticketTypeDayES = "billete semanal";
	
	public static final String ticekTypeNightKR = "야간권";
	public static final String ticekTypeNightUS = "Night Ticket";
	public static final String ticekTypeNightES = "billete de noche";
	
	public static final String calculSocialNumberKR = "주민등록번호는 13자리입니다.";
	public static final String calculSocialNumberUS = "The resident registration number is 13 digits.";
	public static final String calculSocialNumberES = "Su número de registro de residente es de 13 dígitos.";
	
	public static final String calculSocialNumberExceptionKR = "잘못된 나이입니다.";
	public static final String calculSocialNumberExceptionUS = "Wrong age";
	public static final String calculSocialNumberExceptionES = "Edad equivocada.";
	
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
	
	public static final String ageGroupES1 = "Anciano";
	public static final String ageGroupES2 = "Adulto";
	public static final String ageGroupES3 = "Adolescente";
	public static final String ageGroupES4 = "Niño";
	public static final String ageGroupES5 = "Infante";
	public static final String ageGroupES6 = "error";
	
	public static final String genderKR1 = "여성";
	public static final String genderKR2 = "남성";
	
	public static final String genderUS1 = "Woman";
	public static final String genderUS2 = "Man";
	
	public static final String genderES1 = "Mujer";
	public static final String genderES2 = "Masculino";
	
	public static final String countNumbersExceptionKR = "주문 가능 개수는 1인당 1개에서 최대 10개 입니다.\n";
	public static final String countNumbersExceptionUS = "The number of orders is 1 to 10 per person.\n";
	public static final String countNumbersExceptionES = "El número de pedidos disponibles es de 1 a 10 por persona.\n";
	
	public static final String treatmentExceptionKR = "우대사항은 1번에서 5번 사이로 골라주세요.";
	public static final String treatmentExceptionUS = "Please choose between 1 and 5.";
	public static final String treatmentExceptionES = "Por favor, elija entre los números 1 y 5.";
	
	public static final String pregnantExceptionKR = "임산부 우대사항은 성인 여성에게만 적용됩니다.";
	public static final String pregnantExceptionUS = "Pregnant women's preferential treatment is only for adult women.";
	public static final String pregnantExceptionES = "El trato preferencial para embarazadas solo se aplica a las mujeres adultas.";
	
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
	
	public static final String writeCsvIOExceptionES1 = "No hay trato preferencial";
	public static final String writeCsvIOExceptionES2 = "Aplicación preferencial para personas con discapacidad";
	public static final String writeCsvIOExceptionES3 = "Aplicación preferencial para personas de mérito nacional";
	public static final String writeCsvIOExceptionES4 = "Aplicación preferencial para los niños múltiples";
	public static final String writeCsvIOExceptionES5 = "Aplicación preferencial para mujeres embarazadas";
	
	

	private String LANGUAGE = ""; // kor : 0, eng : 1

	public String TICKET_TYPE_QUESTION;

	public void startLanguage(String country) throws Exception {
		LotteCalcul lc = new LotteCalcul();
		LotteInput li = new LotteInput();
		LANGUAGE = country;
		try {
			while(true) {
				if (LANGUAGE.equals("KR")) {
					setLANGUAGE("KR");
					lc.calculPrice(LANGUAGE);
					int continueBreak = li.guideComment(LANGUAGE);
					if (continueBreak == 1) {
						continue;
					} else if (continueBreak == 2) {
						lc.deliverData(LANGUAGE);
						lc.makeCsv(LANGUAGE, lc.data);
						break;
					}
					
				} else if (LANGUAGE.equals("US")) {
					setLANGUAGE("US");
					lc.calculPrice(LANGUAGE);
					int continueBreak = li.guideComment(LANGUAGE);
					if (continueBreak == 1) {
						continue;
					} else if (continueBreak == 2) {
						lc.deliverData(LANGUAGE);
						lc.makeCsv(LANGUAGE, lc.data);
						break;
					}
				} else if (LANGUAGE.equals("ES")) {
					setLANGUAGE("ES");
					lc.calculPrice(LANGUAGE);
					int continueBreak = li.guideComment(LANGUAGE);
					if (continueBreak == 1) {
						continue;
					} else if (continueBreak == 2) {
						lc.deliverData(LANGUAGE);
						lc.makeCsv(LANGUAGE, lc.data);
						break;
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String getLANGUAGE() {
		return LANGUAGE;
	}

	public void setLANGUAGE(String lANGUAGE) {
		LANGUAGE = lANGUAGE;
	}

	public int getDayOld() {
		return DayOld;
	}

	public int getDayAdult() {
		return DayAdult;
	}

	public int getDayTeen() {
		return DayTeen;
	}

	public int getDayKids() {
		return DayKids;
	}

	public int getDayBaby() {
		return DayBaby;
	}

	public int getNightOld() {
		return NightOld;
	}

	public int getNightAdult() {
		return NightAdult;
	}

	public int getNightTeen() {
		return NightTeen;
	}

	public int getNightKids() {
		return NightKids;
	}

	public int getNightBaby() {
		return NightBaby;
	}
}

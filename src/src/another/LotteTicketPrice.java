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
	
	String choiceDayNightKR1 = "권종을 선택하세요.\n";
	String choiceDayNightKR2 = "1. 주간권\n";
	String choiceDayNightKR3 = "2. 야간권\n";
	
	String choiceDayNightUs1 = "Choose Ticket Type.\n";
	String choiceDayNightUs2 = "1. Day Type\\n";
	String choiceDayNightUs3 = "2. Night Type\n";
	
	String choiceDayNightES1 = "Elija la campana.\n";
	String choiceDayNightES2 = "1. billete semanal\\n";
	String choiceDayNightES3 = "2. billete de noche\n";
	
	public static final String KOREAN = "1";
	public static final String ENGLISH = "2";
	public static final String LANGUAGE_KR = "kr";
	public static final String LANGUAGE_US = "us";

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

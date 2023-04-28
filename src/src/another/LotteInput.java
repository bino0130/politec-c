package another;

import java.util.Scanner;

public class LotteInput {
	Scanner sc = new Scanner(System.in);
//	int language = sc.nextInt();

	String choiceLanguage() {
		LotteTicketPrice ltp = new LotteTicketPrice();
		System.out.println("언어를 선택하세요.\n1. 한국어\n2. 영어");
		String language = sc.next();
		return LanguagePrintClass.inputLanguage(language);
	}

	String choiceDayNight() throws Exception {
		LotteCalcul lc = new LotteCalcul();

		System.out.println(LanguagePrintClass.getMsg("dayNightChoice"));

		int inputSelectTicket = sc.nextInt();

		return lc.calculDayNightTicket(inputSelectTicket);
	}

	String[] inputSocialNumber() throws Exception {
		LotteCalcul lc = new LotteCalcul();

//		System.out.printf(LotteTicketPrice.getInputsocialnumberus());
		System.out.println(LanguagePrintClass.getMsg("socialNumberInput"));

		String socialNumber = sc.nextLine(); // 123456-1234567에서 '-' 빼고 입력

		return lc.calculSocialNumber(socialNumber);
	}

	int countNumber() throws Exception {
		LotteCalcul lc = new LotteCalcul();

//		System.out.printf(LotteTicketPrice.getCountnumberus());
		System.out.println(LanguagePrintClass.getMsg("numberCount"));

		int numberOfOrders = sc.nextInt();

		return lc.calculCountNumbers(numberOfOrders);
	}

	double treatment() throws Exception {
		LotteCalcul lc = new LotteCalcul();
		int specificCase;

		System.out.println(LanguagePrintClass.getMsg("selectTreatment"));

		specificCase = sc.nextInt();

		return lc.calculTreatment(specificCase);
	}

	int guideComment() throws Exception {
		LotteCalcul lc = new LotteCalcul();
		int selectContinue;

		System.out.println(LanguagePrintClass.getMsg("commentGuide"));

		selectContinue = sc.nextInt();

		return lc.decideContinue(selectContinue);
	}

	void removeEnter() {
		sc.nextLine();
	}
}
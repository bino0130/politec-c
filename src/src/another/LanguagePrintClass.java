package another;

import java.util.Locale;
import java.util.ResourceBundle;

public class LanguagePrintClass {

	public static ResourceBundle messages;
	
	public static String inputLanguage(String LANGUAGE) { // 언어세팅 메서드
		 if (LANGUAGE.equals(LotteTicketPrice.KOREAN)) {
	            Locale.setDefault(Locale.KOREAN);
	        } else if (LANGUAGE.equals(LotteTicketPrice.ENGLISH)) {
	            Locale.setDefault(Locale.ENGLISH);
	        }
//		 System.out.println(Locale.getDefault().getLanguage());
	        messages = ResourceBundle.getBundle("message", Locale.getDefault());
		return null;
	}
	
	public static String getMsg(String key) {
		String message = null;
		try {
			message = messages.getString(key);
		} catch (Exception e) {
			new IllegalArgumentException("Could not find message for key [" + key + "]");
		}
		return message;
	}
	
	void kiosk() throws Exception {
		LotteInput li = new LotteInput();
		LotteTicketPrice ltp = new LotteTicketPrice();
		LotteCalcul lc = new LotteCalcul();
		
//		Locale currentLocale = Locale.getDefault(); // 운영체제 사용 언어 적용
//		System.out.println("locale : " + currentLocale.getCountry());
		ltp.startLanguage();
	}
}
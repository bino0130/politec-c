package another;

import java.util.Locale;
import java.util.ResourceBundle;

public class LanguagePrintClass {

	public static ResourceBundle messages;
	
	public static void choiceLanguage(String LANGUAGE) {
		if(LANGUAGE.equals(LotteTicketPrice.KOREAN)) {
			Locale.setDefault(Locale.KOREAN);
			messages = ResourceBundle.getBundle("message", new Locale(LotteTicketPrice.LANGUAGE_KR));
		} else if (LANGUAGE.equals(LotteTicketPrice.ENGLISH)) {
			Locale.setDefault(Locale.US);
			messages = ResourceBundle.getBundle("message", new Locale(LotteTicketPrice.LANGUAGE_US));
		}
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
}
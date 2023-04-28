package another;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.List;

public class WriteDB {

	private Connection con;
	
	public WriteDB() {
		try {
			String dbURL = "jdbc:mysql://localhost/test";
			String dbID = "root";
			String dbPassword =  "apfhd135";
			Class.forName("com.mysql.cj.jdbc.Driver");
			con = DriverManager.getConnection(dbURL, dbID, dbPassword);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void writeToDB(List<OrderList> data) {

		try {
			// 반복을 통해 리스트 값을 하나씩 꺼내서 문자열에 담는다.
			for (OrderList order : data) {
				double option = order.getOption();
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
		
				PreparedStatement pst = con.prepareStatement("INSERT INTO Station VALUES (?,?,?,?,?)");
				pst.setString(1, order.getTicketType());
				pst.setString(2, order.getAgeGroup());
				pst.setInt(3, order.getAmount());
				pst.setInt(4, order.getCost());
				pst.setString(5, discount);
				
				// 데이터 베이스 저장 명령어로 문자열 안에 저장된 sql언어를 날린
				pst.executeUpdate();
			}

		} catch (Exception e) {

		}
	}
}
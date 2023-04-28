package another;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.List;
import java.util.Scanner;

public class LotteOutput {
	LotteTicketPrice ltp = new LotteTicketPrice();

	static int printAge(int age) {
		System.out.printf(MessageFormat.format(LanguagePrintClass.getMsg("agePrint"), age));
		return 0;
	}

	static int printPrice(int finalPrice) {
		System.out.printf(MessageFormat.format(LanguagePrintClass.getMsg("pricePrint"), finalPrice));
		return finalPrice;
	}

	static int printEnd(int selectContinue) {
		if (selectContinue == 2) {
			System.out.printf(LanguagePrintClass.getMsg("endPrint"));
		}
		return selectContinue;
	}

	List<OrderList> output(List<OrderList> data, int totalCost) throws FileNotFoundException {
		System.out.println("\n======================롯데월드=======================");

		for (OrderList order : data) {
			String ticketType = order.getTicketType();
			String ageGroup = order.getAgeGroup();
			int amount = order.getAmount();
			double option = order.getOption();
			int cost = order.getCost();
			totalCost = order.getTotalCost();
			String discount = null;

			if (option == 1) {
				discount = LanguagePrintClass.getMsg("discountOutput1");
			} else if (option == 0.6) {
				discount = LanguagePrintClass.getMsg("discountOutput2");
			} else if (option == 0.5) {
				discount = LanguagePrintClass.getMsg("discountOutput3");
			} else if (option == 0.8) {
				discount = LanguagePrintClass.getMsg("discountOutput4");
			} else if (option == 0.85) {
				discount = LanguagePrintClass.getMsg("discountOutput5");
			}

			System.out.printf("%s %s X %d%s%d원%3s%s\n", ticketType, ageGroup, amount, " ", cost, " ", discount);
		}

		System.out.printf(MessageFormat.format(LanguagePrintClass.getMsg("discountOutput6"), totalCost));
		System.out.println("===================================================");

		return null;
	}

	void readCsv(String filePath) throws IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("csv의 파일의 어떤 항목을 읽고 싶으신가요?");
		System.out.println("1. 전체 2. 티켓타입 3. 연령대 4. 총 가격 5. 우대사항");
		int selectCsv = sc.nextInt();
		if (selectCsv == 1) {
			readAllCsv(filePath);
		} else if (selectCsv == 2) {
			readTicketType(filePath);
		} else if (selectCsv == 3) {
			readAgeGroup(filePath);
		} else if (selectCsv == 4) {
			readCost(filePath);
		} else if (selectCsv == 5) {
			readDiscount(filePath);
		}
	}

	void readAllCsv(String filePath) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		String line = "";

		if ((line = reader.readLine()) == null) {
			System.out.println("빈 파일입니다.");
		}
		System.out.println("======================report.csv======================");
		while ((line = reader.readLine()) != null) {
			String[] rowData = line.split(",");
			System.out.println("Ticket type: " + rowData[0] + ", Age group: " + rowData[1] + ", Amount: " + rowData[2]
					+ ", Cost: " + rowData[3] + ", Discount: " + rowData[4]);
		}
	}

	void readTicketType(String filePath) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		String line = "";

		if ((line = reader.readLine()) == null) {
			System.out.println("빈 파일입니다.");
		}
		System.out.println("======================Tickettype======================");
		while ((line = reader.readLine()) != null) {
			String[] rowData = line.split(",");
			System.out.println("Age group: " + rowData[1]);
		}
	}

	void readAgeGroup(String filePath) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		String line = "";

		if ((line = reader.readLine()) == null) {
			System.out.println("빈 파일입니다.");
		}
		System.out.println("======================AgeGroup======================");
		while ((line = reader.readLine()) != null) {
			String[] rowData = line.split(",");
			System.out.println("Amount: " + rowData[2]);
		}
	}

	void readCost(String filePath) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		String line = "";

		if ((line = reader.readLine()) == null) {
			System.out.println("빈 파일입니다.");
		}
		System.out.println("======================Cost======================");
		while ((line = reader.readLine()) != null) {
			String[] rowData = line.split(",");
			System.out.println("Cost: " + rowData[3]);
		}
	}

	void readDiscount(String filePath) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		String line = "";

		if ((line = reader.readLine()) == null) {
			System.out.println("빈 파일입니다.");
		}
		System.out.println("======================Discount======================");
		while ((line = reader.readLine()) != null) {
			String[] rowData = line.split(",");
			System.out.println("Discount: " + rowData[4]);
		}
	}
}

import java.io.*;

public class Assignment22 {

	public static void main(String[] args) {
		String str, k;
		Llist outnum;
		
		try {
			File file = new File("input.txt");
			FileReader flre = new FileReader(file);
			BufferedReader brd = new BufferedReader(flre);
			
			str = brd.readLine();
			Llist num1 = new Llist(str);
			str = brd.readLine();
			Llist num2 = new Llist(str);
			
			outnum = num1.sub(num2);
			
			brd.close();
			File file_2 = new File("output.txt");
			FileWriter flwr = new FileWriter(file_2);
			BufferedWriter bwr = new BufferedWriter(flwr);
			
			k = outnum.dtoS();
			bwr.write(k);
			bwr.close();
			
		}
		
		catch (Exception e) {
			System.out.println("error");
		}
	}
	
}

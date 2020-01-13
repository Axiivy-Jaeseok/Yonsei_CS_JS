import java.io.*;

public class Assignment11 {
	public static void main(String[] args) {
		
		try {
			File file = new File("input.txt");
			FileReader flre = new FileReader(file);
			BufferedReader bfre = new BufferedReader(flre);
			
			File file_2 = new File("output.txt");
			FileWriter flwr = new FileWriter(file_2);
			BufferedWriter bfwr = new BufferedWriter(flwr);
			
			String line = bfre.readLine();
			
			int num = Integer.parseInt(line);
			int i = 0, min_value, index;
						
			
			String[] buylist = new String[num];
			
			while((line = bfre.readLine()) != null) {
				buylist[i] = line;
				i++;
			}
			bfre.close();
			
			int[] price = new int[num];
			String[] name = new String[num];
			
			for(int j=0;j<num;j++) {
				String[] splstr = buylist[j].split(" ", 2);
				price[j] = Integer.parseInt(splstr[0]);
				name[j] = splstr[1];
			}
			
			min_value = Integer.MAX_VALUE;
			index = 0;
			
			for(int m=0;m<num;m++) {
				if(price[m]<min_value) {
					min_value = price[m];
					index = m;
				}
			}
			
			bfwr.write(name[index]);
			bfwr.close();
			
		}
		
		catch(Exception e) {
			System.out.println("error");
		}
		
	}
}

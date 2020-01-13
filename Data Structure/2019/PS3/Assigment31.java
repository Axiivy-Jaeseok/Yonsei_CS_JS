import java.io.*;

class Assigment31 {
		
	public static void main(String[] args) {
		
        try {
        	String s, exec, content;
            int x, top = 0;
            BufferedReader rd = new BufferedReader(new FileReader("input.txt"));
            BufferedWriter wr = new BufferedWriter(new FileWriter("output.txt"));
                        
            s = rd.readLine();
            x = Integer.parseInt(s);
            
            String stack[] = new String[x];
                        
            for(int i=0; i<x; i++) {
            	s = rd.readLine();
            	exec = s.split(" ", 2)[0];
            	            	            	
            	if(exec.equals("u")) {
            		content = s.split(" ", 2)[1];
            		stack[top++] = content;
            		
            	}else if(exec.equals("o")) {
            		if(stack[0] == null) {
            			wr.write("empty\n");
            		}else {
            			wr.write(stack[--top] + "\n");
            			stack[top] = null;
            		}
            		
            	}else if(exec.equals("e")) {
            		if(stack[0] == null) {
            			wr.write("empty\n");
            		}else {
            			wr.write(stack[top-1] + "\n");
            		}
            	}
            }
            
            rd.close();
            wr.close();
        }
        
        catch (Exception e) {
            System.out.println("ERROR");
        }
        
	}
}
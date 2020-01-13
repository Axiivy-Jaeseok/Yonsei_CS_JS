
public class Llist {
	private Node first;
	
	public Llist(String s){
		int i, digit;
		Node last, newnode;

		last = null;
		
		i = s.length()-1;
		
		while(i >= 0) {
			digit = (int)(s.charAt(i));
			
			newnode = new Node();
			newnode.num = digit - (int)'0';
				
			if(last == null) first = newnode;
			else last.next = newnode;
				
			last = newnode;
			i--;
			
		}
	}
	
	private Llist(Node n) {
		first = n;
	}
	
	public String dtoS() {
		int len=0;
		Node n;
		
		for(n=first; n.next!=null; n=n.next) len++;
		
		len += 1;
				
		if(n.num < 0) {
			for(n=first;n!=null;n=n.next) {
				if(n.next == null) n.num = -(n.num+1);
				else if(n == first) n.num = 10 - n.num;
				else n.num = 9 - n.num;	
			}
		}
		
		char[] str = new char[len];
		for(n=first;n!=null;n=n.next) str[--len] = (char)((int)'0' + n.num);
		
		String s = new String(str);
		int num = Integer.parseInt(s);
		s = Integer.toString(num);
		
		return s;
	}
	
	public Llist sub(Llist op) {
		Node out, nr, n1, n2;
		int carry, temp;
		int n1_len=0, n2_len=0;
		
		nr = out = new Node();
		carry = 0;
		
		for(n1=first; n1.next!=null; n1=n1.next) n1_len++;
		for(n2=op.first; n2.next!=null; n2=n2.next) n2_len++;
		
		n1_len++; n2_len++;
		
		if(n2_len > n1_len) {
			n1 = first;
			n2 = op.first;
		
			while((n1 != null) || (n2 != null) || (carry !=0)) {
				temp = carry;
			
				if(n2 != null) {
					temp += n2.num;
					n2 = n2.next;
				}
			
				if(n1 != null) {
					temp -= n1.num;
					n1 = n1.next;
				}
			
				nr.next = new Node();
				nr = nr.next;
			
				if(temp < 0) {
					if(n2 != null) {
						nr.num = 10+temp;					
						n2.num -= 1;
					}
				
					else {
						nr.num = temp;
					}
				}
				else{
					nr.num = temp;
				}
			}
		}
		
		else {
			
			n1 = first;
			n2 = op.first;
		
			while((n1 != null) || (n2 != null) || (carry !=0)) {
				temp = carry;
			
				if(n1 != null) {
					temp += n1.num;
					n1 = n1.next;
				}
			
				if(n2 != null) {
					temp -= n2.num;
					n2 = n2.next;
				}
			
				nr.next = new Node();
				nr = nr.next;
			
				if(temp < 0) {
					if(n1 != null) {
						nr.num = 10+temp;					
						n1.num -= 1;
					}
				
					else {
						nr.num = temp;
					}
				}
				else{
					nr.num = temp;
				}
			}
		}
		
		nr.next = null;
		
		
		return new Llist(out.next);
	}
}

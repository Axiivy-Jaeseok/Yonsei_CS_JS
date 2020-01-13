
class CDIter {
	public CDNode cur;
	public CDList cdll;
	
	public boolean isValid() {
		if(cur != null) return true;
		else return false;
	}
	
	public int getValue() {
		if(!isValid()) return -1;
		
		else {
			return cur.data;
		}
	}
	
	public boolean setValue(int x) {
		if(!isValid()) return false;
		
		else {
			cur.data = x;
			return true;
		}
	}
	
	public int delete() {
		
		if(isValid()) {
			int ret = cur.data;
			
			if(cdll.first.next != cdll.first) {
				if(cur == cdll.first) cdll.first = cur.next;
				
				cur.prev.next = cur.next;
				cur.next.prev = cur.prev;
				next();
			}
			
			else {
				cur = null;
				cdll.first = null;
			}
			
			return ret;
		}
		
		else return -1;
	}
	
	public boolean insertBefore(int x) {
		if(!isValid()) return false;
		
		else {
			CDNode newnode = new CDNode();
			
			newnode.data = x;
			newnode.prev = cur.prev;
			newnode.next = cur;
			cur.prev = newnode;
			cur.prev.next = newnode;
			
			if(cur == cdll.first) {
				cdll.first = newnode;
			}
			
			return true;
		}
	}
	
	public boolean insertAfter(int x) {
		if(!isValid()) return false;
		
		else {
			CDNode newnode = new CDNode();
			
			newnode.data = x;
			newnode.next = cur.next;
			newnode.prev = cur;
			cur.next = newnode;
			cur.next.prev = newnode;
			
			return true;
		}
	}
	
	public void prev() {
		if(!isValid()) return;
		
		else {
			cur = cur.prev;
		}
	}
	
	public void next() {
		if(!isValid()) return;
		
		else {
			cur = cur.next;
		}
	}
	
}

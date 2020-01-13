class LinkedList {
	public Node first, last;
	
	public LinkedList() {
		first = null;
		last = null;
	}
	
	public boolean isEmpty() {
		return (first == null);
	}
	
	public void InsertAtEnd(int x) {
		Node newnode;
		
		newnode = new Node();
		newnode.data = x;
		newnode.next = null;
		
		if(last == null) {
			first = last = newnode;
		}else {
			last.next = newnode;
			last = newnode;
		}
	}
	
	public void InsertAtFront(int x) {
		Node newnode;
		
		newnode = new Node();
		newnode.data = x;
		newnode.next = first;
		
		if(last == null) {
			last = newnode;
		}
	}
	
	public int DeleteFirst() {
		int ret;
		
		if(first == null) return -1;
		ret = first.data;
		first = first.next;
		if(first == null) last = null;
		
		return ret;
	}
	
}
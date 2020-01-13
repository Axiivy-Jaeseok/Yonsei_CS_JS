
class CDList {
	public CDNode first;
	
	public CDList() {
		first = null;
	}
	
	public void append(int x) {
		if(first == null) {
			CDNode newnode = new CDNode();
			first = newnode;
			newnode.data = x;
			newnode.prev = newnode;
			newnode.next = newnode;
		}
		
		else {
			CDNode newnode = new CDNode();
			newnode.data = x;
			newnode.next = first;
			newnode.prev = first.prev;
			first.prev.next = newnode;
			first.prev = newnode;
		}
	}
	
	public CDIter getIter() {
		CDIter newiter = new CDIter();
		newiter.cdll = this;
		newiter.cur = first;
		
		return newiter;
	}
}

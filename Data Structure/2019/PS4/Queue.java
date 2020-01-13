class Queue {
	private final LinkedList llist;
	
	public Queue() {
		llist = new LinkedList();
	}
	
	public void enqueue(int x) {
		llist.InsertAtEnd(x);
	}
	
	public int dequeue() {
		return llist.DeleteFirst();
	}
	
	public boolean isEmpty() {
		return llist.isEmpty();
	}
}

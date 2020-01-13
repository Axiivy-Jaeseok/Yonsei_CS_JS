
public class FibHeap {
	public int n;
	public Node minroot;
	
	// Constructs an empty Fibonacci heap
	public FibHeap() {
		n = 0;
		minroot = null;
	}
	
	// Constructs a Fibonacci heap by uniting h1 and h2
	public FibHeap(FibHeap h1, FibHeap h2) {
		
		// Check one of them is null
		if(h1.minroot == null || h2.minroot == null) {
			
			// h1 is not null
			if(h1.minroot != null) {
				minroot = h1.minroot;
				n = h1.n;
			// h2 is not null
			}else if(h2.minroot != null) {
				minroot = h2.minroot;
				n = h2.n;
			// both h1 and h2 are null
			}else {
				minroot = null;
				n = 0;
			}
			
		// both h1 and h2 are not null
		}else {
			
			n = h1.n + h2.n;
			Node temp = new Node();
			// listing by circular doubly linked list
			h1.minroot.prev.next = h2.minroot;
			h2.minroot.prev.next = h1.minroot;
			temp = h2.minroot.prev;
			h2.minroot.prev = h1.minroot.prev;
			h1.minroot.prev = temp;
			
			// Compare minroot of each Fibonacci heaps and set the minroot 
			if(h1.minroot.key < h2.minroot.key) minroot = h1.minroot;
			else minroot = h2.minroot;
			
		}
	}
	
	public Node insert(int key, String data) {
		
		// Creating newnode
		Node newnode = new Node();
		newnode.key = key;
		newnode.data = data;
		newnode.deg = 0;
		newnode.marked = false;
		newnode.parent = null;
		newnode.child = null;
		
		// When fibheap is an empty heap
		if(minroot == null) {
			minroot = newnode;
			newnode.next = newnode;
			newnode.prev = newnode;
			n++;
		// Not an empty heap
		}else {
			minroot.prev.next = newnode;
			newnode.next = minroot;
			newnode.prev = minroot.prev;
			minroot.prev = newnode;
			
			// Compare the key value of newnode and minroot
			if(newnode.key < minroot.key) {
				minroot = newnode;
			}
			
			// Increase the number of node
			n++;
		}
		
		return newnode;
	}

	
	public Node queryMin() {
		return minroot;
	}
	
	public boolean deleteMin() {
		
		if(minroot != null) {
			Node temp = minroot;
			Node iter = new Node();
			Node children = new Node();
			
			if(minroot.child != null) {
				children = temp.child;
				do {
					iter = children.next;
					minroot.prev.next = children;
					children.next = minroot;
					children.prev = minroot.prev;
					minroot.prev = children;
					
					if(children.key < minroot.key) minroot = children;
					
					children.parent = null;
					children = iter;
				}while(iter != temp.child);
				
			}
			
			temp.prev.next = temp.next;
			temp.next.prev = temp.prev;
			minroot = temp.next;
			
			if(temp == temp.next && temp.child == null) minroot = null;
			else {
				minroot = temp.next;
				
				minroot = findMinRoot();				
				consolidate();
			}
			n--;
			return true;
		}
		
		return false;
	}
	

	public void decreaseKey(Node target, int newkey) {
		if(minroot != null && target != null) {
			target.key = newkey;
			
			Node parent = target.parent;
			if(parent != null && target.key < parent.key) {
				cut(target, parent);
				caseCut(parent);
			}
			
			if(target.key < minroot.key) minroot = target;
		}
	
	}
	
	public void delete(Node target) {
		
		if(minroot != null && target != null) {
			decreaseKey(target, Integer.MIN_VALUE);
			deleteMin();
		}
		
	}

	private void consolidate() {
		int temp;
		int maxDegree = (int)Math.floor(Math.log((double)n) / Math.log(1.618));
		
		Node arr[] = new Node[maxDegree];
				
		for(int i=0; i< maxDegree; i++) {
			arr[i] = null;
		}
		
		Node ptr1 = minroot;
		Node ptr2, ptr3, ptr4;
		
		ptr4 = ptr1;
		
		do {
			ptr4 = ptr4.next;
			temp = ptr1.deg;
			
			while(arr[temp] != null) {
				
				ptr2 = arr[temp];
				if(ptr1.key > ptr2.key) {
					ptr3 = ptr1;
					ptr1 = ptr2;
					ptr2 = ptr3;
				}
				if (ptr2 == minroot) minroot = ptr1;
				
				
				ptr2.prev.next = ptr2.next;
				ptr2.next.prev = ptr2.prev;
				if(ptr1.next == ptr1) minroot = ptr1;
				ptr2.prev = ptr2;
				ptr2.next = ptr2;
				ptr2.parent = ptr1;
				if(ptr1.child == null) ptr1.child = ptr2;
				
				ptr2.next = ptr1.child;
				ptr2.prev = ptr1.child.prev;
				ptr1.child.prev.next = ptr2;
				ptr1.child.prev = ptr2;
				
				ptr1.deg++;
				
				if(ptr1.next == ptr1) minroot = ptr1;
				arr[temp] = null;
				temp++;
			}
						
			arr[temp] = ptr1;
			ptr1 = ptr1.next;
		}while(ptr4 != minroot);
		
	}
	
	private Node findMinRoot() {
		Node cur = minroot.next;
		Node min = minroot;
		do {
			if(cur.key < min.key) min = cur;
			cur= cur.next;
		}while(cur != minroot);
		
		return min;
	}
	
	private void cut(Node target, Node parent) {
		if(target == target.next) parent.child = null;
		
		target.prev.next = target.next;
		target.next.prev = target.prev;
		
		if(target == parent.child) parent.child = target.next;
		
		parent.deg = parent.deg-1;
		target.next = target;
		target.prev = target;
		minroot.prev.next = target;
		target.next = minroot;
		target.prev = minroot.prev;
		minroot.prev = target;
		target.parent = null;
		target.marked = true;
	}
	
	private void caseCut(Node parent) {
		Node gparent = parent.parent;
		if(gparent != null) {
			if(parent.marked == false) parent.marked = true;
			else {
				cut(parent, gparent);
				caseCut(gparent);
			}
		}
	}
	
	
	public void printRoots() {
		Node cur = minroot;
		do {
			System.out.print(cur.key + "(" + cur.deg + "), ");
			if (cur.deg > 0) {
				System.out.print("[" + cur.child.key + "]");
			}
			cur = cur.next;
		}while(cur != minroot);
		System.out.println();
	}
}

class BSTSplit {
	public BST bstSmaller, bstGreater;
	
	public BSTSplit() {
		// bstSmaller와 bstGreater null로 초기화
		bstSmaller = null;
		bstGreater = null;
	}
	
	public void split(BST bstIn, int val) {
		  BSTNode cur = bstIn.root; // 시작 노드 설정
		  BSTNode cannS, cannG;
		  
		  // 객체 생성
		  bstSmaller = new BST();
		  bstGreater = new BST();
		  
		  // lastS와 lastG를 null로 초기화
		  cannS = cannG = null;
		  
		  // split 과정
		  while(cur != null) {
			  // 입력된 값이 현재 key보다 클 때
			  if(val > cur.key) {
				  if(cannS == null) bstSmaller.root = cur;
				  else cannS.right = cur;
				  
				  cannS = cur;
				  cur = cur.right;
			  }
			  
			  // 입력된 값이 현재 key보다 작을 때
			  else if(val < cur.key) {
				  if(cannG == null) bstGreater.root = cur;
				  else cannG.left = cur;
				  
				  cannG = cur;
				  cur = cur.left;
			  }
			  
			  // 입력된 값이 현재 key와 같을 때
			  else {
				  if(cannS == null) bstSmaller.root = cur.left;
				  else cannS.right = cur.left;
				  
				  if(cannG == null) bstGreater.root = cur.right;
				  else cannG.left = cur.right;
				  
				  return;
			  }
		  }
		  
		  // 둘 중 하나의 트리가 null일 경우 empty tree로
		  // 양 끝 노드 cutting
		  if(cannS == null) bstSmaller.root = null;
		  else cannS.right = null;
		  
		  if(cannG == null) bstGreater.root = null;
		  else cannG.left =  null;
	}
}

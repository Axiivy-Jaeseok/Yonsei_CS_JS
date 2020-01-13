public class BST {
	public BSTNode root;
	public BST() {
		root = null;
	}
	
	public void insert(int key) {
		BSTNode cur = root; // 탐색 노드
		BSTNode newnode = new BSTNode(); // 삽입 노드
			
		newnode.key = key; // 삽입 노드에 key 값 추가
		
		// 트리가 없을 경우 삽입 노드를 root로 하는 트리 생성
		if(root == null) root = newnode;
		
		// 트리가 존재할 경우
		else {
			// 동일한 key값 찾기 & 삽입 노드 찾기
			while(true) {
				// key가 현재 key보다 작을 때
				if(key < cur.key) {
					// 왼쪽 노드가 더 이상 없을 때
					if(cur.left == null) {
						cur.left = newnode;
						return;
					}
					cur = cur.left; // 더 있을 경우 왼쪽으로 이동
				}
				
				// key가 현재 key와 같을 때	
				else if(key == cur.key){
					return; // 아무것도 하지 않음
				}
				
				// key가 현재 key보다 클 때
				else {
					// 오른쪽 노드가 더 이상 없을 때
					if(cur.right == null) {
						cur.right = newnode;
						return;
					}
					cur = cur.right; // 더 있을 경우 오른쪽으로 이동
				}
			}
		}
	}
	
	public boolean search(int key) {
		BSTNode cur = root; // 탐색 노드
		
		if(root == null) return false; // 트리가 존재X
		
		// 탐색 과정
		while(true) {
			// key가 현재 key보다 작을 때
			if(key < cur.key) {
				// 왼쪽 노드가 존재하지 않으면 거짓 반환
				if(cur.left == null) return false;
				cur = cur.left; // 왼쪽으로 이동
			}
			
			// key값을 찾았을 경우
			else if(key == cur.key) {
				return true;
				
			}
			
			// key가 현재 key보다 클 때
			else {
				// 오른쪽 노드가 존재하지 않으면 거짓 반환
				if(cur.right == null) return false;
				cur = cur.right; // 오른쪽으로 이동
			}	
		}
	}
	
	public boolean delete(int key) {
		BSTNode cur = root; // 삭제 노드
		BSTNode prev = null; // 삭제 노드의 부모노드
		BSTNode cann = null; // 대체 노드 
		BSTNode capn = null; // 대체 노드의 부모노드
		
		if(root == null) return false; // 트리가 존재X
		
		// 삭제 key 찾는과정
		while(true) {
			if(key == cur.key) break; // key 찾았을 경우
			
			// key가 현재 노드 key보다 작을때
			else if(key<cur.key){
				prev = cur;
				cur = cur.left; // 왼쪽 노드로 이동
				if(cur == null) return false; // 찾는 값X
			}
			
			// key가 현재 노드 key보다 클 때
			else {
				prev = cur;
				cur = cur.right; // 오른쪽 노드로 이동
				if(cur == null) return false; // 찾는 값X
			}
		}
		
		// case 1 : 삭제 노드의 오른쪽 자식X
		if(cur.right == null) {
			// 삭제 노드가 root 노드일 경우
			if(prev == null) root = cur.left;
			else {
				// 삭제노드가 부모노드의 왼쪽 자식이었을 경우
				if(prev.left == cur) prev.left = cur.left;
				// 삭제노드가 부모노드의 오른쪽 자식이었을 경우
				else prev.right = cur.left;
			}
		}
		
		// case 2 : 삭제 노드의 오른쪽 자식의 왼쪽 자식 X
		else if(cur.right.left == null) {
			// 삭제 노드가 root 노드일 경우
			if(prev == null) {
				// root 노드를 삭제 노드의 오른쪽 노드로 교체
				root = cur.right;
				// 새 root 노드의 왼쪽 노드를 삭제 노드의 왼쪽 노드로 연결
				cur.right.left = cur.left;
			}
			else {
				// 삭제 노드의 오른쪽 노드의 왼쪽을 삭제노드의 왼쪽 노드와 연결
				cur.right.left = cur.left;
				// 삭제노드가 부모노드의 왼쪽 자식이었을 경우
				if(prev.left == cur) prev.left = cur.right;
				// 삭제노드가 부모노드의 오른쪽 자식이었을 경우
				else prev.right = cur.right;
			}
		}
		
		// case 3 : 나머지 경우
		else {
			capn = cur;
			cann = cur.right;
			
			// 삭제 노드의 오른쪽 노드의 왼쪽 노드에서 최소값 찾기 
			while(!(cann.left == null)) {
				capn = cann;
				cann = cann.left;
			}
			
			// 대체 노드의 부모노드의 왼쪽노드를 대체노드의 오른쪽 자식에 연결
			capn.left = cann.right;
			// 대체 노드의 왼쪽 노드를 삭제 노드의 왼쪽 노드에 연결
			cann.left = cur.left;
			// 대체 노드의 오른쪽 노드를 삭제 노드의 오른쪽 노드에 연결
			cann.right = cur.right;
			
			// 삭제 노드가 root 노드일 경우
			if(prev == null) root = cann;
			else {
				// 삭제노드가 부모노드의 왼쪽 자식이었을 경우
				if(prev.left == cur) prev.left = cann;
				// 삭제노드가 부모노드의 오른쪽 자식이었을 경우
				else prev.right = cann;
			}
		}
		
		return true;
	}
}
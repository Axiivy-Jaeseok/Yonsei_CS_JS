class SP {

	// define this method
    public static int findSP(int n, int m, int[] x, int[] y, int u, int v, int[] ans) {
    	// 큐 제작
    	Queue queue = new Queue();
    	// 인접 리스트 선언
    	LinkedList[] adjlist = new LinkedList[n];
    	// 방문했는지 확인하는 배열 제작
    	//boolean[] visit = new boolean[n];
    	int[] visit = new int[n];
    	int[] road = new int[n];
    	int cur = 0;
    	
    	
    	// 초기에는 아무곳도 방문하지 않았으므로 false으로 초기화
    	for(int j=0;j<n;j++) {
    		visit[j] = -1;
    		road[j] = -1;
    	}
    	
    	// 인접 리스트 초기화
    	for(int i=0;i<n;i++) adjlist[i] = new LinkedList();
    	
    	// 인접 리스트 제작
    	for(int i=0;i<m;i++) {
    		adjlist[x[i]].InsertAtEnd(y[i]);
    		adjlist[y[i]].InsertAtEnd(x[i]);
    	}
    	
    	// 시작점 방문
    	visit[u] = 0;
    	road[u] = -10;
    	// 시작점 큐에 추가
    	queue.enqueue(u);
    	
    	
    	// queue가 비어 있을때까지 반복
    	while(!queue.isEmpty()) {
    		
    		// 큐에서 값 꺼내기
    		cur = queue.dequeue();
    		
    		// dequeue된 값이 목적지 v이면 break
    		if(cur == v) break;

    		// 인접 리스트 탐색
    		for(Node a = adjlist[cur].first; a != null; a = a.next) {
    			// 방문했는지 확인
    			if(visit[a.data] == -1) {
    				visit[a.data] = visit[cur] + 1;
    				road[a.data] = cur;
    				
    				// 큐에 넣기
    				queue.enqueue(a.data);
    			}
    		}
    	}
    	    	
    	if(cur == v) {
    		
        	ans[visit[v]] = v;
        	int p = visit[v]-1;
        	int e = v;
        	while(p>=0) {
        		ans[p] = road[e];
        		e = road[e];
        		p--;
        	}
        	
        	return visit[v]+1;
    	}
    	
    	return -1;
    }
        
}

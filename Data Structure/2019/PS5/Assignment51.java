import java.io.*;

class Assignment51 {

	static int count = 0, dfn_count = 0;
	static int[] dfn, low;
	static LinkedList[] adjlist;
	
	public static void main(String[] args) {
		// Graph의 Vertex와 Edge를 저장할 변수
		int n, m, pos;
		int[] x, y;
		String s;
		
		try {
			
			// File I/O
			BufferedReader rd = new BufferedReader(new FileReader("input.txt"));
	        BufferedWriter wr = new BufferedWriter(new FileWriter("output.txt"));
			
	        // input.txt에서 첫번째 줄 읽기
	        s = rd.readLine();
			pos = s.indexOf(" ");
			n = Integer.parseInt(s.substring(0, pos));
			m = Integer.parseInt(s.substring(pos + 1));
			
			x = new int[m];
			y = new int[m];
			
			// dfn 배열과 low 배열 선언
			dfn = new int[n];
			low = new int[n];
			
			// dfn과 low 배열 0으로 초기화
			for(int i=0;i<n;i++) dfn[i] = 0;
			for(int i=0;i<n;i++) low[i] = 0;
			
			// 인접리스트 제작을 위한 input.txt 파일 읽기
			for (int i = 0; i < m; i++) {
				s = rd.readLine();
				pos = s.indexOf(" ");
				x[i] = Integer.parseInt(s.substring(0, pos));
				y[i] = Integer.parseInt(s.substring(pos + 1));
			}
			
			rd.close();
			
			// 인접 리스트 제작
			adjlist = new LinkedList[n];
			
			// 인접 리스트 초기화
			for(int i=0;i<n;i++) adjlist[i] = new LinkedList();
			
			// 인접 리스트 제작
	    	for(int i=0;i<m;i++) {
	    		adjlist[x[i]].InsertAtEnd(y[i]);
	    		adjlist[y[i]].InsertAtEnd(x[i]);
	    	}
	    	
	    	// 이중연결요소를 찾기 위한 함수 호출
	    	findBC(0, -1);
	    	
	    	// output 파일에 결과 쓰기
	    	wr.write(Integer.toString(count));
	    	wr.close();
			
		} catch(Exception e) {
			e.printStackTrace();
			System.out.println("Error");
		}
	}
	
	public static void findBC(int v, int parent) {
		dfn[v] = ++dfn_count;
		low[v] = dfn[v];
		
		for(Node a = adjlist[v].first; a != null; a = a.next) {
			// 이웃이 부모이거나 이미 방문했으면 continue
			if(a.data==parent || dfn[v] < dfn[a.data]) continue;
			
			// back edge일때
			if(dfn[a.data] != 0) {
				if(dfn[a.data] <= low[v]) low[v] = dfn[a.data];
			}
			
			// 방문된 적이 없다면
			else {
				findBC(a.data, v);
				if(low[a.data]<= low[v]) low[v] = low[a.data];
				if(low[a.data]>=dfn[v]) {
					count++;
				}
			}
		}
		
		
	}
	

}

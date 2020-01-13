class Assignment12 {
	public static void main(String[] args) {
		
		Oracle o = new Oracle();
		
		int n, tofind;
		
		n = o.getN();
		tofind = o.getWhatToFind();
		
		int left = 0, right = n-1;
		
		while (left < right) {
			int mid = (left + right) / 2;
			if (o.getElementAt(mid) < tofind)
				left = mid + 1; 
			else	right = mid;
		}
		
		if (left == right && (o.getElementAt(left) == tofind))
			o.reportAnswer(true, left);
		else o.reportAnswer(false, 0);
	}
}
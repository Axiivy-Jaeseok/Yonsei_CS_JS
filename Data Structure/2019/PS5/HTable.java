class HTable {
	public HEntry[] table;
	public HTable() {
		table = new HEntry[262139];
		
		for(int i=0;i<262139;i++) table[i] = new HEntry();
	}
	
	public boolean insert(int i, String s) {
		int value = i%262139;
		if(value<0) value += 262139;
		
		for(int j=0;j<262139;j++) {
			if(table[j].i == i) return false;
		}
		
		if(table[value].s != null) {
			for(int j=value;j<262139;j++) {
				if(table[j].s == null) {
					table[j].i = i;
					table[j].s = s;
					return true;
				}
			}
			
			for(int j=0;j<value;j++) {
				if(table[j].s == null) {
					table[j].i = i;
					table[j].s = s;
					return true;
				}
			}
		}
		
		else {
			table[value].i = i;
			table[value].s = s;
		}
		
		return true;
	}
	
	public boolean delete(int i) {
		int value = i%262139;
		if(value<0) value += 262139;
		
		if(table[value].i == i) {
			table[value].deleted = true;
			return true;
		}
		
		else {
			for(int j=0;j<262139;j++) {
				if(table[j].i == i) {
					table[j].deleted = true;
					return true;
				}
			}
		}
		
		return false;
	}
	
	public String query(int i) {
		int value = i%262139;
		if(value<0) value += 262139;
		
		if(table[value].i == i) return table[value].s;
		
		else {
			for(int j=0;j<262139;j++) {
				if(table[j].i == i) return table[j].s;
			}
		}
		return null;
	}
}

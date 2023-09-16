
void phase_4(string input){ // di si dx cx
	// 3 byte in the stack
	int t1 , t2;  //   ?   0 
	auto res = sscanf(input , "%d %d" , t1 , t2);
	if(res != 2){
		bomb();
	}
	if(t1 > 14){
		bomb();
	}
	int res = func4(t1 , 0 , 14);
	if(res == 0){
		if(t2 == 0){
			goto L1;
		}
	}
	bomb();
	L1: success
}
//t1 0 14   di si dx cx
int fun4(int a , int  b  int c){ 
	//1 byte in the stack 
	//int res = c - b;
	//int d = res >> 31;  // -1 or 0
	//res = (d + res) / 2;
	//d = a + res;
	if(b > c) b += 1;
	int d = a + (c - b) / 2;
	
	if(d  >  a){
		res = func4(a , b , d - 1);
		return res * 2;
	}
	res = 0;
	if(c < a){
		res = func4(a , c + 1 , c);
		res = res * 2 + 1;
	}
	return res
}

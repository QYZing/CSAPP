


void phase6(string input){
	//80 字节
	int  a[6]; // rbx rbp r12 r13 r14
	int res = read_siz_numbers();
	
	int i = 0;
	int *rsp = &a[0];
	int *pa = &a[0];
L32:int *prbp = pa;
	int eax = pa[0];
	eax -= 1;
	if(eax > 5){
		bomb();
	}
	i++;
	if(i != 6){
L65:	int ebx = i;
		eax = rsp[i];
		if(eax == prbp[0]){
			bomb();
		}
		ebx += 1;
		if(ebx <= 5){
			goto L65;
		}
		pa++;
		goto L32;
	}
	int *rsi = &a[6];

L95:
	


	for(int i = 0;i < 6; i++){
		if(a[i] > 6){
			bomb();
		}
		
	}
	a0 -= 1;
	if(a0 > 6){
		bomb();
	}
		
	
}

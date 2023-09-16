
void phase(string input){
	usigned char  t ; // 0xc
	usigned char  t1 ; //0x8
	string fmt= "%d %d";
	char res = ssacnf(input , fmt , t1 ,t );	//sscanf("123456 ", "%s", buf);	
	if(res <= 1){
		explode_bomb();
		return ;	
	}
	if(t1 > 7){
		goto L1；
	}
	switch(t1){
		case 0: //  // 0x400f7c
				res = 0xcf;   //207
				break;
		case 2: //      // 0x400f83
				res = 0x2c3; // 707
				break;
		case 3: //      // 0x400f8a
				res = 0x100; // 256
				break;
		case 4: //      // 0x400f91
				res = 0x185; // 389
				break;
		case 5: //      // 0x400f98
				res = 0xce;  // 206
				break;
		case 6: //      // 0x400f9f
				res = 0x2aa; // 682
				break;
		case 7: //      // 0x400fa6
				res = 0x147; // 327
				break;
L1:     explode_bomb();
		 case ?: //      // 0x400fb2
				res = 0x0;
				break;
		case 1:
				res = 0x137; // 311
	}
	
	if(res == t){
		//	success
		return ;
	}
	explode_bomb();
}

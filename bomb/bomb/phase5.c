


char * A[] = "maduiersnfotvbyl" // 0x4024b0
void phase_5(string input){ // rdi
	// 32 byte
	int t1 = %fs:0x28; // rbx |  0x18 + rsp
	int res = string_length(input);
	char * result[6];	
	if(res != 6){
		bomb();
	}
	goto L1; // phase_5 + 39
	for(int i = 0; i < 6; i++){
		char rdx = inptu[i];
		int index = input[i] & 15;
		rdx = A[index];
		result[index] = rdx;
	}	
	res = strings_not_equal(result , "flyers"); // 9 15 14 5 6 7  
	if(res != 0){
		bomb();
	}
	
	L1:
}




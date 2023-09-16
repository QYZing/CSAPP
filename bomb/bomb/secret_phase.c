

void secret_phase(){
	chaar * input = read_line();
	long int res = strcol(input , NULL , 10);
	if(res > 1001){ // 0x3e8 == 1000
		bomb();
	}
	T * rdi = 0x6030f0;
	res = fun7(rdi , res);
	if(res != 2){
		bomb();
	}
	...
}

fun7(T * node , long int val){
	if(node != NULL){
		return -1;
	}

	if(node->val == val){
		return 0;
	}
	if(node->val > val){
		return fun7(nqode->left , val) * 2;
	}

	return fun7(node->right , val) * 2 + 1;
}

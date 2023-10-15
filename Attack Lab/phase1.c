#include <stdio.h>

int main()
{
	FILE * fp = fopen("phase1.txt" , "w");	
	if(fp == NULL){
		return 1;
	}
	const char * p = "0123456789012345678901234567890123456789\xc0\x17\x40";
	fputs(p , fp);
	fclose(fp);
	printf("success\n");
	return 0;
}

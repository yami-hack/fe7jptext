
INCLUDE link.ld
INCLUDE text.ld

SECTIONS
{
	/*要修改导入地址就看这里了*/
	.	=	0x9000000;
	
	.text : 
	{
		KEEP (*(EXCLUDE_FILE (*link.o) .text))
	}
	
	/*以后的数据*/
	.data : 
	{
		KEEP (*(EXCLUDE_FILE (data_*.o) .data))
	}
	.rodata : 
	{
		KEEP (*(EXCLUDE_FILE (data_*.o) .rodata))
	}
}
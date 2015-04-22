/*
 * text_show.c
 *
 *  Created on: 2015年4月21日
 *      Author: yami
 */


/**
 * @file		text_show.c
 * @author		yami
 * @date		2015-04-21 16:32:49
 * @brief
 * 显示的源码
 */


#include "types.h"

extern	void*		fonts[];
extern	void*		fonts2[];

extern	void*	_8005A60();
extern	void*	_80C0798();
extern	void*	_8005A24();

void*		T_show_font(u8*buf,void*a0);
void		T_show2_font(u8*buf,void*a0);

SECTION(".80056D8")
void*		text_show(void*a0,void*a1)
{
	struct{
		u8		u0_[0x4];
		u32		u4_;
		u8		u8_[0xE];
		u8		u16_;
	}*var1;
	var1	=	*(void**)0x2028D68;
	if(var1->u16_){
		return _8005A60(a0,a1);
	}
	else{
		u8*		buf;
		buf		=	a1;
		_80C0798(buf,a0,T_show_font);
		buf		+=	2;
		return buf;
	}
}


SECTION(".80055DC")
void		text_show2(void*a0,void*a1)
{
	struct{
		u8		u0_[0x4];
		u32		u4_;
		u8		u8_[0xE];
		u8		u16_;
	}*var1;
	var1	=	*(void**)0x2028D68;
	if(var1->u16_){
		_8005A24(a0,a1);
	}
	else{
		_80C0798(a1,a0,T_show2_font);
	}
}




void*		T_show_font(u8*buf,void*a0){
	struct{
		u8		u0_[4];
		u8		*u4_;
		void*	(*func)();
	}*var1;

	void**	font_base;
	u8		codeA;
	u8		codeB;
	struct{
		void*		next;
		u8			code;
		u8			w;
	}*font;

	var1		=	*((void**)0x2028D68);


	codeA	=	buf[0];
	codeB	=	buf[1];
	do{
		//由于ROM里面使用的是Shift-JIS编码,汉字特别少,
		//所以,我将判断使用GBK
		//Shift-JIS范围 codeA 0x81-0x9F,0xE0-0xEF
		//Shift-JIS范围 codeB 0x40-0x7E,0x80-0xfc

		//gb2312		codeA 0xA1-0xA9
		//gb2312		codeB 0xA1-0xFE
		if(codeA<=0x9F){
			font_base	=	(void*)(var1->u4_ - 0x100);
			font		=	font_base[codeB];		//这是编码2
			do{
				if(!font){
show_err:
					codeA		=	0x81;
					codeB		=	0xA7;
					var1		=	*((void**)0x2028D68);
					break;
				}
				if(font->code==codeA){
					return var1->func(a0,font);
				}
				else{
					font	=	font->next;
				}
			}while(1);
		}
		else{
			//大于0x9F为gb编码
			font		=	fonts[codeA];
			while(font){
				if(font->code==codeB){
					return var1->func(a0,font);
				}
				else{
					font	=	font->next;
				}
			}
			goto	show_err;
		}
	}while(1);

}

void		T_show2_font(u8*buf,void*a0){
	struct{
		u8		u0_[4];
		u8		*u4_;
		void*	(*func)();
	}*var1;
	struct{
		void*		next;
		u8			code;
		u8			w;
	}*font;
	void**		font_base;
	u8*			src;

	src		=	buf;

	if(*src>1){
		u8	codeA,codeB;
		do{
		codeA		=	*src++;
			if(codeA>0x1F){
				//由于ROM里面使用的是Shift-JIS编码,汉字特别少,
				//所以,我将判断使用GBK
				//Shift-JIS范围 codeA 0x81-0x9F,0xE0-0xEF
				//Shift-JIS范围 codeB 0x40-0x7E,0x80-0xfc

				//gb2312		codeA 0xA1-0xA9
				//gb2312		codeB 0xA1-0xFE
				codeB	=	*src++;
				var1		=	*((void**)0x2028D68);
				if(codeA<=0xA1){

show_:

					font_base	=	(void**)(var1->u4_ - 0x100);
					font		=	font_base[codeB];
					while(font){
						if(font->code==codeA){
							var1->func(a0,font);
							break;
						}
						else{
							font	=	font->next;
							if(!font){
show_err:
								codeB	=	0xA7;
								codeA	=	0x81;
								goto show_;
							}
						}
					}
				}
				else{
					//GBK编码
					font		=	fonts2[codeA];
					while(font){
						if(font->code==codeB){
							var1->func(a0,font);
							break;
						}
						else{
							font	=	font->next;
							if(!font){
								goto show_;
							}
						}
					}
				}


			}
		}while(*src>1);
	}
}



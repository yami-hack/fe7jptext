/*
 * texts.c
 *
 *  Created on: 2015��4��21��
 *      Author: yami
 */



/**
 * @file		texts.c
 * @author		yami
 * @date		2015-04-21 16:01:17
 * @brief
 * �й��ı����޸�
 * ҪGBK����
 */



#include "types.h"


u32			texts[] = {
#include "fe7jp.h"
		[0x01B4] =  (u32)"����"+0x80000000,
		[0x0471] =  (u32)"��ҩ"+0x80000000,
		[0x04E6]	=	 (u32)"��"+0x80000000,
};

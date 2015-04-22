/*
 * texts.c
 *
 *  Created on: 2015年4月21日
 *      Author: yami
 */



/**
 * @file		texts.c
 * @author		yami
 * @date		2015-04-21 16:01:17
 * @brief
 * 有关文本的修改
 * 要GBK保存
 */



#include "types.h"


u32			texts[] = {
#include "fe7jp.h"
		[0x01B4] =  (u32)"测试"+0x80000000,
		[0x0471] =  (u32)"伤药"+0x80000000,
		[0x04E6]	=	 (u32)"琳"+0x80000000,
};

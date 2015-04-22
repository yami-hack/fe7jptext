
include gcc-gba.mk

OUT		:=	fe7t.out


SRC		:=	font.c\
			font2.c\
			link.c\
			text_decode.c\
			text_show.c\
			texts.c
			
O_FILES	:=	$(SRC:.c=.o)
			
LDS		:=	hack.ld





.PHONY:build clean bin

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	

$(OUT):$(O_FILES)
	$(CC) $(CFLAGS) -T$(LDS) $^ -o $@



	
	
HACK_ADDR	:=	8013318 \
				80056D8 \
				80055DC 

				
ROM_BIN			:=	text.mbin

ROM_TEXT_BIN	:=	text.mtbin

HACK_REMOVE	:=	$(addprefix -R.,$(HACK_ADDR:= ))

HACK_DATA	:=	$(HACK_ADDR:=.sbin)


#输出段数据
%.sbin:$(OUT)
	$(OBJCOPY) -O binary -j.$(@:.sbin=) $< $@
	
%.mbin:$(OUT)
	$(OBJCOPY) -O binary $(HACK_REMOVE) $< $@
	

bin:$(HACK_DATA) $(ROM_BIN)
	echo ooo
	
clean:
	-rm $(OUT)
	-rm $(O_FILES)
	-rm $(HACK_DATA)
	-rm $(ROM_BIN)



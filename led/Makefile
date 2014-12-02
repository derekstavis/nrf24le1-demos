CC         := sdcc --verbose
PACKIHX    := packihx
HEX2IMAGE  := hex2image 
CFLAGS     := --opt-code-speed --model-small
LFLAGS     := --code-loc 0x0000 --code-size 0x4000 --xram-loc 0x0000 --xram-size 0x400
FLASH_SIZE := 16384
MAIN       := main
BIN        := led.img

SDK_DIR            := $(shell cd /opt/nrf24le1_sdk_v2.0 && pwd)
INCLUDE            += -I $(SDK_DIR)/include
REL_EXTERNAL_DIR   := $(SDK_DIR)/_target_sdcc_nrf24le1/obj
REL_EXTERNAL_FILES += $(REL_EXTERNAL_DIR)/delay/delay_us.rel
REL_EXTERNAL_FILES += $(REL_EXTERNAL_DIR)/delay/delay_ms.rel
REL_EXTERNAL_FILES += $(REL_EXTERNAL_DIR)/delay/delay_s.rel

REL_SRC := $(MAIN).c
REL_OBJ := $(patsubst %.c,%.rel,$(REL_SRC))

all: rel build

%.rel: %.c
	$(CC) -c $(INCLUDE) $(CFLAGS) $(LFLAGS) $^

rel: $(REL_OBJ)

build:
	$(CC) $(CFLAGS) $(LDFLAGS) $(REL_OBJ) $(REL_EXTERNAL_FILES)
	$(PACKIHX) $(MAIN).ihx > $(MAIN).hex
	$(HEX2IMAGE) -S $(FLASH_SIZE) < $(MAIN).hex > $(BIN)
	tail -n5 $(MAIN).mem

clean:
	$(RM) *.asm *.cdb *.hex *.ihx *.lk *.lst *.map *.mem *.omf *.rel *.rst *.sym *.img

test:
	@echo $(REL_EXTERNAL_FILES)

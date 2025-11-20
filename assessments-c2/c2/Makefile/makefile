# Makefile for C1M2 - supports PLATFORM=HOST and PLATFORM=MSP432
PLATFORM ?= HOST

ifeq ($(PLATFORM),HOST)
	CC       := gcc
	SIZE_TOOL:= size
	CPPFLAGS := -DHOST
	CFLAGS   := -Wall -Werror -g -O0 -std=c99
	LDFLAGS  := -Wl,-Map=c1m2.map
else
	CC       := arm-none-eabi-gcc
	SIZE_TOOL:= arm-none-eabi-size
	CPPFLAGS := -DMSP432
	CFLAGS   := -Wall -Werror -g -O0 -std=c99 \
	           -mcpu=cortex-m4 -mthumb -march=armv7e-m \
	           -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
	LDFLAGS  := -T msp432p401r.lds -Wl,-Map=c1m2.map
endif

-include sources.mk

INCLUDES ?= -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS

OBJECTS := $(SOURCES:.c=.o)
DEPS    := $(SOURCES:.c=.d)
OUT     := c1m2.out
MAP     := c1m2.map

.PHONY: all compile-all build clean size run asm-all

all:
	@echo "Use: make build PLATFORM=HOST|MSP432"

compile-all: $(OBJECTS)
	@echo "Objects: $(OBJECTS)"

build: $(OUT)
	@echo "Built $(OUT)"

$(OUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(OUT) $(LDFLAGS)

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -MMD -MP -MF $(@:.o=.d) -c $< -o $@

%.i: %.c
	$(CC) $(CPPFLAGS) $(INCLUDES) $(CFLAGS) -E $< -o $@

%.asm: %.c
	$(CC) $(CPPFLAGS) $(INCLUDES) $(CFLAGS) -S $< -o $@

asm-all: $(SOURCES:.c=.asm) $(OUT)
	@echo "Generating disassembly -> c1m2_binary.asm"
	@if command -v objdump >/dev/null 2>&1; then \
	  objdump -d $(OUT) > c1m2_binary.asm || true; \
	else \
	  echo "objdump not found; skipping binary disassembly"; \
	fi

size: $(OUT)
	@if command -v $(SIZE_TOOL) >/dev/null 2>&1; then \
	  $(SIZE_TOOL) $(OUT); \
	else \
	  echo "Size tool '$(SIZE_TOOL)' not found."; \
	fi

run: $(OUT)
ifneq ($(PLATFORM),HOST)
	@echo "ERROR: run only valid for PLATFORM=HOST" ; exit 1
else
	@echo "Running $(OUT):" ; ./$(OUT)
endif

clean:
	@echo "Cleaning..."
	@rm -f $(OUT) $(MAP) c1m2_binary.asm
	@rm -f $(OBJECTS) $(DEPS)
	@rm -f $(SOURCES:.c=.i) $(SOURCES:.c=.asm)
	@rm -f *.o *.d *.map *.out

-include $(DEPS)

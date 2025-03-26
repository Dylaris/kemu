CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -I./include
TARGET = main

SRC = ./hardware/cpu/cpu.c ./hardware/cpu/mmu.c \
	  ./hardware/disk/disk.c \
	  ./hardware/mm/dram.c ./hardware/mm/sram.c \
	  main.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)

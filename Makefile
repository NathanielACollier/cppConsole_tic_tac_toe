# Nathaniel Collier
# 2/2/2007
# Tic Tac Toe Game Makefile

#Example:   export set NAC_LIB_DIR=~/binCLib
ifeq ($(NAC_LIB_DIR),)
  $(error NAC_LIB_DIR is not set)
endif

CC = g++

EXE_FILE = tictactoe.exe

C_FLAGS =  -g3 -O0

L_FLAGS =  -Wl,--allow-multiple-definition


C_FILES = tictactoe.cpp 

H_FILES = 

LIB_DIR = $(NAC_LIB_DIR)
LIB_FILES = 
L_FILES := $(patsubst %, $(LIB_DIR)/lib%.a, $(LIB_FILES))

O_FILES := $(patsubst %.cpp,o/%.o,$(C_FILES))

all:
	mkdir -p o
	make -s $(EXE_FILE)

$(EXE_FILE): $(O_FILES)
	$(CC) -o $(EXE_FILE) $(O_FILES) $(L_FILES) $(L_FLAGS)
	echo "Done compiling $(EXE_FILE).";
	chmod 777 $(EXE_FILE)
	chmod 777 $(O_FILES)

clean:
	rm -f $(O_FILES) $(EXE_FILE)

o/%.o: %.cpp
	echo "  Compiling $@....";
	$(CC) -c $(C_FLAGS) $< -o $@


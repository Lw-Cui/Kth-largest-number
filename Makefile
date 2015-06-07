HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION)) 
MYFLAGS = -g -pg
CC = g++
OBJ_DIR = obj
OBJ = main.o 
BUILD_DIR = build
SRC_DIR = /home/lw/icpc/xth/src

$(BUILD_DIR)/xth.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(MYFLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/xth.out 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) $(MYFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out

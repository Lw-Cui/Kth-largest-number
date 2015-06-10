HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION)) -pg -g
CC = g++
OBJ_DIR = obj
OBJ = main.o 
BUILD_DIR = build
SRC_DIR = /home/lw/icpc/Kth-largest/src

$(BUILD_DIR)/Kth-largest.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/Kth-largest.out 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out

HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
<<<<<<< HEAD
FLAGS = $(addprefix -,$(CCOPTION)) -pg -g
=======
FLAGS = $(addprefix -,$(CCOPTION)) 
MYFLAGS = -g -pg
>>>>>>> ab77b26b4d283c5637d0449733c49d1bf08a80c6
CC = g++
OBJ_DIR = obj
OBJ = main.o 
BUILD_DIR = build
<<<<<<< HEAD
SRC_DIR = /home/lw/icpc/Kth-largest/src

$(BUILD_DIR)/Kth-largest.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/Kth-largest.out 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)
=======
SRC_DIR = /home/lw/icpc/xth/src

$(BUILD_DIR)/xth.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(MYFLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/xth.out 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) $(MYFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)
>>>>>>> ab77b26b4d283c5637d0449733c49d1bf08a80c6


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out

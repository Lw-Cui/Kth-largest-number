HDR_DIR = header
HEADER = $(addprefix -I,$(HDR_DIR))
CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1 pg
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ_DIR = obj
OBJ = DivideAndConquer.o maxHeap.o qsort.o selectionSort.o main.o 
BUILD_DIR = build
SRC_DIR = /home/lw/icpc/Kth-largest/src

$(BUILD_DIR)/Kth-largest.out: $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(BUILD_DIR)/Kth-largest.out 

$(OBJ_DIR)/DivideAndConquer.o: $(SRC_DIR)/DivideAndConquer.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/DivideAndConquer.cpp -o $(OBJ_DIR)/DivideAndConquer.o $(HEADER)

$(OBJ_DIR)/maxHeap.o: $(SRC_DIR)/maxHeap.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/maxHeap.cpp -o $(OBJ_DIR)/maxHeap.o $(HEADER)

$(OBJ_DIR)/qsort.o: $(SRC_DIR)/qsort.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/qsort.cpp -o $(OBJ_DIR)/qsort.o $(HEADER)

$(OBJ_DIR)/selectionSort.o: $(SRC_DIR)/selectionSort.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/selectionSort.cpp -o $(OBJ_DIR)/selectionSort.o $(HEADER)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o $(HEADER)


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out

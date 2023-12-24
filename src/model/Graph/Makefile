NAME			:= s21_graph.a

CC				:= g++
CCFLAGS			:= -Wall -Wextra -Werror -std=c++17
LDFLAGS			:= -lgtest

SRC_DIR			:= src/
OBJ_DIR			:= obj/
INC_DIR			:= inc/
TEST_DIR		:= tests/

SRC_FILES		:= s21_graph.cc LoadGraphFromFile.cc
OBJ_FILES		:= $(SRC_FILES:.cc=.o)
INC_FILES		:= GraphExceptions.h
HEADER			:= s21_graph.h
TEST_FILES		:= run_tests.cc LoadGraphFromFile_test.cc
TEST_EXE		:= tests.exe

SRC				:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC				:= $(addprefix $(INC_DIR), $(INC_FILES)) $(HEADER)
TEST			:= $(addprefix $(TEST_DIR), $(TEST_FILES))

.PHONY: all clean re test $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo Compiling $(NAME) success!

$(OBJ_DIR)%.o : $(SRC_DIR)%.cc $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

test: all
	@$(CC) $(CCFLAGS) $(TEST) $(NAME) -o $(TEST_DIR)$(TEST_EXE) $(LDFLAGS)
	./$(TEST_DIR)$(TEST_EXE)
# leaks -atExit -- ./$(TEST_DIR)$(TEST_EXE) #если добавить -fsanitize=address, то ликов нет
	rm $(TEST_DIR)$(TEST_EXE)

clean:
	@rm -rf $(OBJ_DIR) $(NAME)
	@echo Cleaning success!

re: clean all

NAME			:=	cli.a

CC				:=	g++
CCFLAGS			:=	-Wall -Wextra -Werror -std=c++17
LDFLAGS			:=	-lgtest

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
INC_DIR			:=	inc/

SRC_FILES		:=	cli.cc

OBJ_FILES		:=	$(SRC_FILES:.cc=.o)
INC_FILES		:=	GraphExceptions.h
HEADER			:=	s21_graph.h

SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC				:=	$(addprefix $(INC_DIR), $(INC_FILES)) $(HEADER)
TEST			:=	$(addprefix $(TEST_DIR), $(TEST_FILES))

.PHONY: all clean re $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo Compiling $(NAME) success!


$(OBJ_DIR)%.o : $(SRC_DIR)%.cc $(INC) | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(TEMP_DIRS) $(NAME)
	@echo Cleaning success!

re: clean all

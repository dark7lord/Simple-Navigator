NAME			:=	s21_cli.a

CC				:=	g++
CCFLAGS			:=	-Wall -Wextra -Werror -std=c++17
LDFLAGS			:=	-lgtest

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
INC_DIR			:=	inc/

SRC_FILES		:=	cli.cc \
					inputs.cc \
					files.cc \
					algs_methods.cc


OBJ_FILES		:=	$(SRC_FILES:.cc=.o)
INC_FILES		:=	colors.h
HEADER			:=	cli.h

SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC				:=	$(addprefix $(INC_DIR), $(INC_FILES)) $(HEADER)

.PHONY: all clean re $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	echo Compiling $(NAME) success!


$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cc $(INC) | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf obj $(NAME)
	@echo Cleaning success!

re: clean all

clang_n:
	clang-format -style=Google -n src/*.cc inc/*.h *.h
clang_i:
	clang-format -style=Google -i src/*.cc inc/*.h *.h

NAME:= main.exe

CC				:= g++
CCFLAGS			:= -Wall -Wextra -Werror -std=c++17

ALGS_NAME		:= s21_graph_algorithms.a
ALGS_PATH		:= model/GraphAlgorithms
ALGS			:= $(ALGS_PATH)/$(ALGS_NAME)

GRAPHS_NAME		:= s21_graph.a
GRAPHS_PATH		:= model/Graph
GRAPHS			:= $(GRAPHS_PATH)/$(GRAPHS_NAME)

SRC				:= main.cc

.PHONY: all run clean re test check_ext

all: check_ext $(NAME)

check_ext:
	@echo ...compiling $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)

run: all
	./$(NAME)

$(NAME): $(SRC) $(ALGS) $(GRAPHS)
	$(CC) $(CCFLAGS) $(SRC) $(GRAPHS) $(ALGS) -o $(NAME)

$(GRAPHS):
	@echo ...compiling $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)

$(ALGS):
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)

clean:
	@rm -f $(NAME)
	@echo ...clean $(GRAPHS_NAME) && make --silent -C $(GRAPHS_PATH) clean
	@echo ...clean $(ALGS_NAME) && make --silent -C $(ALGS_PATH) clean
	@echo Cleaning success!

test:
	make --silent -C $(GRAPHS_PATH) test
	make --silent -C $(ALGS_PATH) test

re: clean all

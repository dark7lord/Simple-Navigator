NAME			:= main

CC				:= g++
CCFLAGS			:= -Wall -Wextra -Werror -std=c++17

ALGS_NAME		:= s21_graph_algorithms.a
ALGS_PATH		:= model/GraphAlgorithms
ALGS			:= $(ALGS_PATH)/$(ALGS_NAME)

GRAPHS_NAME		:= s21_graph.a
GRAPHS_PATH		:= model/Graph
GRAPHS			:= $(GRAPHS_PATH)/$(GRAPHS_NAME)

CLI_NAME		:= s21_cli.a
CLI_PATH		:= view/CLI
CLI				:= $(CLI_PATH)/$(CLI_NAME)

SRC				:= main.cc

.PHONY: all run clean re test check_ext

all: check_ext $(NAME)

check_ext:
	@echo ...compiling $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)
	@echo ...compiling $(CLI_NAME) && make -C $(CLI_PATH)

run: all
	./$(NAME)

# $(NAME): $(SRC) $(ALGS) $(GRAPHS) $(CLI)
$(NAME): $(SRC) check_ext
	$(CC) $(CCFLAGS) $(SRC) $(GRAPHS) $(ALGS) $(CLI) -o $(NAME)

$(GRAPHS):
	@echo ...compiling $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)

$(ALGS):
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)

$(CLI):
	@echo ...compiling $(CLI_NAME) && make -C $(CLI_PATH)

clean:
	@rm -f $(NAME)
	@echo ...clean $(GRAPHS_NAME) && make --silent -C $(GRAPHS_PATH) clean
	@echo ...clean $(ALGS_NAME) && make --silent -C $(ALGS_PATH) clean
	@echo ...clean $(CLI_NAME) && make --silent -C $(CLI_PATH) clean
	@echo Cleaning success!

test:
	@make --silent -C $(GRAPHS_PATH) test
	@make --silent -C $(ALGS_PATH) test

clang_n:
	@make --silent -C $(GRAPHS_PATH) clang_n
	@make --silent -C $(ALGS_PATH) clang_n
	@make --silent -C $(CLI_PATH) clang_n
	@echo clang_n for all!

clang_i:
	@make --silent -C $(GRAPHS_PATH) clang_i
	@make --silent -C $(ALGS_PATH) clang_i
	@make --silent -C $(CLI_PATH) clang_i
	@echo clang_i for all!

coverage:
	@make --silent -C $(GRAPHS_PATH) coverage
	@make --silent -C $(ALGS_PATH) coverage

coverage:
	make --silent -C $(GRAPHS_PATH) coverage
	make --silent -C $(ALGS_PATH) coverage

re: clean all

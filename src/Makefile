NAME:= main.exe

CC				:= g++
CCFLAGS			:= -Wall -Wextra -Werror -std=c++17

ALGS_NAME := s21_graph_algorithms.a
ALGS_PATH := model/GraphAlgorithms/
ALGS := $(ALGS_PATH)/$(ALGS_NAME)

GRAPHS_NAME := s21_graph.a
GRAPHS_PATH := model/Graph/
GRAPHS := $(GRAPHS_PATH)/$(GRAPHS_NAME)

SRC:= main.cc

all: $(NAME)

run: all
	./$(NAME)

$(NAME): $(SRC) $(ALGS) $(GRAPHS)
	$(CC) $(CCFLAGS) $(SRC) $(GRAPHS) $(ALGS) -o $(NAME)

$(GRAPHS):
	@echo ...compiling $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)

$(ALGS):
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)

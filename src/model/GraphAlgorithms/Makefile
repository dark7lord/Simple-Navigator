NAME			:=	s21_graph_algorithms.a
GRAPH_NAME		:=	../Graph/s21_graph.a

CC				:=	g++
CCFLAGS			:=	-Wall -Wextra -Werror -std=c++17
LDFLAGS			:=	-lgtest
TEST_FLAGS		:=	$(CXXFLAGS) --coverage -fprofile-arcs -ftest-coverage
GTEST_LIBS		:=	-lgtest -lgtest_main -pthread

SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
INC_DIR			:=	inc/
TEST_DIR		:=	tests/
REPORT_DIR		:=	report/
TEST_TEMP_DIR	:=	test_tmp/

TEMP_DIRS		:=	$(OBJ_DIR) \
					$(TEST_TEMP_DIR) \
					$(REPORT_DIR)

SRC_FILES		:=	s21_graph_algorithms.cc \
					GetShortestPathsBetweenAllVertices.cc\
					s21_get_least_spanninng_tree.cc\
					Dijkstra’s_algorithm.cc\
					Ant_algorythm.cc

OBJ_FILES		:= $(SRC_FILES:.cc=.o)
INC_FILES		:= lie.h
HEADER			:= s21_graph_algorithms.h
TEST_FILES		:=	tests_get_least_spanning_tree.cc\
					GetShortestPathsBetweenAllVertices_test.cc\
					run_tests.cc\

TEST_EXE		:= tests.exe

SRC				:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC				:= $(addprefix $(INC_DIR), $(INC_FILES)) $(HEADER)
TEST			:= $(addprefix $(TEST_DIR), $(TEST_FILES))

TEST_TMP_FILES	:=	$(TEST:$(TEST_DIR)%.cc=$(TEST_TEMP_DIR)%.o) \
					$(SRC:$(SRC_DIR)%.cc=$(TEST_TEMP_DIR)%.o)

.PHONY: all clean re test $(NAME) coverage

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo Compiling $(NAME) success!

$(TEMP_DIRS):
	mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.cc $(INC) | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(TEST_TEMP_DIR)%.o: $(SRC_DIR)%.cc | $(TEST_TEMP_DIR)
	$(CC) $(CCFLAGS) $(TEST_FLAGS) -c $< -o $@

$(TEST_TEMP_DIR)%.o: $(TEST_DIR)%.cc | $(TEST_TEMP_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

test: all $(TEST_TMP_FILES) | $(TEST_TEMP_DIR)
	@make -C ../Graph
	@$(CC) $(TEST_FLAGS) $(TEST_TMP_FILES) $(GTEST_LIBS) $(GRAPH_NAME)  -o $(TEST_DIR)$(TEST_EXE) $(LDFLAGS)
	./$(TEST_DIR)$(TEST_EXE) || true

#	leaks -atExit -- ./$(TEST_DIR)$(TEST_EXE)
	rm -f $(TEST_DIR)$(TEST_EXE)

coverage: test | $(REPORT_DIR)
	@lcov -t "coverage" \
		--output-file $(REPORT_DIR)coverage.info \
		--capture \
		--ignore-errors mismatch \
		--quiet \
		--directory $(TEST_TEMP_DIR)

	@genhtml -o $(REPORT_DIR) $(REPORT_DIR)coverage.info \
		--quiet \
		--exclude "10.3.0*"\
		 && echo "...Compiling report.html"
	open $(REPORT_DIR)index.html && echo "...Opening report.html"

clean:
	@rm -rf $(TEMP_DIRS) $(NAME)
	@echo Cleaning success!

re: clean $(TEMP_DIRS) all

ALGS := s21_graph_algorithms.a
ALGS_NAME := s21_graph_algorithms
ALGS_PATH := model/GraphAlgorithms/

GRAPHS := s21_graph.a
GRAPHS_NAME := s21_graph
GRAPHS_PATH := model/Graph/

$(GRAPHS):
# $(MAKE) --silent -C model/s21_graph_algorithms make
	@echo ...compiling! $(GRAPHS_NAME) && make -C $(GRAPHS_PATH)
	@echo $(GRAPHS_PATH)

$(ALGS):
# $(MAKE) --silent -C model/s21_graph_algorithms make
	@echo ...compiling $(ALGS_NAME) && make -C $(ALGS_PATH)
	@echo $(ALGS_PATH)

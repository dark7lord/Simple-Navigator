#include "../s21_graph_algorithms.h"

namespace s21 {

int GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
    int size = graph.GetSize();
    if (vertex1 > size || vertex2 > size || vertex1 < 1 || vertex2 < 1) throw std::invalid_argument("Введено невалидное число!\n");
    std::vector<int> distance(graph.GetSize(), INT_MAX);
    int start = vertex1 - 1;
    int finish = vertex2 - 1;
    distance[start] = 0;
    std::set<std::pair<int, int>> save;
    save.insert({distance[start], start});
    while (!save.empty()) {
        int from = save.begin()->second;
        save.erase(save.begin());
        for (int i = 0; i < size; i++) {
            int edge = graph.GetMatrix()[from][i];
            if (edge) {
                int new_lenght = distance[from] + edge;
                if (new_lenght < distance[i]) {
                    save.erase({distance[i], i});
                    distance[i] = new_lenght;
                    save.insert({distance[i], i});
                }
            }
        }   
    }
    return distance[finish];
}
}
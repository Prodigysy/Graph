#include <gtest/gtest.h>
#include "Graph/Graph.h"

class GraphTest : public ::testing::Test {
protected:
    void SetUp() override {
        graph.add_vertex("A");
        graph.add_vertex("B");
        graph.add_vertex("C");
        graph.add_vertex("D");

        graph.add_edge("A", "B", 2.0);
        graph.add_edge("A", "C", 1.5);
        graph.add_edge("B", "D", 3.0);
        graph.add_edge("C", "D", 2.5);
    }

    Graph<std::string, double> graph;
};

TEST_F(GraphTest, AddVertex) {
    ASSERT_TRUE(graph.has_vertex("A"));
    ASSERT_TRUE(graph.has_vertex("B"));
    ASSERT_TRUE(graph.has_vertex("C"));
    ASSERT_TRUE(graph.has_vertex("D"));
}

TEST_F(GraphTest, AddRemoveEdge) {
    ASSERT_TRUE(graph.has_edge("A", "B"));
    ASSERT_TRUE(graph.has_edge("A", "C"));
    ASSERT_TRUE(graph.has_edge("B", "D"));
    ASSERT_TRUE(graph.has_edge("C", "D"));

    ASSERT_TRUE(graph.remove_edge("A", "B"));
    ASSERT_FALSE(graph.has_edge("A", "B"));
}

TEST_F(GraphTest, BreadthFirstSearch_PrintResult) {
    std::vector<std::string> visited_vertices;
    auto action = [&visited_vertices](const std::string& vertex) {
        visited_vertices.push_back(vertex);
        std::cout << vertex << " -> ";
        };

    std::cout << "BFS traversal result: ";
    graph.walk("A", action);
    std::cout << std::endl;

    ASSERT_EQ(visited_vertices.size(), 4);
    ASSERT_EQ(visited_vertices[0], "A");
    ASSERT_EQ(visited_vertices[1], "B");
    ASSERT_EQ(visited_vertices[2], "C");
    ASSERT_EQ(visited_vertices[3], "D");
}


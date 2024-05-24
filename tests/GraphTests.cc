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


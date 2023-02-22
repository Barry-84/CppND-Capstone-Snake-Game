#include <algorithm>
#include <iostream>
#include "pathplanner.h"

//PathPlanner::PathPlanner(const std::size_t grid_width, const std::size_t grid_height) : grid(grid.resize(grid_width, grid_height)) {
PathPlanner::PathPlanner(const std::size_t grid_width, const std::size_t grid_height) {
    grid.resize(grid_height, std::vector<Node*>(grid_width));
    std::cout << "grid height: " << grid.size() << ", grid width: " << grid[0].size() << std::endl;
}

float PathPlanner::CalculateHValue(Node const *node) {
    return node->distance(*end_node);
}

void PathPlanner::AddNeighbours(Node *current_node) {
    current_node->FindNeighbours();
    for (Node* node : current_node->neighbours) {
        if (!node->visited) {
            node->parent = current_node;
            node->h_value = CalculateHValue(node);
            node->g_value = current_node->g_value + current_node->distance(*node);
            node->visited = true;
            open_list.push_back(node);
        }
    }
}

bool sortBySumDescending(Node const *node1, Node const *node2) {
    return (node1->h_value + node1->g_value) > (node2->h_value + node2->g_value);
}

Node* PathPlanner::NextNode() {
    // could also use lambda expression instead of auxiliary (predicate?) function sortBySumDescending.
    std::sort(open_list.begin(), open_list.end(), sortBySumDescending);
    Node* lowestSumNode = open_list.back();
    open_list.pop_back();
    return lowestSumNode;
}

//std::vector<Node> PathPlanner::ConstructFinalPath(Node *current_node) {
void PathPlanner::ConstructFinalPath(Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    //std::vector<Node> path_found;

    // TODO: Implement your solution here.
    while (current_node != start_node) {
        distance += current_node->distance(*current_node->parent);
        //path_found.push_back(*current_node);
        path.push_back(current_node);
        current_node = current_node->parent;
    }

    // push the start node to the path.
    //path_found.push_back(*current_node);
    path.push_back(current_node);

    //distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    //reverse(path_found.begin(), path_found.end());
    reverse(path.begin(), path.end());

    //return path_found;

}

std::vector<Node*> PathPlanner::AStarSearch(int start_x, int start_y, int end_x, int end_y) {

    Node *current_node = nullptr;

    start_x = start_x;
    start_y = start_y;
    end_x = end_x;
    end_y = end_y;

    start_node->x = start_x;
    start_node->y = start_y;
    end_node->x = end_x;
    end_node->y = end_y;

    // TODO: Implement your solution here.
    start_node->visited = true;
    open_list.push_back(start_node);
    AddNeighbours(start_node);

    while (!open_list.empty()) {
        // sort the open list and return the next node (node with lowest f-value)
        current_node = NextNode();
        // check whether we've reached the end_node.
        // Alternatively: current_node->x == end_node->x && current_node->y == end_node->y
        if (current_node->distance(*end_node) == 0) {
            //m_Model.path = ConstructFinalPath(current_node);
            ConstructFinalPath(current_node);
            break;
        }
        AddNeighbours(current_node);
    }

    return path;
}
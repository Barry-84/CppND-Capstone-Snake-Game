// //#include <memory>
// #include "node.h"

// // Finds the 4 neighbours north, south, east and west of the current node.
// // Note the snake cannot moved diagonally as it also cannot do so when
// // controlled manually. 
// void Node::FindNeighbours() {
//     for (auto& delta : neighboursDeltas) {
//         Node* neighbour = new Node;
//         ////std::unique_ptr<Node> neighbour = std::make_unique<Node>;
//         neighbour->x = this->x + delta[0];
//         neighbour->y = this->y + delta[1];
//         if (neighbour->x >= 0 && neighbour->x <= 32 && neighbour->y >= 0 && neighbour->x <= 32) {
//             neighbours.push_back(neighbour);
//         }
//         //delete neighbour;
//         ////neighbours.push_back(grid[this->x + delta[0], this->y + delta[1]]);
//     }
// }

// float Node::distance(Node other) const {
//     return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
// }
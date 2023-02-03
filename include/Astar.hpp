/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:07:43
 * @ Description:
 */

#pragma once

#include "Node.hpp"
#include "RawMap.hpp"
#include <math.h>

class Astar
{
    public:
        Astar(RawMap map, Vector2f start, Vector2f target);
        ~Astar() = default;

        void findPath();

    private:
        Node<RawMap, Vector2f> m_startNode;
        Node<RawMap, Vector2f> m_targetNode;
        Node<RawMap, Vector2f> m_lastNode;
        std::vector<Node<RawMap, Vector2f>> m_openList;
        std::vector<Node<RawMap, Vector2f>> m_closedList;
        std::pair<int, int> m_startPos;
        std::pair<int, int> m_endPos;
};

namespace heuristic
{
    int manhattanDistance(std::pair<int, int> start, std::pair<int, int> target);
    int euclideanDistance(std::pair<int, int> start, std::pair<int, int> target);
}
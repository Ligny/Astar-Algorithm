/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:07:43
 * @ Description:
 */

#pragma once

#include "Node.hpp"

using ProtoMap = std::vector<std::vector<char>>;
using Vector2f = std::pair<int, int>;

class Astar
{
    public:
        Astar();
        ~Astar() = default;

        void findPath(ProtoMap& map, Vector2f start, Vector2f target);

    private:
        // Node<ProtoMap, Vector2f> m_startNode;
        // Node<ProtoMap, Vector2f> m_targetNode;
        // Node<ProtoMap, Vector2f> m_lastNode;
        // std::vector<Node<ProtoMap, Vector2f>> m_openList;
        // std::vector<Node<ProtoMap, Vector2f>> m_closedList;
        // std::pair<int, int> m_endPos;
};
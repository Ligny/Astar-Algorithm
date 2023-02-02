/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:12:38
 * @ Description:
 */

#include "../include/Astar.hpp"
#include <iostream>

Astar::Astar()
{
    // ProtoMap toto = {};

    // m_startNode = Node<ProtoMap, Vector2f>({0, 0}, toto);
    // m_targetNode = Node<ProtoMap, Vector2f>({0, 0}, toto);
    // m_lastNode = m_startNode;
    // m_openList.clear();
    // m_closedList.clear();
    // m_endPos = {0, 0};
}



void Astar::findPath(ProtoMap& map, Vector2f start, Vector2f target)
{
    std::cout << "Start: " << start.first << ", " << start.second << std::endl;
    return;
}
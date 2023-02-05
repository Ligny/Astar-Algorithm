/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:07:43
 * @ Description:
 */

#pragma once

#include <queue>
#include <math.h>

#include "../include/Node.hpp"

class Astar
{
    public:
        Astar(std::vector<std::vector<Node>> map, Vector2f start, Vector2f end, Vector2f size);

        bool isFinish(Vector2f pos);
        bool isWalkable(Vector2f pos);
        bool isOutOfBounds(Vector2f pos);
        std::vector<Node> findPath();
    private:
        std::uint32_t m_width;
        std::uint32_t m_height;
        std::vector<std::vector<Node>> m_map;
        std::vector<Node> m_openList;
        Vector2f m_start;
        Vector2f m_end;
};
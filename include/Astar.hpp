/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:07:43
 * @ Description:
 */

#pragma once

#include <queue>
#include <math.h>
#include <array>

#include "../include/Node.hpp"

class Astar
{
    public:
        Astar(std::vector<std::vector<Node>> map, Vector2f start, Vector2f end, Vector2f size);

        bool isFinish(Vector2f pos);
        bool isWalkable(Vector2f pos);
        bool isOutOfBounds(Vector2f pos);
        std::vector<Node> findPath(std::function<float(Vector2f, Vector2f)> heuristic, int direction_nbr);
    private:
        std::uint32_t m_width;
        std::uint32_t m_height;
        std::vector<std::vector<Node>> m_map;
        std::vector<Node> m_openList;
        std::vector<Node> m_closedList;
        Vector2f m_start;
        Vector2f m_end;
        std::array<Vector2f, 8> m_directions;
        std::uint16_t m_nbrDirections;
};

namespace heuristic
{
    float manhattan(Vector2f start, Vector2f target);
    float euclidean(Vector2f start, Vector2f target);
}
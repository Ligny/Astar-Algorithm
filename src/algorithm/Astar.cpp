/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-04 17:06:53
 * @ Description:
 */

#include "../../include/Astar.hpp"

Astar::Astar(std::vector<std::vector<Node>> map, Vector2f start, Vector2f end, Vector2f size)
: m_map(map), m_start(start), m_end(end), m_width(size.first), m_height(size.second)
{
};


bool Astar::isFinish(Vector2f pos)
{
    return pos == m_end;
};

bool Astar::isWalkable(Vector2f pos)
{
    return m_map[pos.first][pos.second].isWalkable;
};

bool Astar::isOutOfBounds(Vector2f pos)
{
    return pos.first < 0 || pos.first >= m_width || pos.second < 0 || pos.second >= m_height;
};

std::vector<Node> Astar::findPath(std::function<float(Vector2f, Vector2f)> heuristic_fct, int direction_nbr)
{
    m_nbrDirections = direction_nbr;
    int x = m_start.first;
    int y = m_start.second;
    m_map[x][y].m_gCost = 0.0f;
    m_map[x][y].m_fCost = 0.0f;
    m_map[x][y].m_hCost = 0.0f;
    m_map[x][y].m_parent = m_start;

    m_openList.emplace_back(m_map[x][y]);

    while (!m_openList.empty() && m_openList.size() < m_height * m_width) {
        std::sort(m_openList.begin(), m_openList.end());
        Node current = m_openList.back();
        m_openList.pop_back();

        if (isFinish(current.m_pos)) {
            std::vector<Node> path;
            while (current.m_pos != m_start) {
                path.emplace_back(current);
                current = m_map[current.m_parent.first][current.m_parent.second];
            }
            path.emplace_back(current);
            return path;
        }

        for (int i = 0; i < m_nbrDirections; i++) {
            auto dir = m_directions[i];
            Vector2f newPos = {current.m_pos.first + dir.first, current.m_pos.second + dir.second};
            if (isOutOfBounds(newPos) || !isWalkable(newPos)) {
                continue;
            }

            float newGCost = current.m_gCost + 1.0f;
            if (newGCost < m_map[newPos.first][newPos.second].m_gCost) {
                m_map[newPos.first][newPos.second].m_gCost = newGCost;
                m_map[newPos.first][newPos.second].m_hCost = heuristic_fct(newPos, m_end);
                m_map[newPos.first][newPos.second].m_fCost = m_map[newPos.first][newPos.second].m_gCost + m_map[newPos.first][newPos.second].m_hCost;
                m_map[newPos.first][newPos.second].m_parent = current.m_pos;
                m_openList.emplace_back(m_map[newPos.first][newPos.second]);
            }
        }
    }
    return {};
}

float heuristic::manhattan(Vector2f start, Vector2f target)
{
    return abs(start.first - target.first) + abs(start.second - target.second);
}

float heuristic::euclidean(Vector2f start, Vector2f target)
{
    return sqrt(pow(start.first - target.first, 2) + pow(start.second - target.second, 2));
}

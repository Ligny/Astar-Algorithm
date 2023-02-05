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

std::vector<Node> Astar::findPath()
{
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

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                Vector2f neighbour = {current.m_pos.first + i, current.m_pos.second + j};
                if (isOutOfBounds(neighbour) || !isWalkable(neighbour))
                    continue;
                float gCost = current.m_gCost + sqrt(i * i + j * j);
                float hCost = sqrt((neighbour.first - m_end.first) * (neighbour.first - m_end.first) + (neighbour.second - m_end.second) * (neighbour.second - m_end.second));
                float fCost = gCost + hCost;
                if (fCost < m_map[neighbour.first][neighbour.second].m_fCost) {
                    m_map[neighbour.first][neighbour.second].m_fCost = fCost;
                    m_map[neighbour.first][neighbour.second].m_gCost = gCost;
                    m_map[neighbour.first][neighbour.second].m_hCost = hCost;
                    m_map[neighbour.first][neighbour.second].m_parent = current.m_pos;
                    m_openList.emplace_back(m_map[neighbour.first][neighbour.second]);
                }
            }
        }
    }
}

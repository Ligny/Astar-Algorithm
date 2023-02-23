/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-04 17:06:53
 * @ Description:
 */

#include "../../include/Astar.hpp"
#include <algorithm>

Astar::Astar(std::vector<std::vector<Node>> map, Vector2f start, Vector2f end, Vector2f size)
: m_map(map), m_start(start), m_end(end), m_width(size.first), m_height(size.second), m_directions({{Vector2f(0, -1), Vector2f(1, 0), Vector2f(0, 1), Vector2f(-1, 0), Vector2f(-1, -1), Vector2f(1, -1), Vector2f(1, 1), Vector2f(-1, 1)}}), m_nbrDirections(8)
{
    m_height = m_height - 1;
    m_width = m_width - 1;

    // for (auto row : m_map)
    // {
    //     for (auto node : row)
    //     {
    //         std::cout << node.isWalkable << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << "Start: " << m_start.first << " " << m_start.second << std::endl;
    std::cout << "End: " << m_end.first << " " << m_end.second << std::endl;

    std::cout << "Width: " << m_width << std::endl;
    std::cout << "Height: " << m_height << std::endl;
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
    // Astar algorithm
    // each cost Node __FLT_MAX__

    // 1. Add the starting square (or node) to the open list.
    std::cout << "Start: " << m_start.first << " " << m_start.second << std::endl;
    m_openList.push_back(m_map[m_start.first][m_start.second]);

    // 2. Repeat the following:
    while (!m_openList.empty())
    {
        // a) Look for the lowest F cost square on the open list. We refer to this as the current square.
        std::sort(m_openList.begin(), m_openList.end());
        Node current = m_openList[0];

        // b) Switch it to the closed list.
        m_closedList.push_back(current);
        m_openList.erase(m_openList.begin());
        std::cout << "--- debug ---" << std::endl;

        // c) For each of the 8 squares adjacent to this current square ...
        std::cout << "nbr of direction: " << direction_nbr << std::endl;
        for (int i = 0; i < direction_nbr; i++)
        {
            std::cout << "debug1" << std::endl;
            std::cout << "looking direction: " << m_directions[i].first << " " << m_directions[i].second << std::endl;
            std::cout << "my position now is: " << current.m_pos.first << " " << current.m_pos.second << std::endl;
            Vector2f neighbour = {current.m_pos.first + m_directions[i].first, current.m_pos.second + m_directions[i].second};
            std::cout << "neighbour is: " << neighbour.first << " " << neighbour.second << std::endl;
            std::cout << "is out of map: " << isOutOfBounds(neighbour) << std::endl;
            if (!isOutOfBounds(neighbour))
                std::cout << "is walkable: " << isWalkable(neighbour) << std::endl;


            // If it is not walkable or if it is on the closed list, ignore it. Otherwise do the following.
            if (isOutOfBounds(neighbour) || !isWalkable(neighbour) || std::find(m_closedList.begin(), m_closedList.end(), m_map[neighbour.first][neighbour.second]) != m_closedList.end()) {
                std::cout << "skip" << std::endl;
                continue;
            }
            std::cout << "after" << std::endl;

            // If it isn't on the open list, add it to the open list. Make the current square the parent of this square. Record the F, G, and H costs of the square.
            if (std::find(m_openList.begin(), m_openList.end(), m_map[neighbour.first][neighbour.second]) == m_openList.end())
            {
                m_openList.push_back(m_map[neighbour.first][neighbour.second]);
                m_map[neighbour.first][neighbour.second].m_parent = current.m_pos;
                m_map[neighbour.first][neighbour.second].m_gCost = current.m_gCost + 1;
                m_map[neighbour.first][neighbour.second].m_hCost = heuristic_fct(neighbour, m_end);
                m_map[neighbour.first][neighbour.second].m_fCost = m_map[neighbour.first][neighbour.second].m_gCost + m_map[neighbour.first][neighbour.second].m_hCost;
            }
            // If it is on the open list already, check to see if this path to that square is better, using G cost as the measure. A lower G cost means that this is a better path. If so, change the parent of the square to the current square, and recalculate the G
            // and F scores of the square. If you are keeping your open list sorted by F score, you may need to resort the list to account for the change.
            else
            {
                if (current.m_gCost + 1 < m_map[neighbour.first][neighbour.second].m_gCost)
                {
                    m_map[neighbour.first][neighbour.second].m_parent = current.m_pos;
                    m_map[neighbour.first][neighbour.second].m_gCost = current.m_gCost + 1;
                    m_map[neighbour.first][neighbour.second].m_fCost = m_map[neighbour.first][neighbour.second].m_gCost + m_map[neighbour.first][neighbour.second].m_hCost;
                }
            }
            std::cout << "debug4" << std::endl;

            // d) Stop when you:
            // * Add the target square to the closed list, in which case the path has been found (see note below), or
            if (isFinish(neighbour))
            {
                // Path
                std::vector<Node> path;
                Node current_node = m_map[m_end.first][m_end.second];
                while (current_node.m_parent != m_start)
                {
                    path.push_back(current_node);
                    current_node = m_map[current_node.m_parent.first][current_node.m_parent.second];
                }
                path.push_back(current_node);
                path.push_back(m_map[m_start.first][m_start.second]);
                std::reverse(path.begin(), path.end());
                
                // print path
                for (auto node : path) {
                    std::cout << node.m_pos.first << " " << node.m_pos.second << std::endl;
                }
                return path;
            }
            std::cout << "debug5" << std::endl;
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

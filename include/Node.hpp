/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-04 21:06:10
 * @ Description:
 */


#include <iostream>

using Vector2f = std::pair<int, int>;

struct Node
{
    Node() {};
    Node(Vector2f pos, Vector2f parent, float cost, bool walkable)
        : m_pos(pos), m_parent(parent), m_gCost(cost), m_hCost(cost), m_fCost(cost), isWalkable(walkable)
    {
    }

    Vector2f m_pos;
    Vector2f m_parent;
    float m_gCost;
    float m_hCost;
    float m_fCost;
    bool isWalkable;
};

inline bool operator<(const Node &a, const Node &b)
{
    return a.m_fCost > b.m_fCost;
}
/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-02 18:32:43
 * @ Description:
 */

#pragma once

#include <memory>
#include <vector>

template<typename T, typename V>
class Node
{
    public:
        Node(T map, V pos) : m_map(map), m_pos(pos) {};
        ~Node() = default;

        void setParent(std::shared_ptr<Node<T, V>> parent);
        void setGCost(int gCost);
        void setHCost(int hCost);
        void setFCost(int fCost);
        void setPos(V pos);
        void setMap(T map);

        std::shared_ptr<Node<T, V>> getParent() const;
        int getGCost() const;
        int getHCost() const;
        int getFCost() const;
        V getPos() const;
        T getMap() const;

        bool operator==(const Node<T, V>& other) const;
        bool operator!=(const Node<T, V>& other) const;

    private:
        std::shared_ptr<Node<T, V>> m_parent;
        int m_gCost;
        int m_hCost;
        int m_fCost;
        V m_pos;
        T m_map;
};
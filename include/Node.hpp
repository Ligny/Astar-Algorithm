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
        Node(V pos, T& w);
        Node(const Node& other);
        Node(Node&& other);

        Node& operator=(Node&& other);
        Node& operator=(const Node& other);

        float m_f;
        float m_g;
        float m_h;

        V m_pos;

    private:
        
        
        std::shared_ptr<Node> m_parent;
};
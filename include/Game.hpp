/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:17:30
 * @ Description:
 */

#pragma once

#include "iostream"
#include "string"

#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "Astar.hpp"

class Game
{
    public:
        Game(int width, int height, const std::string& title, std::uint16_t tileSize);

        void run(sf::Vector2f start, sf::Vector2f target);
    
    private:
        void display();
        void event();

        void mouseEvent();
        void keyEvent(sf::Keyboard::Key& key);

        sf::RenderWindow m_window;
        Map m_map;
};
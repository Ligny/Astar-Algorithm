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
#include "Button.hpp"

class Game
{
    public:
        Game(int width, int height, const std::string& title, std::uint16_t tileSize);

        void run(sf::Vector2f start, sf::Vector2f target);
    
    private:
        void display();

        void event();
        void mouseEvent();
        void launchAlgorithm();
        void keyEvent(sf::Keyboard::Key& key);

        void setUp(sf::Vector2f start, sf::Vector2f target);

        std::vector<std::vector<Node>> makeProtoMap(const int width, const int height);

        sf::RenderWindow m_window;
        Map m_map;

        sf::Font m_font;
        std::vector<Button> m_buttons;
        bool m_isDiagonal;
};
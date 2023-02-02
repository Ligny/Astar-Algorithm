/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:17:23
 * @ Description:
 */

#include "../include/Game.hpp"
#include <iostream>

Game::Game(int width, int height, const std::string& title, std::uint16_t tileSize)
    : m_window(sf::VideoMode(width, height), title),
    m_map(Map({width, height}, tileSize)),
    m_astar()
{
}

void Game::run(sf::Vector2f start, sf::Vector2f target)
{
    m_map.setStart(start, sf::Color::Green);
    m_map.setTarget(target, sf::Color::Red);
    while (m_window.isOpen()) {
        event();
        display();
    }
}

void Game::display()
{
    m_window.clear();
    m_window.draw(m_map);
    m_window.display();
}

void Game::mouseEvent()
{
    auto position = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosition(position.x, position.y);

    auto tile = m_map[mousePosition];
    if (tile.getColor() == sf::Color::White) {
        tile.setColor(sf::Color::Black);
        m_map[mousePosition] = tile;
    } else if (tile.getColor() == sf::Color::Black) {
        tile.setColor(sf::Color::White);
        m_map[mousePosition] = tile;
    }
}

void Game::keyEvent(sf::Keyboard::Key& key)
{
    auto position = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosition(position.x, position.y);

    if (key == sf::Keyboard::S) {
        m_map.setStart(mousePosition, sf::Color::Green);
    } else if (key == sf::Keyboard::T) {
        m_map.setTarget(mousePosition, sf::Color::Red);
    } else if (key == sf::Keyboard::Enter) {
        m_astar.findPath(
            m_map.getProtoMap(),
            {m_map.getStart().getPosition().y / m_map.getTileSize(), m_map.getStart().getPosition().x / m_map.getTileSize()},
            {m_map.getTarget().getPosition().y / m_map.getTileSize(), m_map.getTarget().getPosition().x / m_map.getTileSize()});
    }
}

void Game::event()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            mouseEvent();
        } else if (event.type == sf::Event::KeyPressed) {
            keyEvent(event.key.code);
        }
    }
}
/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:17:23
 * @ Description:
 */

#include "../../include/Game.hpp"
#include <SFML/Window.hpp>

Game::Game(int width, int height, const std::string& title, std::uint16_t tileSize)
    : m_window(sf::VideoMode((width * tileSize) + 300, height * tileSize), title),
    m_map(Map({width, height}, tileSize))
{
};

void Game::setUp(sf::Vector2f start, sf::Vector2f target)
{
    m_map.setStart(start, sf::Color::Green);
    m_map.setTarget(target, sf::Color::Red);

    if (!m_font.loadFromFile("Sansation.ttf"))
        std::cout << "Error loading font" << std::endl;
    sf::Text temp_text = sf::Text(" - Diagonal", m_font);
    temp_text.setPosition((m_map.getWidth() * m_map.getTileSize()) + 100, 70);
    m_activateTexts.push_back(ActivateText(temp_text, true));
}

void Game::run(sf::Vector2f start, sf::Vector2f target)
{
    setUp(start, target);
    while (m_window.isOpen()) {
        event();
        display();
    }
}

void Game::display()
{
    m_window.clear();
    m_window.draw(m_map);
    m_window.draw(m_activateTexts[0]);
    m_window.display();
}

void Game::mouseEvent()
{
    auto position = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosition{(float)position.x / m_map.getTileSize(), (float)position.y / m_map.getTileSize()};

    auto tile = m_map[mousePosition];
    if (tile.getColor() == sf::Color::White) {
        tile.setColor(sf::Color::Black);
        m_map[mousePosition] = tile;
    } else if (tile.getColor() == sf::Color::Black) {
        tile.setColor(sf::Color::White);
        m_map[mousePosition] = tile;
    }
}

std::vector<std::vector<Node>> getProtoMap(const int width, const int height, const int tileSize)
{
    auto rHeight = height / tileSize;
    auto rWidth = width / tileSize;
    std::vector<std::vector<Node>> map;
    for (auto y = 0; y < rHeight; y++) {
        std::vector<Node> row;
        for (auto x = 0; x < rWidth; x++) {
            row.push_back(Node({x, y}, {-1, -1}, __FLT_MAX__, true));
        }
        map.push_back(row);
    }
    return map;
}

void Game::keyEvent(sf::Keyboard::Key& key)
{
    auto position = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosition{(float)position.x / m_map.getTileSize(), (float)position.y / m_map.getTileSize()};

    if (key == sf::Keyboard::S) {
        m_map.setStart(mousePosition, sf::Color::Green);
    } else if (key == sf::Keyboard::T) {
        m_map.setTarget(mousePosition, sf::Color::Red);
    } else if (key == sf::Keyboard::Enter) {
        std::cout << m_map.getStart().getPosition().x / m_map.getTileSize() << " " << m_map.getStart().getPosition().y / m_map.getTileSize() << std::endl;
        Astar astar(
            getProtoMap(m_map.getWidth(), m_map.getHeight(), m_map.getTileSize()),
            {m_map.getStart().getPosition().x / m_map.getTileSize(), m_map.getStart().getPosition().y / m_map.getTileSize()},
            {m_map.getTarget().getPosition().x / m_map.getTileSize(), m_map.getTarget().getPosition().y / m_map.getTileSize()},
            {m_map.getWidth() / m_map.getTileSize(), m_map.getHeight() / m_map.getTileSize()}
        );
        auto res = astar.findPath(4);
        if (res.empty()) {
            std::cout << "Path not found" << std::endl;
        } else {
            std::cout << "Path found" << std::endl;
            for (auto& node : res) {
                std::cout << node.m_pos.first << " " << node.m_pos.second << std::endl;
            }
        }
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
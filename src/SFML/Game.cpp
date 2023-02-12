/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:17:23
 * @ Description:
 */

#include "../../include/Game.hpp"
#include <SFML/Window.hpp>

Game::Game(int width, int height, const std::string& title, std::uint16_t tileSize)
    : m_window(sf::VideoMode((width * tileSize) + 300, height * tileSize), title),
    m_map(Map({width, height}, tileSize)),
    m_isDiagonal(false)
{
};

void Game::setUp(sf::Vector2f start, sf::Vector2f target)
{
    m_map.setStart(start, sf::Color::Green);
    m_map.setTarget(target, sf::Color::Red);

    if (!m_font.loadFromFile("ressources/Sansation.ttf"))
        std::cout << "Error loading font" << std::endl;

    m_buttons.push_back(Button(sf::Text("Diagonal", m_font), {(int)(m_map.getWidth() * m_map.getTileSize()) + 75, 70}, button_type_t::DIAGONAL));
    m_buttons.push_back(Button(sf::Text("Start", m_font), {(int)(m_map.getWidth() * m_map.getTileSize()) + 75, 350}, button_type_t::START));
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
    std::string pos = "Start\nx: " + std::to_string((int)m_map.getStart().getPosition().x / m_map.getTileSize()) + " y: " + std::to_string((int)m_map.getStart().getPosition().y / m_map.getTileSize());
    sf::Text tot(pos, m_font);
    tot.setFillColor(sf::Color::Green);
    tot.setPosition((m_map.getWidth() * m_map.getTileSize()) + 50, 500);
    std::string pos1 = "Target\nx: " + std::to_string((int)m_map.getTarget().getPosition().x / m_map.getTileSize()) + " y: " + std::to_string((int)m_map.getTarget().getPosition().y / m_map.getTileSize());
    sf::Text tat(pos1, m_font);
    tat.setFillColor(sf::Color::Red);
    tat.setPosition((m_map.getWidth() * m_map.getTileSize()) + 50, 600);
    m_window.draw(tot);
    m_window.draw(tat);
    for (auto& button : m_buttons)
        m_window.draw(button);
    m_window.display();
}

void Game::launchAlgorithm()
{
    Astar astar(
        makeProtoMap(m_map.getWidth(), m_map.getHeight()),
        {m_map.getStart().getPosition().x / m_map.getTileSize(), m_map.getStart().getPosition().y / m_map.getTileSize()},
        {m_map.getTarget().getPosition().x / m_map.getTileSize(), m_map.getTarget().getPosition().y / m_map.getTileSize()},
        {m_map.getWidth(), m_map.getHeight()}
    );
    auto res = astar.findPath((m_isDiagonal) ? 8 : 4);
    if (res.empty()) {
        std::cout << "Path not found" << std::endl;
    } else {
        std::cout << "Path found" << std::endl;
        for (auto& node : res) {
            std::cout << node.m_pos.first << " " << node.m_pos.second << std::endl;
        }
    }
}

void Game::mouseEvent()
{
    auto position = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosition{(float)position.x / m_map.getTileSize(), (float)position.y / m_map.getTileSize()};

    for (auto& button : m_buttons) {
        if (button.isInBounds((sf::Vector2f)position)) {
            button.setActive(!button.getActive());
        } if (button.getType() == button_type_t::START && button.getActive()) {
            button.setString("Reset");
            button.setType(button_type_t::RESET);
            launchAlgorithm();
        } if (button.getType() == button_type_t::RESET && !button.getActive()) {
            button.setString("Start");
            button.setType(button_type_t::START);
        } if (button.getType() == button_type_t::DIAGONAL)
            m_isDiagonal = button.getActive();
    }
    auto tile = m_map[mousePosition];
    if (tile.getColor() == sf::Color::White && m_map.isInMap(mousePosition)) {
        tile.setColor(sf::Color::Black);
        m_map[mousePosition] = tile;
    } else if (tile.getColor() == sf::Color::Black && m_map.isInMap(mousePosition)) {
        tile.setColor(sf::Color::White);
        m_map[mousePosition] = tile;
    }
}

std::vector<std::vector<Node>> Game::makeProtoMap(const int width, const int height)
{
    std::vector<std::vector<Node>> map;
    for (auto y = 0; y < height; y++) {
        std::vector<Node> row;
        for (auto x = 0; x < width; x++) {
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

    if (key == sf::Keyboard::S && m_map.isInMap(mousePosition))
        m_map.setStart(mousePosition, sf::Color::Green);
    else if (key == sf::Keyboard::T && m_map.isInMap(mousePosition))
        m_map.setTarget(mousePosition, sf::Color::Red);
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
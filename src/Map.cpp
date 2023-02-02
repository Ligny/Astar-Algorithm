/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:36:02
 * @ Description:
 */

#include "../include/Map.hpp"

Map::Map(std::pair<std::uint32_t, std::uint32_t> size, std::uint16_t tileSize)
    : m_width(size.first),
    m_height(size.second),
    m_tileSize(tileSize)
{
    for (auto y = 0; y <= m_height; y += m_tileSize) {
        for (auto x = 0; x < m_width; x += m_tileSize) {
            m_tileMap.push_back(Tile(sf::IntRect(x, y, m_tileSize, m_tileSize), sf::Color::White));
        }
    }
}

Map::Map(const Map& map) = default;

Map& Map::operator=(const Map& other) = default;

Tile& Map::operator[](sf::Vector2f position)
{
    return m_tileMap[indexAt(position)];
}

const Tile& Map::operator[](sf::Vector2f position) const
{
    return m_tileMap[indexAt(position)];
}

inline int Map::indexAt(sf::Vector2f position) const
{
    auto positionX = static_cast<int>(position.x);
    auto positionY = static_cast<int>(position.y);

    positionX = (positionX - (positionX % m_tileSize)) / m_tileSize;
    positionY = (positionY - (positionY % m_tileSize)) / m_tileSize;

    return (positionY*(m_width / m_tileSize) + positionX);
}

void Map::setStart(sf::Vector2f position, sf::Color color)
{
    for (auto& tile : m_tileMap)
        if (tile.getColor() == color)
            tile.setColor(sf::Color::White);
    auto tile = m_tileMap[indexAt(position)];
    tile.setColor(color);
    m_start = tile;
    (*this)[m_start.getPosition()] = m_start;
}

void Map::setTarget(sf::Vector2f position, sf::Color color)
{
    for (auto& tile : m_tileMap)
        if (tile.getColor() == color)
            tile.setColor(sf::Color::White);
    auto tile = m_tileMap[indexAt(position)];
    tile.setColor(color);
    m_target = tile;
    (*this)[m_target.getPosition()] = m_target;
}

Tile& Map::getStart()
{
    return m_start;
}

Tile& Map::getTarget()
{
    return m_target;
}

std::vector<std::vector<char>> &Map::getProtoMap()
{
    m_protoMap.clear();

    for (auto y = 0; y < m_height; y += m_tileSize) {
        std::vector<char> line;
        for (auto x = 0; x < m_width; x += m_tileSize) {
            auto tile = m_tileMap[indexAt(sf::Vector2f(x, y))];
            if (tile.getColor() == sf::Color::White)
                line.push_back(CASE);
            else
                line.push_back(BLOCK);
        }
        m_protoMap.push_back(line);
    }
    return m_protoMap;
}

std::uint16_t Map::getTileSize() const
{
    return m_tileSize;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& tile : m_tileMap)
        target.draw(tile);
}
/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:36:02
 * @ Description:
 */

#include "../../include/Map.hpp"
#include <math.h>


Map::Map(std::pair<std::uint32_t, std::uint32_t> size, std::uint16_t tileSize)
    : m_width(size.first),
    m_height(size.second),
    m_tileSize(tileSize)
{
    for (auto y = 0; y <= m_height; y++) {
        for (auto x = 0; x < m_width; x++) {
            m_tileMap.push_back(Tile(sf::IntRect(x * m_tileSize, y * m_tileSize, m_tileSize, m_tileSize), sf::Color::White));
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
    return (trunc(position.y) * m_width) + trunc(position.x);
}

void Map::clear(sf::Color color, bool partial)
{
    for (auto& tile : m_tileMap)
        if (partial && tile.getColor() == color)
            tile.setColor(sf::Color::White);
        else if (!partial)
            tile.setColor(sf::Color::White);
}

void Map::setStart(sf::Vector2f position, sf::Color color)
{
    clear(color, true);
    auto tile = m_tileMap[indexAt(position)];
    tile.setColor(color);
    m_start = tile;
    (*this)[position] = m_start;
}

void Map::setTarget(sf::Vector2f position, sf::Color color)
{
    clear(color, true);
    auto tile = m_tileMap[indexAt(position)];
    tile.setColor(color);
    m_target = tile;
    (*this)[position] = m_target;
}

Tile& Map::getStart()
{
    return m_start;
}

Tile& Map::getTarget()
{
    return m_target;
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

std::uint32_t Map::getWidth() const
{
    return m_width;
}

std::uint32_t Map::getHeight() const
{
    return m_height;
}
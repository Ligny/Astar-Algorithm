/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:49:36
 * @ Description:
 */

#include "../include/Tile.hpp"

Tile::Tile() = default;

Tile::Tile(sf::IntRect rect, sf::Color color)
    : m_shape(sf::Vector2f(rect.width, rect.height))
{
    m_shape.setFillColor(color);
    setPosition(rect.left, rect.top);
    m_shape.setOutlineColor(sf::Color(160,160,160));
    m_shape.setOutlineThickness(.6f);
}

void Tile::setColor(sf::Color color)
{
    m_shape.setFillColor(color);
}

sf::Color Tile::getColor() const
{
    return m_shape.getFillColor();
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(m_shape, states);
}
/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-13 23:42:30
 * @ Description:
 */

#include "../../../include/TextData.hpp"
#include <iostream>

TextData::TextData(sf::Text text, sf::Vector2i pos, sf::Color color) : m_text(text)
{
    m_text.setPosition({(float)pos.x, (float)pos.y});
    m_text.setFillColor(color);
}

void TextData::setString(std::string text)
{
    m_text.setString(text);
}

void TextData::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}
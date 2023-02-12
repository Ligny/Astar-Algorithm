/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-07 23:22:39
 * @ Description:
 */

#include "../../include/Button.hpp"
#include <iostream>

Button::Button(sf::Text text, sf::Vector2i pos, button_type_t type)
    : m_active(false), m_text(text)
{
    m_text.setPosition(pos.x, pos.y);
    m_text.setStyle(sf::Text::Bold);
    m_rect = sf::RectangleShape(sf::Vector2f(m_text.getGlobalBounds().width + 50, m_text.getGlobalBounds().height + 50));
    m_rect.setPosition({m_text.getPosition().x - 25, m_text.getPosition().y - 25});
    m_rect.setOutlineThickness(1.6f);
    setActive(false);
}

bool Button::isInBounds(sf::Vector2f position) const
{
    return m_rect.getGlobalBounds().contains(position);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rect, states);
    target.draw(m_text, states);
}

void Button::setActive(bool active)
{
    if (active) {
        m_rect.setFillColor(sf::Color::White);
        m_rect.setOutlineColor(sf::Color::Black);
        m_text.setFillColor(sf::Color::Black);
    } else {
        m_rect.setFillColor(sf::Color::Black);
        m_rect.setOutlineColor(sf::Color::White);
        m_text.setFillColor(sf::Color::White);
    }
    m_active = active;
}

bool Button::getActive() const
{
    return m_active;
}
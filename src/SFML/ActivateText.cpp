/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-07 23:22:39
 * @ Description:
 */

#include "../../include/ActivateText.hpp"
#include <iostream>

ActivateText::ActivateText(sf::Text text, bool active)
    : m_active(active), m_text(text)
{
    m_rect = sf::RectangleShape(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 10));
    m_rect.setPosition(m_text.getPosition());
    m_rect.setFillColor(sf::Color::Black);
    m_rect.setOutlineColor(sf::Color::White);
    m_rect.setOutlineThickness(1.6f);
    setActive(true);
}

void ActivateText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rect, states);
    target.draw(m_text, states);
}

void ActivateText::setActive(bool active)
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
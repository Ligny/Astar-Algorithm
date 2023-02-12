/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-07 18:40:22
 * @ Description:
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
    typedef enum button_type {
        DIAGONAL,
        START,
        RESET,
    } button_type_t;

    public:
        explicit Button(sf::Text text, sf::Vector2i pos, button_type_t type);
        Button() = default;

        void setActive(bool active);
        bool getActive() const;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        bool isInBounds(sf::Vector2f position) const;

    private:
        sf::Text m_text;
        bool m_active;
        sf::Font m_font;
        sf::RectangleShape m_rect;
};
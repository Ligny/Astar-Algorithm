/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-07 18:40:22
 * @ Description:
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class ActivateText : public sf::Drawable, public sf::Transformable
{
    public:
        explicit ActivateText(sf::Text text, bool active);
        ActivateText() = default;

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
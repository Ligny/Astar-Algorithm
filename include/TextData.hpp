/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-13 23:43:17
 * @ Description:
 */

#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class TextData : public sf::Drawable, public sf::Transformable
{
    public:
        explicit TextData(sf::Text text, sf::Vector2i pos, sf::Color color);
        TextData() = default;

        void setString(std::string text);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Text m_text;
};
/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:50:13
 * @ Description:
 */

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "SFML/Graphics/RenderWindow.hpp"

class Tile : public sf::Drawable, public sf::Transformable
{
    public:
        explicit Tile(sf::IntRect rect, sf::Color color);
        Tile();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setColor(sf::Color color);
        sf::Color getColor() const;

    private:
        sf::RectangleShape m_shape;
        sf::Color m_color;
    };
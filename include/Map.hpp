/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:36:12
 * @ Description:
 */

#pragma once

#include "iostream"
#include "array"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Tile.hpp"

class Map : public sf::Drawable
{
    public:
        Map();
        Map(const Map& map);
        Map(std::pair<std::uint32_t, std::uint32_t> size, std::uint16_t tileSize);

        void setStart(sf::Vector2f position, sf::Color color);
        void setTarget(sf::Vector2f position, sf::Color color);
        Tile &getStart();
        Tile &getTarget();
        std::uint16_t getTileSize() const;
        std::uint32_t getWidth() const;
        std::uint32_t getHeight() const;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        Map& operator=(const Map& other);
        Tile& operator[](sf::Vector2f position);
        const Tile& operator[](sf::Vector2f position) const;

    private:
        inline int indexAt(sf::Vector2f position) const;
        void clear(sf::Color color, bool partial = false);

        std::uint32_t m_width;
        std::uint32_t m_height;
        std::uint16_t m_tileSize;

        std::vector<Tile> m_tileMap;
        Tile m_start;
        Tile m_target;
};
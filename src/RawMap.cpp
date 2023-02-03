/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-03 17:17:09
 * @ Description:
 */

#include "../include/RawMap.hpp"

RawMap::RawMap(ProtoMap map) : m_map(map) {};

ProtoMap RawMap::getMap() const
{
    return m_map;
}
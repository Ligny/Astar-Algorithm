/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-02-03 16:58:20
 * @ Description:
 */

#pragma once

#include <string>
#include <vector>

using ProtoMap = std::vector<std::vector<char>>;
using Vector2f = std::pair<int, int>;

class RawMap
{
    private:
        ProtoMap m_map;

    public:
        RawMap(ProtoMap map);
        ~RawMap() = default;

        ProtoMap getMap() const;
};

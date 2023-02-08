/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:14:43
 * @ Description:
 */

#include "../include/Game.hpp"

int main(int argc, char *argv[])
{
    try {
        Game game(32, 18, "SFML window", 40);
        game.run({0, 0}, {0, 3});
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
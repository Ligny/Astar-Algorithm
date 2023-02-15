/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-01-28 14:14:43
 * @ Description:
 */

#include "../include/Game.hpp"

std::pair<int, int> error_handling(int arg1, int arg2)
{
    if (arg1 == 0 || arg2 == 0)
        throw;
    return std::pair<int, int>(arg1, arg2);
}

int main(int argc, char *argv[])
{
    try {
        if (argc == 1) {
            Game game(32, 18, "Astar", 40);
            game.run({0, 0}, {12, 15});
        } else if (argc == 3) {
            auto args = error_handling(atoi(argv[1]), atoi(argv[2]));
            Game game(args.first, args.second, "Astar", 40);
            game.run({0, 0}, {1, 0});
        } else
            throw;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cout << "ERROR: Please read the README" << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
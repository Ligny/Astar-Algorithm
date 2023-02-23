# A-star

This project is a simple graphics **A-star** search algorithm implementation.

## Description

A*, A-star or Astar is a pathfinding algorithm that find the shortest path between two points.

A-star algorithm is one of the best pathfinding algorithm, it can be seen as an extension of Dijkstra's algorithm by using heuristics to guide its search.

* [A* search algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm)
* [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

The heuristic function is used to estimate the cost to reach the goal from node n.

For this project, the Euclidean and Manhattan distances have been implemented.
> Euclidean: d = √[(x2 – x1)^2 + (y2 – y1)^2]

> Manhattan: d = (x2 - x1) + (y2 - y1)

* [Euclidean Distance](https://en.wikipedia.org/wiki/Euclidean_distance)
* [Manhattan Distance](https://en.wikipedia.org/wiki/Taxicab_geometry)

In my version of the Astar algorithm, I let you decide if you allow diagonals.
> 4 directions: North, East, South, West

> 8 directions: North, North East, East, South East, South, South West, West, North West

## Getting Started

### Dependencies

* [c++17](https://en.cppreference.com/w/cpp/17)
* [SFML](https://www.sfml-dev.org/download.php)

### Executing program



![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)


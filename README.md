# A-star

This project is a simple graphics **A-star** search algorithm implementation.

![This is an image](https://github.com/Ligny/A-star/blob/main/ressources/images/Astar_menu.png)

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

## Architecture

this repository is divided into two folders, the graphic and algorithmic part which are independent of each other.

[Algorithmic](src/algorithm)

[Graphic SFML](src/SFML)

## Getting Started

### Dependencies

* [c++17](https://en.cppreference.com/w/cpp/17)
* [SFML](https://www.sfml-dev.org/download.php)

### Executing program

1. **Compile all cpp files with Makefile:**
> create `astar` executable
````
make
````
2. **Launch:**
> launch Astar Window with default 32 18 **Grid size**
````
./astar
````
> launch Astar Window with x y **Grid size**
````
./astar x y
````

## How to use

### On Grid

Set **BLOCK**: click on Tile

Set new **START**: press key ``s`` on the new start tile
> Default start `x = 0, y = 0`

Set new **TARGET**: press key ``t`` on the new target tile
> Default target `x = 12,  y = 15` or with args `x = 1, y = 0`

### Button

**Diagonal**: set diagonal
> Default `Diagonal = false`

**Manhattan/Euclidian**: set heuristic function
> Default `Euclidian`

**Start/Reset**: Start Algorithm

![This is an image](https://github.com/Ligny/A-star/blob/main/ressources/images/Astar_manhattan.png)

## Help

### Makefile Error

#### SFML Error
> [here](#dependencies)

#### Other
Also exist rules: `make re`, `make clean`, `make fclean`
> `make re`    : recompile (make fclean + make)<br />
> `make clean` : delete *.o<br />
> `make fclean`: delete *.o && executable<br />

### Execution Error

#### Arguments Error
````
❯ ERROR: Please read the README
````
> [here](#executing-program)

##
![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)

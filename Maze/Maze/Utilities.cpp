//
//  Utilities.cpp
//  Maze
//
//  Created by Adam Saher on 22/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <stdio.h>
#include "Maze.hpp"
bool can_move_up(const Maze&, const Coord&);

int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[]){
    if (start == end) {
        path[0] = start;
        return 1;
    }
    if (can_move_up(theMaze, start)) {
        return findPath(theMaze, Coord(start.x, start.y + 1), end, path);
    }
    return 0;
    
    
}


bool can_move_up(const Maze& maze, const Coord& point) {
    return point.y + 1 < maze.height();
}

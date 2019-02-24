//
//  Utilities.cpp
//  Maze
//
//  Created by Adam Saher on 22/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <stdio.h>
#include "Maze.hpp"


int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[]){
    if (start.x >= theMaze.width() || start.x < 0 || start.y >= theMaze.height() || start.y < 0)
        return 0;
    
    if (end.x >= theMaze.width() || end.x < 0 || end.y >= theMaze.height() || end.y < 0)
        return 0;
    
    if (theMaze.isWall(start) || theMaze.isWall(end))
        return 0;
    
    if (start == end) {
        theMaze.mark(start);
        path[0] = start;
        return 1;
    }
    
    if (start.y + 1 < theMaze.height()) {
        return findPath(theMaze, Coord(start.x, start.y + 1), end, path);
    }
    
    if (start.y - 1 >= 0) {
        return findPath(theMaze, Coord(start.x, start.y - 1), end, path);
    }
    
    if (start.x + 1 < theMaze.width()) {
        return findPath(theMaze, Coord(start.x + 1, start.y), end, path);
    }
    
    if (start.x - 1 >= 0) {
        return findPath(theMaze, Coord(start.x - 1, start.y), end, path);
    }
    
    return 0;
}


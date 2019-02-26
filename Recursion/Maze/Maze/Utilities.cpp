//
//  Utilities.cpp
//  Maze
//
//  Created by Adam Saher on 22/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Maze.hpp"



int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[]){
    //if start is out of bounds, return false
    if (start.x < 0 || start.x >= theMaze.width() || start.y < 0 || start.y >= theMaze.height())
        return 0;
    
    //if end is out of bounds, return false
    if (end.x < 0 || end.x >= theMaze.width() || end.y < 0 || end.y >= theMaze.height())
        return 0;
    
    //if start or end are not empty (like a wall or marked) return false
    if (!(theMaze.isEmpty(start) && theMaze.isEmpty(end)))
        return 0;
    
    if (start == end) {
        theMaze.mark(start);
        path[0] = start;
        return 1;
    }
    
    theMaze.mark(start);
    path[0] = start;
    
    //If there is a node up, try to get the path from there to the end, and append that path to the path array
    if (start.y + 1 < theMaze.height() ) {
        if(auto path_len = findPath(theMaze, Coord(start.x, start.y + 1), end, path + 1))
            return path_len + 1;
    }
    
    //If there is a node down, try to get the path from there to the end, and append that path to the path array
    if (start.y - 1 >= 0 ) {
        if (auto path_len = findPath(theMaze, Coord(start.x, start.y - 1), end, path + 1))
            return path_len + 1;
    }
    
    //    //If there is a node right, try to get the path from there to the end, and append that path to the path array
    if (start.x + 1 < theMaze.width() ) {
        if (auto path_len = findPath(theMaze, Coord(start.x + 1, start.y), end, path + 1))
            return path_len + 1;
    }
    
    //If there is a node left, try to get the path from there to the end, and append that path to the path array
    if (start.x - 1 >= 0) {
        if (auto path_len = findPath(theMaze, Coord(start.x - 1, start.y), end, path + 1))
            return path_len + 1;
    }
    //unmark everything if you don't find a path
    theMaze.unMark(start);
    
    return 0;
}


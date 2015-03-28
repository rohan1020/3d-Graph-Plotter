//
//  SceneStateData.cpp
//  graph3d
//
//  Created by Rohan Raja on 26/03/15.
//
//

#include "SceneStateData.h"

SceneStateData::SceneStateData(){
    
    
}

SceneStateData::SceneStateData(const SceneStateData &p2){
    
    cubes = p2.cubes;
    
}

SceneStateData SceneStateData::operator+(SceneStateData csd)
{
    
    SceneStateData toReturn = csd;
    toReturn.cubes.insert(toReturn.cubes.end(), cubes.begin(), cubes.end());
    
    return toReturn;
    
}
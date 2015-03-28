//
//  SceneStateData.h
//  graph3d
//
//  Created by Rohan Raja on 26/03/15.
//
//

#ifndef __graph3d__SceneStateData__
#define __graph3d__SceneStateData__

#include <stdio.h>
#include "RCube.h"
#include <vector>

using namespace std;

class SceneStateData {
    
    
public:
    
    vector<RCube> cubes;
    
    SceneStateData();
    
    SceneStateData(const SceneStateData &p2);
    
    SceneStateData operator+(SceneStateData csd);
};

#endif /* defined(__graph3d__SceneStateData__) */

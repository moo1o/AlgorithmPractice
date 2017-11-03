//
//  1526.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 9. 13..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int standary[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

struct puzzle{
    int ary[3][3];
    int dist = 0;
    int zeroX, zeroY;
    bool check = false;
};


bool check (puzzle a){
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(a.ary[i][j] != standary[i][j])
                return false;
        }
    }
    return true;
}

int main(void){
    puzzle a;
    queue<puzzle> q;
    
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j < 3 ; j++){
            cin >> a.ary[i][j];
            if(a.ary[i][j] == 0){
                a.zeroX = i;
                a.zeroY = j;
            }

        }
    }

    a.dist = 0;
    a.check = true;
    q.push(a);
    
    while(!q.empty()){
        puzzle now = q.front();
        q.pop();
        
        
    }
    
    
    
    
    return 0;
}

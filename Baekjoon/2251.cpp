//
//  2251.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 9. 19..
//  Copyright © 2017년 김무열. All rights reserved.
//

// 2251 순열 풀이(물통의 크기가 오름차순이 아니므로 실패)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int ary[3];
    int a, b, c;
    vector<int> ans;
    queue<int*> q;
    
    cin >> a >> b >> c;

    ary[0] = 0;
    ary[1] = 0;
    ary[2] = c;
    
    ans.push_back(ary[2]);
    
    vector<int> tmp(3);
    for(int y=0 ; y<=b ; y++){
        for(int z=0 ; z<c ; z++){
            tmp[0] = 0;
            tmp[1] = y;
            tmp[2] = z;
            if(y+z == c && (y== a || y == b || y == c|| z==a || z==b || z == c)){
                ans.push_back(z);
            }
        }
    }
    

    sort(ans.begin(), ans.end());
    
    for(int i =0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}

//
//  2251queue.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 9. 19..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
bool check[201][201];
bool ans[201];

int main(void){
    int a, b, c;
    cin >> a >> b >>c;
    int sum = c;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    ans[c] = true;
    
    while(!q.empty()){
        
        
    }
    
    
    return 0;
}

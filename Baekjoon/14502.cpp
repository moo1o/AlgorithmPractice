//
//  14502.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 10. 17..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<vector<int>> &map, int n, int m){
    int cnt = 0;
    vector<vector<int>> tmp(n, vector<int>(m));
    do{
        tmp.clear();
        tmp.assign(map.begin(), map.end());
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(map[i][j] == 2){
                    if(i-1 >= 0 && map[i-1][j] == 0){
                        map[i-1][j] = 2;
                    }
                    if(j-1 >= 0 && map[i][j-1] == 0){
                        map[i][j-1] = 2;
                    }
                    if(i+1 < n && map[i+1][j] == 0){
                        map[i+1][j] = 2;
                    }
                    if(j+1 >= 0 && map[i][j+1] == 0){
                        map[i][j+1] = 2;
                    }
                }
            }
        }
    }while(tmp != map);
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(map[i][j] == 0){
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main(void){
    int n, m, ans=0;
    cin >> n >> m;
    
    vector<pair<int, int>> loc;
    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            loc.push_back(make_pair(i, j));
            cin >> map[i][j];
        }
    }
    
    for(int i=0 ; i<loc.size()-2 ; i++){
        for(int j=i+1 ; j<loc.size()-1 ; j++){
            for(int k=j+1 ; k<loc.size() ; k++){
                vector<vector<int>> tmp(n, vector<int>(m));
                tmp.clear();
                tmp.assign(map.begin(), map.end());
                if(tmp[loc[i].first][loc[i].second] == 0 &&
                   tmp[loc[j].first][loc[j].second] == 0 &&
                   tmp[loc[k].first][loc[k].second] == 0){
                    tmp[loc[i].first][loc[i].second] = 1;
                    tmp[loc[j].first][loc[j].second] = 1;
                    tmp[loc[k].first][loc[k].second] = 1;
                    int cnt = func(tmp, n, m);
                    if(ans < cnt){
                        ans = cnt;
                    }
                }
            }
        }
    }
    
    cout << ans << endl; 
    
    return 0;
}

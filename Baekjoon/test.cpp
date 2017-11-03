//
//  12100.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 10. 25..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int ans;

void findans(vector<vector<int>> board){
    for(int i=0 ; i<board.size() ; i++){
        for(int j=0 ; j<board.size() ; j++){
            if(board[i][j] > ans){
                ans = board[i][j];
            }
        }
    }
}

void func(vector<vector<int>> board){
    int cnt=0;
    queue<vector<vector<int>>> q;
    q.push(board);
    
    while(cnt < 1024){
        cnt++;
        vector<vector<int>> now = q.front();
        
        //상
        for(int j=0 ; j<board.size() ; j++){
            for(int i=0 ; i<board.size() ; i+=2){
                if(i+1 < board.size() && now[i][j] == now[i+1][j]){
                    now[i][j] += now[i+1][j];
                    now[i+1][j] = 0;
                }
                int t=i;
                while(t-1 > -1 &&  now[t-1][j] == 0){
                    now[t-1][j] = now[t][j];
                    now[t][j] = 0;
                    t--;
                }
            }
        }
        q.push(now);
        
        if(cnt > 254){
            findans(now);
        }
        
        //하
        now = q.front();
        for(int j=0 ; j<board.size() ; j++){
            for(int i=(int)board.size()-1 ; i>-1 ; i-=2){
                if(i-1 > -1 && now[i][j] == now[i-1][j]){
                    now[i][j] += now[i-1][j];
                    now[i-1][j] = 0;
                }
                int t=i;
                while(t+1 < board.size() &&  now[t+1][j] == 0){
                    now[t+1][j] = now[t][j];
                    now[t][j] = 0;
                    t++;
                }
            }
        }
        q.push(now);
        
        if(cnt > 254){
            findans(now);
        }
        
        //좌
        now = q.front();
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board.size() ; j+=2){
                if(j+1 < board.size() && now[i][j] == now[i][j+1]){
                    now[i][j] += now[i][j+1];
                    now[i][j+1] = 0;
                }
                int t=j;
                while(t-1 > -1 &&  now[i][t-1] == 0){
                    now[i][t-1] = now[i][t];
                    now[i][t] = 0;
                    t--;
                }
            }
        }
        q.push(now);
        
        if(cnt > 254){
            findans(now);
        }
        
        //우
        now = q.front();
        for(int i=0 ; i<board.size() ; i++){
            for(int j=(int)board.size()-1 ; j>-1 ; j-=2){
                if(j-1 > -1 && now[i][j] == now[i][j-1]){
                    now[i][j] += now[i][j-1];
                    now[i][j-1] = 0;
                }
                int t=j;
                while(t+1 < board.size() &&  now[i][t+1] == 0){
                    now[i][t+1] = now[i][t];
                    now[i][t] = 0;
                    t++;
                }
            }
        }
        q.push(now);
        
        if(cnt > 254){
            findans(now);
        }
        
        q.pop();
    }
    
}

int main(void){
    int n;
    cin >> n;
    vector <vector <int>> board(n, vector <int>(n));
    
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> board[i][j];
        }
    }
    
    func(board);
    
    cout << ans << endl;
    
    return 0;
}

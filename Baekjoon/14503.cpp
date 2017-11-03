//
//  14503.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 10. 3..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//0:북 1:동 2:남 3:서
/*
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
   1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
   2. 왼쪽 방향에 청소할 방향이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
   3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
   4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다. */
int map[51][51];
int n, m;
int score;
int tmp;

void clean(int r, int c){
    if(map[r][c] == 0){
        map[r][c] = 1;
        score += 1;
    }
}

void find(int r, int c, int d, int cnt){
    clean(r, c);
    if(cnt == 4){
        switch(d){
            case 0:
                if(map[r+1][c] == 1){
                    find(r+1, c, d, 0);
                }
                break;
            case 1:
                if(map[r][c-1] == 1){
                    find(r, c-1, d, 0);
                }
                break;
            case 2:
                if(map[r-1][c] == 1){
                    find(r-1, c, d, 0);
                }
                break;
            case 3:
                if(map[r][c+1] == 1){
                    find(r, c+1, d, 0);
                }
                break;
        }
        return;
    }
    switch(d){
        case 0:
            if(map[r][c-1] == 0){
                find(r, c-1, 3, 0);
            }
            else
                find(r, c, 3, cnt+1);
            break;
            
        case 1:
            if(map[r-1][c] == 0){
                find(r-1, c, 0, 0);
            }
            else
                find(r, c, 0, cnt+1);
            break;
            
        case 2:
            if(map[r][c+1] == 0){
                find(r, c+1, 1, 0);
            }
            else
                find(r, c, 1, cnt+1);
            break;
            
        case 3:
            if(map[r+1][c] == 0){
                find(r+1, c, 2, 0);
            }
            else
                find(r, c, 2, cnt+1);
            break;
    }
    return;
}

int main(void){
    for(int i=0; i<51; i++){
        for(int j=0 ; j<51 ; j++){
            map[i][j] = 2;
        }
    }
    
    cin >> n >> m;
    
    int r, c, d;
    
    cin >> r >> c >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0 ; j<m ; j++){
            cin >> map[i][j];
        }
    }
    for(int i=n; i<51; i++){
        for(int j=m ; j<51 ; j++){
            map[i][j] = 2;
        }
    }
    
    find(r, c, d, 0);
    cout << score << endl;
    
    
    return 0;
}

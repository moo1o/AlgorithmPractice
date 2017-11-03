//
//  9095.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 8. 31..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>

using namespace std;
int cnt;

void cases(int n, int stnum){
    if(stnum+1 < n){
        cases(n, stnum+1);
    }
    if(stnum+2 < n){
        cases(n, stnum+2);
    }
    if(stnum+3 < n){
        cases(n, stnum+3);
    }
    
    if(stnum+1 == n || stnum+2 == n || stnum+3 == n){
        cnt++;
        return;
    }
}


int main(void){
    int T, n;
    scanf("%d", &T);
    
    for(int i=0 ; i<T ; i++){
        scanf("%d", &n);
        
        cases(n, 0);
        
        printf("%d \n", cnt);
        cnt = 0;
    }
    
    return 0;
}

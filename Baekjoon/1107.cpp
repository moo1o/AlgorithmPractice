//
//  1107.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 8. 31..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, m, tmp, ans = 0;
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    vector<int> elementN(0);
    bool num[10] = {true};
    for(int i=0 ; i<m ; i++){
        scanf("%d", &tmp);
        num[tmp] = false;
    }
    tmp = n;
    while(true){
        if(n < 10){
            elementN.push_back(n);
            break;
        }
        else{
            elementN.push_back(n%10);
            n /= 10;
        }
    }
    n = tmp;
    cnt = (int)elementN.size();
    ans = (unsigned int)(n - 100);
    tmp = 0;
    for(int i=0 ; i<elementN.size() ; i++){
        if(num[elementN[i]] == true)
            tmp = tmp+(elementN[i]*(10^i));
        else{
            int j = 1;
            while(true){
                if(num[elementN[i]+j] == true){
                    tmp = tmp+(elementN[i]*(10^i));
                    break;
                }
                if(num[elementN[i]-j] == true){
                    tmp = tmp+(elementN[i]*(10^i));
                    break;
                }
                j++;
            }
        }
    }
    printf("%d\n", tmp);
    cnt += (unsigned int)(n - tmp);
    if(ans > cnt)
        ans = cnt;
    
    printf("%d\n", ans);
    return 0;
}

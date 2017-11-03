//
//  10819.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 8. 31..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n, ans =0;
    scanf("%d", &n);
    vector<int> ary(n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &ary[i]);
    }
    
    sort(ary.begin(), ary.end());
    
    do{
        int sum = 0;
        for(int i=1; i<ary.size() ; i++){
            sum += abs(ary[i] - ary[i-1]);
        }
        if(ans < sum)
            ans = sum;
    }while(next_permutation(ary.begin(), ary.end()));
    
    printf("%d\n", ans);
    
    return 0;
}

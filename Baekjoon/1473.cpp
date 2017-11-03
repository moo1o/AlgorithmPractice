//
//  1473.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 8. 11..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>

using namespace std;
int d[1000001];

int check(int n){
    if(n == 1) return 0;
    if(d[n] > 0) return d[n];
    d[n] = check(n-1) + 1;
    if(n % 2 == 0){
        int temp = check(n/2) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    if(n % 3 == 0){
        int temp = check(n/3) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    return d[n];
}

int main(void){
    int n;
    cin >> n;
    
    cout << check(n) << endl;
    
    return 0;
}

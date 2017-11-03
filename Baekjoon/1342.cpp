//
//  1342.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 10. 17..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string s;
    cin >> s;
    int ans = 0;
    
    sort(s.begin(), s.end());
    
    do{
        bool check = true;
        for(int i=0 ; i<s.length()-1 ; i++){
            if(i==0){
                if(s[i] == s[i+1]){
                    check = false;
                    break;
                }
            }
            else{
                if(s[i-1] == s[i] || s[i] == s[i+1]){
                    check = false;
                    break;
                }
            }
        }
        if(check){
            ans++;
        }
    }while(next_permutation(s.begin(), s.end()));
    
    cout << ans << endl;
    
    return 0;
}

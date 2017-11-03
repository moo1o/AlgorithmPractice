//
//  1759.cpp
//  Baekjoon
//
//  Created by 김무열 on 2017. 9. 19..
//  Copyright © 2017년 김무열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int l, c;
    
    vector<char> alpha;
    vector<char> Valpha; //모음
    vector<char> Calpha; //자음
    vector<string> ans;
    
    cin >> l >> c;
    
    vector<int> ary(c, 0);
    for(int i = 0 ; i<l ; i++){
        ary[i] = 1;
    }
    
    sort(ary.begin(), ary.end());
    
    for(int i = 0 ; i<c ; i++){
        char tmp;
        cin >> tmp;
        if(tmp == 'a'|| tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
            Valpha.push_back(tmp);
        else
            Calpha.push_back(tmp);
        alpha.push_back(tmp);
    }
    
    do{
        vector<char> tmp;
        for(int i=0; i<ary.size() ; i++){
            if(ary[i] == 1)
                tmp.push_back(alpha[i]);
        }
    }while(next_permutation(ary.begin(), ary.end()));
    
    
    return 0;
}

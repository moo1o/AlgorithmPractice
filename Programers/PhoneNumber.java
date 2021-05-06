import java.util.*;

/*
    프로그래머스 : 전화번호 목록
 */

public class PhoneNumber {

        public boolean solution(String[] phone_book) {
            boolean answer = true;
            /*
            Solve1. 각 길이에 따라 substring 비교 => 시간초과(O(n^2))
             */
//            for(String src : phone_book){
//                for(String desc : phone_book){
//                    if(!desc.equals(src) && src.length() < desc.length() && desc.substring(0, src.length()).equals(src)){
//                        return false;
//                    }
//                }
//            }
            /*
                Solve 2. 해쉬 맵 사용해서 풀이
             */


            Arrays.sort(phone_book, new Comparator<String>(){
                @Override
                public int compare(String s1, String s2){
                    if(s1.length() > s2.length()){
                        return 1;
                    }
                    else if(s1.length() < s2.length()){
                        return -1;
                    }
                    return 0;
                }
            });
            Set<Integer> minSize = new HashSet<Integer>();

            for(String num : phone_book){
                minSize.add(num.length());

            }

            HashMap<String, Integer> prefix = new HashMap<String, Integer>();
            for(String num : phone_book){
                int tlen = num.length();
                Iterator iter = minSize.iterator();
                while(iter.hasNext()){
                    int len = (int) iter.next();
                    if(len <= tlen) {
                        if(prefix.get(num.substring(0,len)) != null && prefix.get(num.substring(0,len)) == num.substring(0,len).length())
                            return false;
                        prefix.put(num.substring(0,len), tlen);
                    }else{
                        break;
                    }
                }
            }



            return answer;
        }

}

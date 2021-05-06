import java.util.HashMap;

/*
    프로그래머스 : 위장
 */
public class Camouflage {
    /*
        Solve 1. 재귀 조합 -> 시간초과
     */
//    Set<HashMap<String, String>> comb = new HashSet<HashMap<String, String>>();
//
//    int N;
//    public int solution(String[][] clothes) {
//
//        N = clothes.length;
//        HashMap<String, String> selec = new HashMap<String, String>();
//        func(0, selec, clothes);
//
//
//        return comb.size();
//    }
//
//    public void func(int n,  HashMap<String, String> selec, String[][] clothes){
//        if(n == N){
//            if(selec.size() > 0)
//               comb.add(new HashMap<String, String>(selec));
//            return;
//        }
//        String key = clothes[n][1];
//        String value = clothes[n][0];
//        //선택 안한 경우
//        func(n+1, selec, clothes);
//        //선택한 경우
//        String prev = "";
//        if(selec.get(key)!=null) {
//            prev = selec.get(key);
//        }
//        selec.put(key, value);
//        func(n+1, new HashMap<String, String>(selec), clothes);
//        if(!prev.equals(""))
//            selec.put(key, prev);
//        else
//            selec.remove(key);
//    }

    public int solution(String[][] clothes) {
        int answer = 0;

        HashMap<String, Integer> cloMap = new HashMap<String, Integer>();
        for(String[] str : clothes){
            String key = str[1];
            String value = str[0];
            cloMap.put(key, cloMap.getOrDefault(key,0)+1);
        }
        answer = 1;
        for(String key : cloMap.keySet()){
            answer *= cloMap.get(key)+1;
        }
        answer--;


        return answer;
    }
}

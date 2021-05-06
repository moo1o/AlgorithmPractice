import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
    프로그래머스 : 완주하지 못한 선수
 */

public class Maratone {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        /*
            Solve 1. 해쉬 이용해서 풀기
            참가자 이름을 키, 참가자 수를 밸류로 하고 완주인원이 있을경우 밸류값을 하나씩 줄여서 최종적으로 해쉬 맵에 0이 아닌 키를 반환
         */
        Map<String, Integer> part = new HashMap<String, Integer>();
        for(String str : participant){
            part.put(str, part.getOrDefault(str,0) +1);
        }
        for(String str : completion){
            part.put(str, part.get(str) - 1);
        }
        for(String str : part.keySet()){
            if(part.get(str) != 0){
                answer = str;
            }
        }

        /*
            Solve 2. 정렬 해서 풀기
            정렬한다음 값을 각각 비교해서 두값이 다를때 participant 값이 답(participant가 1 크므로)
         */
        Arrays.sort(participant);
        Arrays.sort(completion);
        int i=0;
        for(String comp : completion){
            if(!participant[i].equals(comp)){
                break;
            }
            i++;
        }
        answer = participant[i];
        return answer;
    }
}

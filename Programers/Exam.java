import java.util.ArrayList;
import java.util.List;

/*
    프로그래머스 : 모의 고사
 */
public class Exam {
    public int[] solution(int[] answers) {
        int[] answer = {};
        List<Integer> top = new ArrayList<Integer>();
        int score=0;
        //1번 수포자 1~5 순서대로 찍기
        int i = 1;
        int cnt = 0;
        for(int ans : answers){
            if(ans == i){
                cnt++;
            }
            i++;
            if(i == 6)
                i=1;
        }
        top.add(1);
        score = cnt;
        //2번 수포자 2찍고 1, 3, 4, 5 순서
        cnt = 0;
        int[] stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int j = 0;
        for(i=0; i<answers.length ; i++){
            if(answers[i] == stu2[j])
                cnt++;
            j++;
            if(j == 8)
                j=0;
        }
        if(cnt > score){
            top.clear();
            top.add(2);
            score = cnt;
        }else if(cnt == score){
            top.add(2);
        }

        //3번 수포자 3 2번 1, 2, 4, 5 각 두번씩
        cnt = 0;
        j=0;
        int[] stu3 = {3,3,1,1,2,2,4,4,5,5};
        for(i=0 ; i<answers.length ; i++){
            if(answers[i] == stu3[j])
                cnt++;
            j++;
            if(j == 10)
                j=0;
        }
        if(cnt > score){
            top.clear();
            top.add(3);
            score = cnt;
        }else if(cnt == score){
            top.add(3);
        }
        answer = new int[top.size()];
        i=0;
        for(int ans : top){
            answer[i] = ans;
            i++;
        }

        return answer;
    }

}

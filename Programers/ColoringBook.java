import javafx.util.Pair;

import java.util.LinkedList;
import java.util.Queue;

/*
    프로그래머스 : 카카오 컬러링북
 */
public class ColoringBook {
    private static final int[] dy = {0, 1, 0, -1};
    private static final int[] dx = {1, 0, -1, 0};

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int[] answer = new int[2];

        int[][] visit = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] != 0 && visit[i][j] == 0) {
                    int size = bfs(m, n, i, j, picture, visit);
                    if (size > maxSizeOfOneArea)
                        maxSizeOfOneArea = size;
                    numberOfArea++;
                }
            }
        }

        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;

        return answer;
    }

    public int bfs(int m, int n, int x, int y, int[][] picture, int[][] visit) {
        int size = 0;
        int value = picture[x][y];
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair<Integer, Integer>(x, y));
        visit[x][y] = 1;
        size++;
        while (!q.isEmpty()) {
            x = q.peek().getKey();
            y = q.peek().getValue();
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(m, n, nx, ny) && picture[nx][ny] == value && visit[nx][ny] == 0) {
                    visit[nx][ny] = 1;
                    size++;
                    q.add(new Pair<Integer, Integer>(nx, ny));
                }
            }
        }

        return size;
    }

    public boolean check(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}

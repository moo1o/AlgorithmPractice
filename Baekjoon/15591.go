package main

import (
	"bufio"
	"fmt"
	"os"
)

var N, Q int
var mtMap [][]Usado // MooTube 유사도 맵
var visit []bool

type Usado struct {
	d int
	u int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &Q)
	mtMap = make([][]Usado, N+1)
	for i := 1; i < N; i++ {
		var p, q, r int
		fmt.Fscanln(reader, &p, &q, &r)
		usado := Usado{d: q, u: r}
		mtMap[p] = append(mtMap[p], usado)
		usado.d = p
		usado.u = r
		mtMap[q] = append(mtMap[q], usado)
	}

	for i := 0; i < Q; i++ {
		var k, v int
		fmt.Fscanln(reader, &k, &v)
		visit = make([]bool, N+1)
		fmt.Printf("%d\n", bfs(k, v))
	}

}

func bfs(k, v int) int {
	var qary []int
	cnt := 0
	qary = append(qary, v)
	visit[v] = true
	for len(qary) != 0 {
		val := qary[0]
		qary = qary[1:]
		for _, mt := range mtMap[val] {
			if visit[mt.d] {
				continue
			}
			if mt.u >= k {
				cnt++
				qary = append(qary, mt.d)
			}
			visit[mt.d] = true
		}
	}

	return cnt

}

package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
)

//---------
// Fast IO
//---------

var fp, _ = os.Open("input.txt")

var rd = bufio.NewReader(fp)

//var rd = bufio.NewReader(os.Stdin)

// var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

//------
// Main
//------

var N, answer int
var h *IntHeap
var visit []bool

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	defer wr.Flush()
	fmt.Fscanln(rd, &N)
	h = &IntHeap{}
	heap.Init(h)
	visit = make([]bool, 10)
	for i := 0; i < 10; i++ {
		heap.Push(h, i)
		visit[i] = true
		dfs(N, 2, i, i)
		visit[i] = false
	}
	answer = -1
	cnt := -1
	for h.Len() > 0 {
		num := heap.Pop(h).(int)
		cnt++
		if cnt == N {
			answer = num
			break
		}
	}
	fmt.Fprintln(wr, answer)
}

func dfs(N, n, prev, currentNum int) {
	for i := prev + 1; i < 10; i++ {
		if visit[i] {
			continue
		}
		strN := strconv.Itoa(i) + strconv.Itoa(currentNum)
		temp, _ := strconv.Atoi(strN)
		visit[i] = true
		heap.Push(h, temp)
		dfs(N, n+1, i, temp)
		visit[i] = false
	}
}

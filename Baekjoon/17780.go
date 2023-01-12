package main

import (
	"bufio"
	"fmt"
	"os"
)

//---------
// Fast IO
//---------

var fp, _ = os.Open("input.txt")

//var rd = bufio.NewReader(fp)
var rd = bufio.NewReader(os.Stdin)

// var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

//------
// Main
//------
type Piece struct {
	row int
	col int
	dir int
}

var N, K int
var piece []Piece
var chessMap [][]int
var pieceMap [][][]int

func main() {
	defer wr.Flush()
	fmt.Fscanln(rd, &N, &K)
	chessMap = make([][]int, N+1)
	pieceMap = make([][][]int, N+1)
	piece = make([]Piece, K+1)
	for i := 1; i < N+1; i++ {
		chessMap[i] = append(chessMap[i], 0)
		pieceMap[i] = make([][]int, N+1)
		for j := 1; j < N+1; j++ {
			var in int
			fmt.Fscan(rd, &in)
			chessMap[i] = append(chessMap[i], in)
		}
	}

	for i := 1; i < K+1; i++ {
		var row, col, dir int
		fmt.Fscan(rd, &row, &col, &dir)
		piece[i].row = row
		piece[i].col = col
		piece[i].dir = dir
		pieceMap[row][col] = append(pieceMap[row][col], i)
	}
	solve()
}

func solve() {
	answer := 0

	for {
		answer++
		for i := 1; i < K+1; i++ {
			r := piece[i].row
			c := piece[i].col

			if pieceMap[r][c][0] == i {
				move(i)
				if len(pieceMap[piece[i].row][piece[i].col]) >= 4 {
					fmt.Fprintln(wr, answer)
					return
				}
			}
		}
		if answer > 1000 {
			answer = -1
			fmt.Fprintln(wr, answer)
			return
		}
	}
}

const (
	WHITE = 0
	RED   = 1
	BLUE  = 2
)

func move(n int) {
	dy := []int{0, 0, 0, -1, 1}
	dx := []int{0, 1, -1, 0, 0}

	r := piece[n].row
	c := piece[n].col
	d := piece[n].dir
	var color int
	if r+dy[d] < 1 || r+dy[d] > N || c+dx[d] < 1 || c+dx[d] > N {
		color = BLUE
	} else {
		color = chessMap[r+dy[d]][c+dx[d]]
	}

	switch color {
	// 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
	// A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
	// 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다
	case WHITE:
		for i := 0; i < len(pieceMap[r][c]); i++ {
			pn := pieceMap[r][c][i]
			piece[pn].row = r + dy[d]
			piece[pn].col = c + dx[d]
			pieceMap[r+dy[d]][c+dx[d]] = append(pieceMap[r+dy[d]][c+dx[d]], pn)
		}
		pieceMap[r][c] = nil

	// 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
	// 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
	case BLUE:
		switch d {
		case 1:
			d = 2
		case 2:
			d = 1
		case 3:
			d = 4
		case 4:
			d = 3
		}
		piece[n].dir = d
		if r+dy[d] >= 1 && r+dy[d] <= N && c+dx[d] >= 1 && c+dx[d] <= N && chessMap[r+dy[d]][c+dx[d]] != BLUE {
			move(n)
		}

	// 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
	// A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
	// A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
	case RED:
		for i := len(pieceMap[r][c]) - 1; i >= 0; i-- {
			pn := pieceMap[r][c][i]
			piece[pn].row = r + dy[d]
			piece[pn].col = c + dx[d]
			pieceMap[r+dy[d]][c+dx[d]] = append(pieceMap[r+dy[d]][c+dx[d]], pn)
		}
		pieceMap[r][c] = nil
	}

}

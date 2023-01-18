package main

import (
	"bufio"
	"fmt"
	"os"
)

var fp, _ = os.Open("input.txt")

var rd = bufio.NewReader(fp)

// var rd = bufio.NewReader(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

var N int
var spaceMap [][]string
var tInfo []TeacherInfo
var answer string

type TeacherInfo struct {
	y, x int
}

func main() {
	fmt.Fscan(rd, &N)
	spaceMap = make([][]string, N)

	for i := 0; i < N; i++ {
		spaceMap[i] = make([]string, N)
		for j := 0; j < N; j++ {
			var in string
			fmt.Fscan(rd, &in)
			spaceMap[i][j] = in
			t := TeacherInfo{}
			if in == "T" {
				t.y = i
				t.x = j
				tInfo = append(tInfo, t)
			}
		}
	}

	answer = "NO"
	solve()
	//fmt.Fprintln(wr, answer)
	fmt.Println(answer)
}

func solve() {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if spaceMap[i][j] == "X" {
				spaceMap[i][j] = "O"
				for k := 0; k < N; k++ {
					for l := 0; l < N; l++ {
						if spaceMap[k][l] == "X" {
							spaceMap[k][l] = "O"
							for m := 0; m < N; m++ {
								for n := 0; n < N; n++ {
									if spaceMap[m][n] == "X" {
										spaceMap[m][n] = "O"
										if checkMap() {
											answer = "YES"
										}
										spaceMap[m][n] = "X"
									}
								}
							}
							spaceMap[k][l] = "X"
						}

					}
				}
				spaceMap[i][j] = "X"
			}

		}
	}
}

func checkMap() bool {
	for _, t := range tInfo {
		for i := t.y + 1; i < N; i++ {
			if spaceMap[i][t.x] == "S" {
				return false
			}
			if spaceMap[i][t.x] == "O" || spaceMap[i][t.x] == "T" {
				break
			}
		}
		for i := t.y - 1; i >= 0; i-- {
			if spaceMap[i][t.x] == "S" {
				return false
			}
			if spaceMap[i][t.x] == "O" || spaceMap[i][t.x] == "T" {
				break
			}
		}
		for j := t.x + 1; j < N; j++ {
			if spaceMap[t.y][j] == "S" {
				return false
			}
			if spaceMap[t.y][j] == "O" || spaceMap[t.y][j] == "T" {
				break
			}
		}
		for j := t.x - 1; j >= 0; j-- {
			if spaceMap[t.y][j] == "S" {
				return false
			}
			if spaceMap[t.y][j] == "O" || spaceMap[t.y][j] == "T" {
				break
			}
		}
	}

	return true
}

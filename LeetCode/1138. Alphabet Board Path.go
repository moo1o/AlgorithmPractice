package main

import (
	"fmt"
)

func main() {
	str := "abc"
	strByte := []byte(str)

	fmt.Println(strByte[0] - 'a')
	// fmt.Println(alphabetBoardPath("leet"))
	fmt.Println(alphabetBoardPath("zdz"))
}

var board = []string{"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"}

type CharLocation struct {
	x, y  int
	alpha string
}

func alphabetBoardPath(target string) string {
	answer := ""
	cLAry := make([]CharLocation, 26)
	for i := 0; i < len(board); i++ {
		strByte := []byte(board[i])
		for j := 0; j < len(board[i]); j++ {
			cLAry[strByte[j]-'a'] = CharLocation{
				x:     i,
				y:     j,
				alpha: string(strByte[j]),
			}
		}
	}

	type loc struct {
		i, j int
	}
	nowLoc := loc{
		i: 0,
		j: 0,
	}
	t2b := []byte(target)
	for i := 0; i < len(target); i++ {
		targetLoc := loc{
			i: cLAry[t2b[i]-'a'].x,
			j: cLAry[t2b[i]-'a'].y,
		}
		for {
			if cLAry[t2b[i]-'a'].x == nowLoc.i && cLAry[t2b[i]-'a'].y == nowLoc.j {
				answer += "!"
				break
			}
			// find 'U', 'D' oper
			if targetLoc.i < nowLoc.i {
				answer += "U"
				nowLoc.i--
				continue
			} else if targetLoc.i > nowLoc.i { // z 조건 추가하긴
				if (nowLoc.i == 4 && nowLoc.j == 0) || nowLoc.i < 4 {
					answer += "D"
					nowLoc.i++
					continue
				}

			}

			// find 'L', 'R' oper
			if targetLoc.j < nowLoc.j {
				answer += "L"
				nowLoc.j--
				continue
			} else if targetLoc.j > nowLoc.j {
				answer += "R"
				nowLoc.j++
				continue
			}
		}

	}

	return answer
}

// func abs(x int) int {
// 	return int(math.Abs(float64(x)))
// }

//DDDDD!UUUUURRR!DDDDLLLD!
//DDDDD!UUUUURRR!DDDDDLLL!

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(numTilePossibilities("AAB"))
}

var ansMap map[string]bool

func numTilePossibilities(tiles string) int {
	var answer int

	selec := make([]bool, len(tiles))
	ansMap = make(map[string]bool)
	tilesAry := strings.Split(tiles, "")
	var permTiles []string
	perm(tilesAry, permTiles, 0, selec)
	answer = len(ansMap)
	return answer
}

func perm(tilesAry, permTiles []string, order int, selec []bool) {
	if order == len(tilesAry) {
		return
	}

	for i := 0; i < len(tilesAry); i++ {
		if !selec[i] {
			permTiles = append(permTiles, tilesAry[i])
			element := strings.Join(permTiles, "")
			if _, ok := ansMap[element]; !ok {
				ansMap[element] = true
				selec[i] = true
				perm(tilesAry, permTiles, order+1, selec)
				selec[i] = false
			}
			permTiles = permTiles[:len(permTiles)-1]
		}
	}
}

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func part1() int{
	file, err := os.Open("input")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	for i := 1; scanner.Scan(); i++ {
		game := strings.Split(strings.Split(scanner.Text(), ":")[1], ";")
		for ii, set := range game {
			cubes := strings.Split(set, ",")
			fmt.Printf("Game %d, Set %d: %s\n", i, ii, cubes)
		}
	}
	return 0
}

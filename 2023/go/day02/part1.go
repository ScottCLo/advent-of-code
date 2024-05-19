package main

import (
	"bufio"
	"log"
	"os"
)

func part1() int{
	file, err := os.Open("input")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
	}

	return 0
}

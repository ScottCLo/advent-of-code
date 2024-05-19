package main

import (
	"bufio"
	"log"
	"os"
	"strconv"
)

func part1() int{
	file, err := os.Open("input")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	total := 0
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		nums := ""
		for _, c := range line {
			if '0' <= c && c <= '9' {
				nums += string(c)
			}

		}
		result := nums[:1] + nums[len(nums) - 1:]
		rasin, err := strconv.Atoi(result)
		if err != nil {
			log.Fatal(err)
		}
		total += rasin
	}
	return total
}

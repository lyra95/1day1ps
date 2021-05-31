package main

import (
	"bufio"
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"strings"
)

var list []string

func read(path string) (string, string) {
	file, _ := os.Open(path)
	defer file.Close()
	scanner := bufio.NewReader(file)
	header, _ := scanner.ReadString(byte('#'))
	body, _ := scanner.ReadString(byte('@'))
	return header[:len(header)-1], "#" + body
}

func print(path, header, body string) {

	fmt.Println("=========================================================")
	fmt.Println(path[3:])
	fmt.Println("HEADER---------------------------------------------------")
	fmt.Println(header)
	fmt.Println("SOLUTION-------------------------------------------------")
	fmt.Println(body)
}

func initialize() error {
	err := filepath.Walk("../", func(path string, info fs.FileInfo, err error) error {
		if err != nil {
			panic(err)
		}
		if strings.HasSuffix(path, "solution.cpp") {
			list = append(list, path)
		}
		return err
	})
	return err
}

func search_keyword(key string) {
	for i := 0; i < len(list); i++ {
		search_helper(key, list[i])
	}
}

func search_helper(key, path string) {
	header, body := read(path)
	if strings.Contains(header, key) || strings.Contains(body, key) {
		print(path, header, body)
	}
}

func main() {
	initialize()
	for {
		fmt.Println("Select Task.\n0: search by keyword\nothers : exit")
		var task int
		fmt.Scanln(&task)
		switch task {
		case 0:
			var key string
			fmt.Println("Type keyword.")
			fmt.Scanln(&key)
			search_keyword(key)
		default:
			return
		}
	}
}

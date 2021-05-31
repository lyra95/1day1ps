package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

var stdin *bufio.Reader

type Problem struct {
	year   int
	month  time.Month
	day    int
	source string
	level  int
	name   string
	link   string
}

func Setup() Problem {
	year, month, day := time.Now().Date()

	source, _ := GetSource()
	level, _ := GetLevel()
	name, _ := GetName()
	link, _ := GetLink()

	return Problem{year, month, day, source, level, name, link}
}

func GetSource() (string, error) {
	var source string
	fmt.Println("write the source of problem. (Default = programmers)")
	_, err := fmt.Scanln(&source)
	if err != nil {
		source = "programmers"
		//stdin.ReadString('\n')
	}
	return source, err
}

func GetLevel() (int, error) {
	var level int
	fmt.Println("write the level of difficulty")
	_, err := fmt.Scanln(&level)
	if err != nil {
		level = 0
		//stdin.ReadString('\n')
	}
	return level, err
}

func GetName() (string, error) {
	var name string
	fmt.Println("write the name of problem.")
	_, err := fmt.Scanln(&name)
	if err != nil {
		name = ""
		//stdin.ReadString('\n')
	}
	return name, err
}

func GetLink() (string, error) {
	var link string
	fmt.Println("write the url of problem.")
	_, err := fmt.Scanln(&link)
	if err != nil {
		link = ""
		//stdin.ReadString('\n')
	}
	return link, err
}

func PrintInfo(p *Problem) {
	fmt.Printf("Date  : %v %v %v\n", p.year, p.month, p.day)
	fmt.Printf("Source: %v\n", p.source)
	fmt.Printf("Level : %v\n", p.level)
	fmt.Printf("Name  : %v\n", p.name)
	fmt.Printf("URL   : %v\n", p.link)
}

type Code struct {
	header_solution string
	solution        string
	header_test     string
	test            string
	test_h          string
}

func SetupCode(p *Problem) Code {
	header_sol := GetHeaderSol(p)
	sol, _ := GetSolution()
	header_test, _ := GetHeaderTest()
	test, _ := GetTest()
	test_h, _ := GetTestH()
	return Code{header_sol, sol, header_test, test, test_h}
}

func GetText(path string) (string, error) {
	content, err := os.ReadFile(path)
	return string(content), err
}

func GetHeaderSol(p *Problem) string {
	var tmp string = ""
	tmp += fmt.Sprintf("// Date  : %v %v %v\n", p.year, p.month, p.day)
	tmp += fmt.Sprintf("// Source: %v\n", p.source)
	tmp += fmt.Sprintf("// Level : %v\n", p.level)
	tmp += fmt.Sprintf("// Name  : %v\n", p.name)
	tmp += fmt.Sprintf("// URL   : %v\n", p.link)
	return tmp
}

func GetHeaderTest() (string, error) {
	content, err := os.ReadFile("./template/header_test.txt")
	return string(content), err
}

func GetSolution() (string, error) {
	content, err := os.ReadFile("./template/solution.txt")
	return string(content), err
}

func GetTest() (string, error) {
	content, err := os.ReadFile("./template/test.txt")
	return string(content), err
}

func GetTestH() (string, error) {
	content, err := os.ReadFile("./template/test_h.txt")
	return string(content), err
}

func CreateDir() string {
	id, _ := GetID()
	path := "../" + strconv.Itoa(id)

	if _, err := os.Stat(path); os.IsNotExist(err) {
		e := os.Mkdir(path, os.ModeDir)
		check(e)
		fmt.Println("created %v directory", path)
	} else {
		fmt.Println("%v directory already exists", path)
		panic(err)
	}
	LogID(id)
	return path
}

func GetID() (int, error) {
	file, e1 := os.Open("./template/ID_log.txt")
	check(e1)
	defer file.Close()
	var tmp int
	var err error
	scanner := bufio.NewScanner(file)
	if scanner.Scan() {
		tmp, err = strconv.Atoi(scanner.Text())
	}
	tmp++
	return tmp, err
}

// this fucking not working
func LogID(id int) {
	// open ./template/ID_log.txt: The parameter is incorrect.
	file, e1 := os.OpenFile("template/ID_log.txt", os.O_WRONLY|os.O_TRUNC, 0644)
	check(e1)
	defer file.Close()
	w := bufio.NewWriter(file)
	_, err := w.WriteString(strconv.Itoa(id))
	check(err)
	w.Flush()
}

func WriteCode(path string, code *Code) {
	Write(path+"/solution.cpp", code.header_solution+code.solution)
	Write(path+"/test.cpp", code.header_test+code.test)
	Write(path+"/test.h", code.test_h)
}

func Write(path string, body string) {
	file, _ := os.Create(path)
	defer file.Close()
	w := bufio.NewWriter(file)
	w.WriteString(body)
	w.Flush()
}

func main() {
	stdin = bufio.NewReader(os.Stdin)
	p := Setup()
	PrintInfo(&p)
	c := SetupCode(&p)
	path := CreateDir()
	WriteCode(path, &c)
}

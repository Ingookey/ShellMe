package main

import "fmt"
import "os"

func main() {
	fmt.Println("args:", os.Args)
	os.Exit(1)
}
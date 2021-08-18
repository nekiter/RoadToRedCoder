package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// O(N)
func minimumBribes(q []int32) {
	bribes := 0
	for i := len(q) - 1; i >= 0; i-- {
		// Checking if the current person bribed more than 2 person
		if q[i]-int32(i+1) > int32(2) {
			fmt.Println("Too chaotic")
			return
		}

		// Counting how many ppl bribed the current person
		j := int32(0)
		if q[i]-2 > 0 {
			j = q[i] - 2
		}
		// In the worst case checks two numbers
		for j < int32(i) {
			if q[j] > q[i] {
				bribes++
			}
			j++
		}
	}
	fmt.Printf("%d\n", bribes)

}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 16*1024*1024)

	tTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	checkError(err)
	t := int32(tTemp)

	for tItr := 0; tItr < int(t); tItr++ {
		nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
		checkError(err)
		n := int32(nTemp)

		qTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

		var q []int32

		for i := 0; i < int(n); i++ {
			qItemTemp, err := strconv.ParseInt(qTemp[i], 10, 64)
			checkError(err)
			qItem := int32(qItemTemp)
			q = append(q, qItem)
		}

		minimumBribes(q)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}

package main

import (
        "fmt"
        "time"
        "net/http"
)

func main() {
  start := time.Now()
  http.Get("http://www.google.com/")
  fmt.Println(time.Since(start))
}

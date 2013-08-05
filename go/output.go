package main

import (
        "fmt"
        "encoding/json"
        "encoding/xml"
        "log"
)

type Lang struct {
    Name string
    Year int
    URL  string
}

func main() {
    lang := Lang{"Go", 2009, "http://golang.org/"}
    j, errj := json.Marshal(lang)
    x, errx := xml.MarshalIndent(lang, "", "    ")

    if errj != nil {
        log.Fatal(errj)
    }

    if errx != nil {
        log.Fatal(errx)
    }

    fmt.Printf("%s\n", j)
    fmt.Printf("%s\n", x)
}

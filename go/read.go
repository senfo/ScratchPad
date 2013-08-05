package main

import (
        "encoding/json"
        "encoding/xml"
        "fmt"
        "io"
        "log"
        "os"
)

type Lang struct {
    Name string
    Year int
    URL  string
}

func main() {
    do(func(lang Lang) {
        fmt.Printf("%+v\n", lang) // The + gives us more detail about lang

        // Convert the JSON to XML using reflection (lang is still in JSON format)
        data, err := xml.MarshalIndent(lang, "", "    ")

        if err != nil {
            log.Fatal(err)
        }

        fmt.Printf("%s", data)
    })
}

func do(f func(Lang)) {
    input, err := os.Open("lang.json")

    if err != nil {
        log.Fatal(err)
    }

    dec := json.NewDecoder(input)

    for {
        var lang Lang
        err := dec.Decode(&lang)

        if err != nil {
            if err == io.EOF {
                break
            }

            log.Fatal(err)
        }

        f(lang)
    }
}

package main

import "net/http"

func main() {
    bytes := []byte("This is a test...")

    http.HandleFunc("/", func(writer http.ResponseWriter, reader *http.Request) {
        writer.Write(bytes)
    })

    http.ListenAndServe(":8000", nil)
}

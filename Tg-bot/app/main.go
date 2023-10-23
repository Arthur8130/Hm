package main

import (
	"flag"
	"log"
)

const (
	tgBotHost = "api.telegram.org"
)

func main() {
	tgClient := telegram.New(mustToken())
}

func mustToken() string {
	token := flag.String("token-bot-token", "", "token for access to telegram bot")
	flag.Parse()

	if *token == "" {
		log.Fatal("token is not speicified")
	}
	return *token
}
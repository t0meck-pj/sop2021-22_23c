#!/bin/bash

coloredText () {
 echo -e "${2}${1}\e[0m"
}

coloredText "Testowy tekst" "\e[35m" #kolor: Magenta

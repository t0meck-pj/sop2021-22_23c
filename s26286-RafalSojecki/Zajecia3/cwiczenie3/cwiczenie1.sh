#!/bin/bash
# Przygotuj skrypt z funkcją która będzie wypisywała tekst pokolorowany na
# zadany kolor. Niech funkcja ta przyjmuje dwa argumenty - tekst i kolor. 
# Zobacz man console_codes oraz składnię komendy echo (lub przykład
# z poprzednich zajęć).

function printColoredText {
  declare -A COLORS
  COLORS[reset]="\e[0m"
  COLORS[black]="\e[30m"
  COLORS[red]="\e[31m"
  COLORS[green]="\e[32m"
  COLORS[orange]="\e[33m"
  COLORS[blue]="\e[34m"
  COLORS[purple]="\e[35m"
  COLORS[cyan]="\e[36m"
  COLORS[gray]="\e[37m"

  echo -e "${COLORS[$2]} $1"
}

printColoredText "tekst", black
printColoredText "tekst", red
printColoredText "tekst", green
printColoredText "tekst", orange
printColoredText "tekst", blue
printColoredText "tekst", purple
printColoredText "tekst", cyan
printColoredText "tekst", gray
printColoredText "tekst", reset

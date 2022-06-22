#!/bin/bash

fib() {
    if [[ $1 -le 1 ]]; then
        return "$1"
    else
        fib $(($1-1))
        local wynik=$?
        fib $(($1-2))
        return $((wynik+$?))
    fi
}

fib 20

echo "Wynik funkcji fibonacciego to $?"
#nastapilo przekroczenie zakresu (zakres return to jeden bajt [0-255)

#!/bin/bash

fib() {
    declare wynik;
    if [ $1 -le 1 ]; then
        echo $1
    else
        pierwszy=$(fib $(( $1 - 1 )));
        drugi=$(fib $(( $1 - 2 )));
        wynik=$(( $pierwszy + $drugi ));
        echo $wynik;
    fi
    return $wynik
}

fib 20

echo "Wynik funkcji fibonacciego to $?"
#nastapilo przekroczenie zakresu (zakres return to jeden bajt [0-255)

#!/bin/bash

max=$1 #jako parametr podajemy ile liczb z ciagu ma sie wyswietlic w konsoli ale rownie dobrze mozemy ustawic tu stala liczbe

fibonacciSeries () {
 firstNumber=0
 secondNumber=1

 for (( i=0; i<$max; i++ )); do
     echo $firstNumber

     addition=$((firstNumber + secondNumber))

     firstNumber=$secondNumber
     secondNumber=$addition
 done
}

echo "Ciag fibonacciego: " $(fibonacciSeries)

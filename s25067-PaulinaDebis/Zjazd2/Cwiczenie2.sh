#!/bin/bash

#X=tekst
#echo $X
#bash
#echo $X

#po uruchomieniu skryptu na ekranie pojawilo sie tylko jeden raz slowo "tekst". Logika podpowiadalaby,
#ze powinnismy sie spodziewac dwoch wyrazow. 
#Jest tak dlatego ze w trzeciej linijce napisalismy "bash", co spowodowalo, ze uruchomilismy nowa powloke basha, 
#w tej z ktorej korzystamy aktualnie. Uruchamiajac skrypt uruchmiamy go w tej pierwszej powloce, dlatego tez
#drugi napis nam sie nie pojawia bo jest on przypisany do nowej powloki zagniezdzonej w aktualnej powloce.

#X='Tekst dłuższy'
#echo $X

#Wyskoczyla nam komenda, ze jest blad w linijce 14, czyli u mnie akurat w miejscu gdzie przypisuje wartosc do X.
#Stalo sie tak dlatego, ze w odroznieniu od pierwszego przykladu, gdzie do zmiennej pprzypisywalismy pojedyncze slowo,
#tutaj dajemy juz jakis ciag wyrazow. Zeby zadzialalo musimy:
#a) dac ", jezeli wiemy ze w tym co bedzie pomiedzy cudyslowiami nie znajdziemy zadnego znaku specjalnego, a zmienne sa
#tlumaczone na wartosci
#b) dac ', wtedy hulaj dusza piekla nie ma

#X="Tekst 1"
#Y="tekst:$1"
#echo "$Y"
#Y='tekst:$X'
#echo "$Y"
#Y=tekst:$X
#echo "$Y"

#Po uruchomieniu skryptu na ekranie pojalilo sie:
#tekst:
#tekst:$X
#tekst:Tekst 1

#co jest zgodne z tym co napisalam powyzej :)

A=Ala
echo $A ma kota, a kot ma ${A}ę


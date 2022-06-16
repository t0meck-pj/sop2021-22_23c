
## Zadania zjazd nr.2 2022.03.25

### Zadanie 1
```
#!/bin/bash
echo -e "Witamy w terminalu"
```

### Zadanie 2

- Seria poleceń, ostatnie ```echo $X``` nie wydrukuje nic z racji na to ze nie przekazalismy zmienej do nowej instancji basha, wywolanej przed chwilą.
- ```X=Tekst dłuższy``` to nie zadziala. Whitespace to koniec deklaracji X'a. Nalezy to zrobic tak ```X="Test dluższy"```

#### Roznice miedzy ```'``` a ```"```

- ```"``` Pozwala powloce odnalesc i nadpisac wywolania zmiennych ktore zostaly uzyte w stringu.
- ```'``` Cos jak `"""test"""` w pythonie, czyli wszystko to co w takim stringu ma zostac tak jak jest bez interpretacji i dopisywania.

### Zadanie 3

#### PATH

- Zmienna przechowuje string sciezki do folderu zawierajacego skrypty, programy. Dzieki temu mozemy uruchomic np. komende "Python3". Bez koniecznosci podawania calkowitej lokalizacji programu Python3.exe

#### RANDOM

- Pseudolosowa liczba z zakresu 0-32768

#### PWD

- Sciezka do katalogu w ktorym obeznie sie znajduje terminal

#### PS1

- Jest to wzor na przedrostek ktory pojawia sie gdy wejdziemy w terminal.
- Np. user@pc ~ $

#### USER

- Nazwa uzytkownika ktory odpalil terminal wywolujacy komende

#### HOSTNAME

- Nazwa hosta 

#### OSTYPE

- Rodzaj systemu operacyjnego np. "darwin","cygwin"

### Zadanie 4

#### X=$(ls -l)





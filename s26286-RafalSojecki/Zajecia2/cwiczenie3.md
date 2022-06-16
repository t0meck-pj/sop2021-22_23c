```PATH```

```/Users/rafal.sojecki@schibsted.pl/.nvm/versions/node/v16.15.0/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Users/rafal.sojecki@schibsted.pl/.nvm/versions/node/v16.15.0/bin```

Zawiera ona informacje o miejscach w których znajdują się pliki wykonywalne.

Mogą się przydać gdy chcę umożliwić wykonywanie programu lub skryptu bez
każdorazowego podawania ścieżki.

---
```RANDOM```

```3424```

Generator liczb pseudolosowych.

Przydatny przy konieczności zasymulowania losowości, nie kryptograficznej. Symulacja
rzutu kostką, odwołanie do losowego komputera w sieci itp.

---
```PWD```

```/Users/rafal.sojecki@schibsted.pl/Pjatk/sop2021-22_23c/s26286-RafalSojecki/Zajecia2```

Ścieżka bezwzględna katalogu w którym się znajdujemy.

Sprawdzanie czy nie wykonujemy skryptu w katalogu głównym

---
```PS1```

OSX
```%n@%m %1~ %#```

Debian
```${debian_chroot:+($debian_chroot)}\u@\h:\w\$```

Zmienna w której jest definiowany wygląd znaku zachęty (ciągu znaków).

Przydatne gdy chcemy by terminal witał nas wybranym przez nas tekstem np. jak na szuflandii.

---
```USER```

Nazwa użytkownika

Przydatne gdy chcemy zidentyfikować użytkownika wykonujacego skrypt (np. przy tworzeniu logów)

---
```HOSTNAME```

Nazwa hosta

---
```OSTYPE```

OSX
```darwin21.0```

Debian
```linux-gnu```

Typ systemu operacyjnego.

Przydatne przy tworzeniu skryptów na wiele platform, można dzięki niej
rozwiązać problemy wynikające z różnic implementacyjnych poszczególnych
komend na różnych OS (np sed - https://unix.stackexchange.com/a/131940)

Wykonaj komendę ```ls -l``` w podpowłoce i przypisz ją do zmiennej ```X```.

Wyświetl zawartość tej zmiennej.

Spraw, aby nie było różnicy (co najwyżej kolorki) między zwykłym wykonaniem komendy:

```
ls -l
```
a wypisaniem zawartości zmiennej X. Nie będzie dobrego rezultatu gdy zrobimy tak:
```
echo $X
```
Zastanów się dlaczego.


```
rafal.sojecki@schibsted.pl@60386 Zajecia2 % ls -l
total 24
-rwxr-xr-x  1 rafal.sojecki@schibsted.pl  staff   232  5 cze 16:26 cwiczenie1.sh
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff  1515  5 cze 17:22 cwiczenie2.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff  1613  5 cze 18:50 cwiczenie3.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 18:58 cwiczenie4.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 18:58 cwiczenie5a.sh
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 19:01 cwiczenie5b.sh
```
```
X=$(ls -la)
```

```
rafal.sojecki@schibsted.pl@60386 Zajecia2 % echo $X
total 24
drwxr-xr-x  8 rafal.sojecki@schibsted.pl  staff   256  5 cze 19:01 .
drwxr-xr-x  3 rafal.sojecki@schibsted.pl  staff    96  5 cze 18:58 ..
-rwxr-xr-x  1 rafal.sojecki@schibsted.pl  staff   232  5 cze 16:26 cwiczenie1.sh
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff  1515  5 cze 17:22 cwiczenie2.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff  1613  5 cze 18:50 cwiczenie3.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 18:58 cwiczenie4.md
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 18:58 cwiczenie5a.sh
-rw-r--r--  1 rafal.sojecki@schibsted.pl  staff     0  5 cze 19:01 cwiczenie5b.sh
```

Pod OSX wyswietla się "prawidłowo"

Natomiast na Debianie:

```
s26286@szuflandia:~$ echo $X
razem 128 drwxr-xr-x 7 s26286 pjwstk 4096 sty 15 08:57 . drwxr-xr-x 3235 root root 69632 kwi 7 09:36 .. -rwxr--r-- 1 s26286 pjwstk 0 paź 9 2021 1Cwiczenia.txt -rw------- 1 s26286 pjwstk 150 gru 3 2021 .bash_history -rw-r--r-- 1 s26286 pjwstk 220 paź 5 2021 .bash_logout -rw-r--r-- 1 s26286 pjwstk 3392 paź 5 2021 .bashrc drwxr-xr-x 2 s26286 pjwstk 4096 paź 23 2021 .nano -rw-r--r-- 1 s26286 pjwstk 675 paź 5 2021 .profile drwxr-xr-x 3 s26286 pjwstk 4096 paź 9 2021 Projekty -rwxr--r-- 1 s26286 pjwstk 15238 sty 15 08:57 ps-info.ps1.txt drwxr-xr-x 2 s26286 pjwstk 4096 paź 23 2021 public_html drwxr-xr-x 4 s26286 pjwstk 4096 paź 23 2021 ukos drwxr-xr-x 3 s26286 pjwstk 4096 paź 9 2021 windows
```

Po otoczeniu zmiennej w nawias:

```
s26286@szuflandia:~$ echo "$X"
razem 128
drwxr-xr-x    7 s26286 pjwstk  4096 sty 15 08:57 .
drwxr-xr-x 3235 root   root   69632 kwi  7 09:36 ..
-rwxr--r--    1 s26286 pjwstk     0 paź  9  2021 1Cwiczenia.txt
-rw-------    1 s26286 pjwstk   150 gru  3  2021 .bash_history
-rw-r--r--    1 s26286 pjwstk   220 paź  5  2021 .bash_logout
-rw-r--r--    1 s26286 pjwstk  3392 paź  5  2021 .bashrc
drwxr-xr-x    2 s26286 pjwstk  4096 paź 23  2021 .nano
-rw-r--r--    1 s26286 pjwstk   675 paź  5  2021 .profile
drwxr-xr-x    3 s26286 pjwstk  4096 paź  9  2021 Projekty
-rwxr--r--    1 s26286 pjwstk 15238 sty 15 08:57 ps-info.ps1.txt
drwxr-xr-x    2 s26286 pjwstk  4096 paź 23  2021 public_html
drwxr-xr-x    4 s26286 pjwstk  4096 paź 23  2021 ukos
drwxr-xr-x    3 s26286 pjwstk  4096 paź  9  2021 windows
```

Podejżewam że znak końca lini jest dodawany jako efekt wykonania polecenie/programu
i nie jest przechowywany w łańcuchu znaków.

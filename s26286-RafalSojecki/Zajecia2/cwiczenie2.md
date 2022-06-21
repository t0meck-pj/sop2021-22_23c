Zobacz taką serię poleceń:

```
X=tekst
echo $X
bash
echo $X
```

Co się stało? Czy potrafisz wyjaśnić?

Stworzyliśmy zmienną ```X``` przechowywującą ciąg znaków. Przy uzyciu komendy
```echo``` wyświetliliśmy ja na ekranie. Zmienna ta jest zmienną lokalną,
dostępną tylko w zakresie instancji bash-a w której została zadeklarowana.
Następnie stworzyliśmy nową instancje bash-a i w niej próbowaliśmy się odwołać
do zmiennej ```X```. Zakończyło to się niepowodzeniem, zmienna nie istnieje
w bierzącej instancji.

---
Zobacz:

```
X=Tekst dłuższy
echo $X
```

Co jest nie tak? jak to naprawić? Zobacz czy pomoże zastosowanie cudzysłowów
i apostrofów.

Zadeklarowaliśmy zmienną lokalną ```X``` i przyporządkowaliśmy jej wartość
```Tekst```, następnie nieopatrznie wywołaliśmy komendę ```dłuższy``` która
prawdopodobnie nie jest zdefiniowana w wielu powłokach bash. Komenda
oczywiście się nie wykonała (bo jej nie ma) a zmienna nie została
zadeklarowana.

Możemy owinąć łańcuch znaków zarówno w cudzysłów i apostrof - w tym
przypadku różnice między nimi nie wpływają na poprawności wyniku.

---
Zobacz:
```
X="Tekst 1"
Y="tekst:$X"
echo "$Y"
Y='tekst:$X'
echo "$Y"
Y=tekst:$X
echo "$Y"
```
Jaka jest różnica między " a ' ?

Wartości w apostrofach są zachowywane dokładnie jak je wpisaliśy (z wyłączeniem
apostrofu), a w cudzysłowie z wyłączeniem znaków interpretowanych. Ponnadto
w cudzysłowie zmienne są zamieniane na wartości.

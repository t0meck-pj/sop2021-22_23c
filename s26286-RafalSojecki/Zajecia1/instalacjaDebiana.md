#Instalacja debiana na maszynie wirtualnej
## 1. Ustawienia maszyny wirtualniej
W kolejnych oknach wybieramy:
1. Nazwę maszyny, folder w którym przechowywane są pliki maszyny wirtualnej
Typ systemu operacyjnego (Linux) i wersje (Debian 64bit)
2. Ilość dostępnej pamięci RAM (Wg dokumentacji Debian potrzebuje minimum
512MB, rekomendowane są natomiast 2GB. Jako że posiadam 32 GB ustawiłem 4 GB)
3. Dysk twardy. Możemy nie tworzyć dysku wirtualnego, stworzyć nowy lub użyć
istniejącago. W naszym przypadku chcemy stworzyć nowy. Mamy tutaj 3 formaty
do wyboru:
    - VDI
    - VHD
    - VMDK
    Wybieram VDI, gdyż jest to format domyślny VirtualBox-a i nie zamierzam
    udostępniać obrazu dysku innym użytkownikom posiadającym inne
    oprogramowanie maszyn wirtualnych.
4. Typ dysku. Mamy 2 opcje do wyboru
    - Dynamicznie przydzielany
    - Stały
    Pierwszy pozwala na stworzenie pliku dysku twartego ze zmienną
    wielkością, pozwala to na bardziej optymalne wykorzystanie dysku
    twardego hosta. Zwiększa się jego rozmiar (Do określonej wartości) wraz
    z ilością danych zapisanym na dysku w maszynie wirtualnej, aczkolwiek
    nie jest on zmiejszany po usuwaniu danych z niego.
    W stałym określamy wielkość i tworzony jest plik o tej samej ilośći GB
5. Rozmiar dysku. Dokumentacja podaje minimalny rozmiar 10 GB, ustawiłem 20GB

## Instalacja
0. W głównym oknie klikamy na napęd optyczny i montujemy obraz debiana 
pobrany wcześniej z internetu. Uruchamiamy maszynę wirtualną
1. Widzimy menu instalatora. mamy do wyboru:
    - Graphical install - instalacja przy użyciu GUI.
    - Install - instalacja bez interfejsu graficznego
    - Opcje zaawansowane:
        - tryb experta, pozwalający na pełną kontrolę procesu instalacji
        - rescue mode, przeznaczony do naprawy OS
        - Automated install
    - Pomoc i opcje ułatwienia dostępu

2. Wybieramy Install
3. Wybór języka - Angielski
3. Wybór połozenia - Polska
4. Wybór lokalizacji - pl_PL.UTF-8
5. Układ klawiatury - polski
6. Nazwa hosta - podajemy nazwę pod którą komputer będzie widoczny w sieci -
VM-1
7. Nazwa domeny - w naszym przypadku zostawiamy puste.
8. Nadajemy hasło root-a 
9. Tworzymy użytkownika
10. Partycje
Mamy do wyboru:
    - Guided - use entire disk - używany jest kreator
    - Guided - use entire disk and set-up LVM - jak poprzednio + LVM czyli
    rozwiązanie pozwalające na bardziej elastyczne tworzenie partycji
    - Guided - use entire disk and set-up Encrypted LVM - jak poprzednio +
    szyfrowanie
    - Manual - ręczny podział

Dokonujemy podziału ręcznego podziału na partycje. Możemy stworzyć 
maksymalnie 4 partycje podstawowe. Musimy stworzyć minimum jedną - na 
system, powinniśmy też stworzyć partycje SWAP - jest ona wykorzystywana jako 
przestrzeń wymiany, gdy zabraknie nam ramu i podczas hibernacji jest tam 
przechowywany zrzut pamięci RAM. Wg https://opensource.com/article/18/9/
swap-space-linux-systems powinniśmy ustawić 8 GB (dla 4GB RAM-u).

Ustaiwamy partycje systemową, ustawiamy jej wielkość (12 GB), ustawiamy 
punkt montowania na /, Label (etykietę), zaznazcamy że jest to partycja 
bootowalna.

Dobrą praktyką jest rozdzielenie danych użytkownika do osobnej partycji, 
tworzymy ją analogicznie jak partycje systemową, ustawiając punkt montowania 
na /home, zaznaczamy tylko że partycja NIE jest bootowalna.

W przypadku gdy chcemy stworzyć więcej niż 4 partycje podstawowe, możemy 
wspomagać się partycjami logicznymi.

12. Dodatkowe Oprogramowania
Tutaj dokonujemy wyboru GUI które chcemy zainstalować, SSH, Serwera WWW
oraz Standardowych narzędzi systemowych

12. GRUB
Jest to program służący do załadowania systemu operacyjnego, w naszym 
wypadku chcemy go zainstalować
(nie posiadamy zainstalowanego innego bootloadera)

13. Restart, Możemy się zalogować i korzystać z systemu

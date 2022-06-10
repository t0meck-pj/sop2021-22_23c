## Instalacja debiana 2022.03.17

### Pobranie systemu
- Wchodzimy na oficjalna stronke Debiana. Klikamy w przycisk Download. Przekieruje to nas na podstronke z rozszerzeniem /download.
- Po krótkiej chwili rozpocznie się automatyczne pobieranie pliku iso.
- Jeśli zajdzie potrzeba pobrania innej wersji debiana lub wersji systemu dla urządzeń 32-bitowych.
- Nalezy wejść w zakładke other releases.
- Tutaj mamy możliwość nawet pobrania wersji w fazie testowej oraz nie stabilnych.
- Po wybraniu wersji którą chcemy pobrać wybieramy architekture komputera na której będzie debian zainstalowany aby mieć odpowiednie wsparcie.

### Tworzenie wirtualnej maszyny
- Odpalamy VirutalBox'a i klikamy guzik z napisem "New"
- Nadajemy nazwe Maszynie wybieramy typ - Linux, wersja - Debian (64-bit)
- Oraz podajemy lokalizacje na dysku dla naszej maszyny.
- Przydzielamy ilość pamięci RAM - tutaj w zależności od potrzeb i od zasobów naszego komputera (na oficialnej stronie debiana jest tak: No desktop [min. 128 MB, recommended 512 MB] With Desktop [min. 256 MB, recommended 1024 MB] Ja wybrałem 4GB
- Następnie wybieramy typ pliku wirtualnego dysku. Wybieramy VDI
- VDI to natywny format dysku dla oprogramowania VirtualBox
- VHD format dysku rozwijany przez Microsoft używany w Hyper-V
- VMDK czyli rodzaj dysku charakterystyczny dla oprogramowań od firmy VMware takich jak VMware Workstation, VMware Server, VMware Server, VMware Fusion, VMware ESXi
- W kolejnym kroku pojawia się pytanie o to czy chcemy mieć dynamicznie przydzielany rozmiar dysku czy też na stałe mieć przydzielony rozmiar. Jeśli wybierzemy dynamiczny to wybranie np. 200GB w kolejnym kroku będzie oznaczało że dysk może mieć maxymalnie 200GB a teraz niech zajmuje minimalną potrzebną pojemność. W przypadku wybrania stałej pojemności odrazu dysk bedzie zajmował 200GB nie będzie to dynamiczne.
- Wybieramy rozmiar oraz lokalizacje dysku. Tutaj w zależności od celów użytkowych systemu. Według strony debian.org (You must have at least 135MB of memory and 780MB of hard disk space to perform a normal installation.) Czyli minimalnie wybrałbym 1GB. A teraz wybieram 200GB statycznego przydzielania

### Konfiguracja wirtualnej maszyny
- Klikamy guzik z napisem "Settings"
- Wchodzimy w zakładke Storage
- Na dole mamy 4 ikonki klikamy w drugą od prawej. Klikamy optical drive dodajemy wczesniej pobrane iso debiana

### Faktyczna instalacja debiana

- Klikamy guzik START
- Maszyna pyta się o wybór instalacji wybieramy "install" bez środowiska graficznego
- Pytanie o jezyk jaki chcemy mieć, wybieramy English, caly świat IT działa w tym jezyku. W przypadku wystąpienia problemów będzie nam łatwiej odnaleść odpowiedz jeśli będziemy szukali odpowiedzi na problem po angielsku. W 95% przypadków ktoś już kiedyś trafił na nasz problem i odpowiedz została do niego znaleziona.
- Pytanie o lokalizacje wchodzimy w other, potem Europe, i Poland.
- Wybieramy kodowanie en_US.UTF-8 UTF-8 jest najpopularniejszym sposobem zapisu wartości liczbowej z tablicy Unicode do postaci bitowej. Jest też te kodowanie kompatybilne z ASCII
- Keymap - American English
- Hostname - dowolnie, mozna zostawić "debian"
- Pytanie o adres domeny pod ktora dziala nasz serwer/urzadzenie, tutaj nic nie wpisujemy bo to wirutalka w prywatnej sieci
- Pytanie o haslo roota, ustawiamy takie jakie spamiętamy i nie będzie tymsamym zbyt łatwe.
- Potwierdzenie hasla
- Stworzenie nowego uzytkownika ale juz tym razem nie roota, pytanie o "full name" potem o "nickname", a na koncu o haslo.
- Pytanie o przestrzen dyskową, klikamy w "manual"
- LVM - jest to system zaawansowanego zarządzania przestrzenią dyskową, który jest o wiele bardziej elastyczny, niż klasyczne partycje dyskowe. Zarządca pozwala na połączenie partycji znajdujących się na różnych urządzeniach pamięci masowej w jeden dysk wirtualny.
- Encrypted LVM - tworzy zaszyfrowaną partycje LVM
- Odnajdujemy i wybieramy nasz wirtualny dysk
- Klikamy w niego, potwierdzamy utworzenie pustej tabeli partycji
- klikamy w free space
- Klikamy "Create a new partition"
### /root

- Ja przyznaczam 30GB, wybieram beginning, primary, ext4 i ustawiam flage bootable na off

### Tworzymy partycje boot
- Podajemy wielkosc nowej partycji, ja dałem z 1.5GB
- Pytanie o typ. Primary czy Logical. Logical sluzy do przychowywania danych a Primary zawiera system oraz sluzy do bootowania. Wybieramy Primary
- Pytanie o to gdzie w pamieci ma sie znajdować nasza partycja, daje ją jako pierwszą.
- Teraz jesteśmy w koncowym dostrajaniu partycji, ustawiamy mount point na /boot, chcemy aby tutaj byla przypisywana cala hierarchia plikow systemowych.
- Nadajemy nazwe w okienku Label na "boot"
- Use as: EXT4 journaling file system
- Koniec

### swap

Jest to "systemowa partycja występująca w systemach typu UNIX.
 Służy do tymczasowego przechowywania danych w sytuacji, gdy ich ilość
 przekracza zasoby wolnej pamięci RAM". Dla swap'a tworzymy partycje logiczną wybieramy "swap area".

##### Co do wielkośći partycji swap natrafiłem na taką tabelke w internecie

- 1 kolumna ilość Ramu w systemie
- 2 kolumna rekomendowana pojemność na "swap"a
- 3 kolumna rekomendowana pojemność na "swap"a z hibernacją
- ≤ 2GB | 2X RAM | 3X RAM
- 2GB – 8GB | 	= RAM |	2X RAM
- 8GB – 64GB |	4G to 0.5X RAM |1.5X RAM
- >64GB |	Minimum 4GB |	Hibernation not recommended
- Zgodnie z tą tabelką przypisałem odpowiednią wielkość partycji swap
- Mam 4GB pamięci ram to daje 8GB.

### Systemy plków
- Ext4 - jest kompatybilny wstecznie z ext2, jak i ext3.O obecnie najpopularniejszy system plikow na Linux'ach
- Ext3 , Ext2 - poprzednicy Ext4, posiadają adresowanie pośrednie bloków a ext4 zmienił to i posiada mechanizm extentów. Nie będe się wymądrzał bo przeczytałem tylko to co w necie znalazłem
tutaj jest ciekawy artykuł o tych rzeczach. https://students.mimuw.edu.pl/ZSO/Wyklady/00_stud/ext4/ext4.html
- btrfs - system plików stworzony przez Oracle, zaprojektowany w celu bycia mniej awaryjnym
- JFS - opracowany przez IBM, 64-bitowy system plików z księgowaniem. Księgowanie pośrednie zapisywanie danych na dysku przy użyciu dziennika, dzieki czemu zmniejsza się prawdopodobieństwo utraty danych.
- FAT16 (File Allocation Table) - odmiana systemu FAT, posługująca się 16-bitowym adresowaniem przy dostępie do plików. Stworzony do obsługi pierwszych dysków twardych

### /home

- w miejscu na pojemnosc wpisuje MAX bo chce przeznaczyc reszte pamieci na tą partycje. mount point - /home i tyle.
- Zatwierdzamy swoje zmiany na dysku

### Software Selection

- Pytanie o software selection, bo narazie mamy tylko zainstalowane podstawowe rzeczy systemowe jesli chcemy miec ssh server albo web server, albo zmienic srodowisko graficzne na Xfce to mozemy teraz to tutaj zaznaczyc.
- Z tego co sie dowiedzialem na cwiczeniach pozniej tez mozna te opcje odpalic.
- Instalator zauwazyl ze jest to swiezy system i pyta sie czy chcemy grub'a jak bedziemy instalowali kolejne systemy ulatwi to sprawe bo juz bedziemy mieli bootloader.
- Instalacja zakonczona

### GRUB - grand unified bootloader

- Jest to najpopularniejszy program rozruchowy, służący do uruchomiania systemu operacyjnego, bez niego nie bylibyśmy w stanie załadować systemu. Daje rowniez mozliwość uzytkowania wiecej niz jednego systemu na jednej maszynie.
- IPL - (Initial Program Loader) znajduje się w MBR(Master Boot Record), nie rozpoznaje systemu plików, za to potrafi załadować moduł odpowiedzialny za obsługe danego typu plików.
- Czytany jest plik boot/grub/menu.list i wyświetlane menu startowe
- Po wybraniu pozycji następuje uruchamianie konkretnego systemu
- Istnieją alternatywy dla GRUB'a np. systemd-boot (popOS!),rEFInd i LILO.
- Doczytalem ze mozna stworzyc partycje ESP ustawioną na bootable (litera B) a bios mode ustawic na uefi wtedy grub nie jest potrzebny

- Koniec

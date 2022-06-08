# Przygotuj skrypt, który odczyta plik (jego nazwa ma być argumentem skryptu)
# i wypisze go na terminalu tak, aby wszystkie wystąpienia Twojego imienia
# były podświetlone na czerwono. 
#!/bin/bash

value=$(<$1)
HIGLIGHTED="\e[32mSOP\e[0m"
echo -e "${value//Rafał/$HIGLIGHTED}"

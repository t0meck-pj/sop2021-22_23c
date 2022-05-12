#!/bin/bash

if [[ $1 =~ ^[A-ZŻĘÓĄŚŁŻŹĆŃ][[AaĄąBbCcĆćDdEeĘęFfGgHhIiJjKkLlŁłMmNnŃńOoÓóPpRrSsŚśTtUuWwYyZzŹźŻż]{0,16}$ ]]; then
	echo "Imie $1 jest poprawne!!";
else
	echo "Imie $1 jest niepoprawne!!"
fi

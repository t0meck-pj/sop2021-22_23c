#!/bin/bash


if [[ $1 =~ ^[A-ZŻĘÓĄŚŁŻŹĆŃ][[AaĄąBbCcĆćDdEeĘęFfGgHhIiJjKkLlŁłMmNnŃńOoÓóPpRrSsŚśTtUuWwYyZzŹźŻż]{0,16}$ ]]; then echo "imie"
elif [[ $1 =~ [1-9]{1}[0-9]{1}[-][0-9]{3}$ ]]; then echo "kod pocztowy"
elif [[ $1 =~ ^[^\.\!\$\%\`\^\@\&\\*\#\(\+\=\)\_\-]+@[^\.\!\$\@\%\^\&\\*\#\(\+\=\)\_\-]+[.]+[^\.\!\$\%\^\&\*\#\(\+\=\)\@\_\\\-]{2,4}$ ]]; then echo "email"
else echo "nie pasuje nic"
fi

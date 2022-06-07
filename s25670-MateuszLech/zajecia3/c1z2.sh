$!/bin/bash
if [ -e config.cfg ]; then
	./config.cfg
elif [ $# -gt 0 ]; then
	./$1
else
	echo "Błąd"
fi

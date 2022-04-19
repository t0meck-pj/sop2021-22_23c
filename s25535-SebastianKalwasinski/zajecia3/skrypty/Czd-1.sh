#!/bin/bash

if [[ $1 =~ ^([A-ZĄŚĆÓŻŹ]{1}[a-ząśćóżź]*)$ ]]; then
	echo "Tekst spełnia wymagania zadania domowego."

else
	echo "Warunki nie zostały spełnione."
fi


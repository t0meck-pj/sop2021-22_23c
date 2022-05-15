#!/bin/bash

if [[ $1 =~ ^([A-ZĄŚĆÓŁŻŹ]{1}[a-ząśćółżź]+)$ ]]; then
	echo "Tekst spełnia wymagania zadania domowego."

else
	echo "Warunki nie zostały spełnione."
fi


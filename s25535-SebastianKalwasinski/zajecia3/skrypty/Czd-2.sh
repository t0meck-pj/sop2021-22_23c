#!/bin/bash

echo "Czy $1 to kod pocztowy?"

if [[ $1 =~ (^[0-9]{2}-[0-9]{3})$ ]]; then
echo "Tak, $1 jest kodem pocztowym." 

else
echo "Nie, $1 nie jest kodem pocztowym."
fi


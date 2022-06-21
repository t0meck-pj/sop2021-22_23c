#!/bin/bash
# Napisz skrypt, który wczyta jako argument jakiś tekst. Skrypt ten wypisze
# kolejno:
# - Pierwszy znak z argumentu
# - Ostatni znak z argumentu
# - Zamieni w argumencie każdy tekst SOP na tekst poniżej (zastosuj echo z
#  przełącznikiem -e):
#  \e[32mSOP\e[0m
# Przykładowy tekst testowy:
# SOP! SOP w imieniu prawa! SOP w imieniu prawa!
# Wynikowo ma to wyglądać tak:
# SOP! SOP w imieniu prawa! SOP w imieniu prawa!

HIGLIGHTED="\e[32mSOP\e[0m"
echo -e "${1//SOP/$HIGLIGHTED}"

#!/bin/bash

greetString="Hello"
nameString="stranger"

if [ "$#" -lt 1 ]; then
    echo "Недостаточно аргументов. Пожалуйста, передайте в качестве аргумента имя. Пример: $0 Vasya"
    exit 1
fi

if [ "$1" = "Vasya" ]; 
then
    nameString="Vasiliy"
    greetString="Whatsup"
elif ["$1" = "Masha"];
then
     nameString="Maria"
elif ["$1" = "Michael" ];
then
    greetString="Shalom"
    nameString="Michael"
fi

echo "$greetString, $nameString!"


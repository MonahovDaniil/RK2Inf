#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Пожалуйста, укажите директорию и расширение файлов."
    exit 1
fi

dir="$1"
ext="$2"

if [ ! -d "$dir" ]; then
    echo "Директория не найдена."
    exit 1
fi

found_files=$(find "$dir" -name "*.$ext")

if [ -z "$found_files" ]; then
    echo "Файлы с расширением .$ext не найдены."
else
    echo "Найденные файлы с расширением .$ext:"
    echo "$found_files"
fi

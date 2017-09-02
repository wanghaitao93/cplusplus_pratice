#! /bin/bash

if [[ $1 == "" || $1 == "-h" || $1 == "-help" ]]
then
    echo "
\$RUN [file_name]
    
    usage:
        \$RUN my_test.c 
            ~~ this will complie output file my_test , then run my_test procedure 
        "
    exit
fi

if [[ $1 == *".cpp" ]]
then
    length=${#1}-4
    execute=g++
elif [[ $1 == *".c" ]] 
then
    length=${#1}-2
    execute=gcc
else
    echo "this procedure not C/C++, please check you procedure !"
    exit
fi

echo 'start run procedure...'
file_name=${1:0:$length}
$execute -o $file_name $1
./$file_name
echo 'end run procedure...'

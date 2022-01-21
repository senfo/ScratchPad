#!/bin/bash

declare -a parameters=()
declare -A flags=( ["u"]="User name" ["p"]="User password" ["r"]="Role" )

usage () {
    for flag in "${!flags[@]}"; do
        echo "-$flag: ${flags[$flag]}"
    done
}

# Loops through each of the items in the hash and echos them
show () {
    for parameter in ${!parameters[@]}; do
        echo ${parameters[$parameter]}
    done
}

for flag in "${!flags[@]}"; do
    parameters+=($flag)
done

# Add a parameter to handle help
parameters+=(\?)

# Join the parameters array, seperating by comma
options=$(IFS=: ; echo "${parameters[*]}")
#echo $options

while getopts ${options} flag
do
    case "${flag}" in
        u) username=${OPTARG};;
        p) password=${OPTARG};;
        r) role=${OPTARG};;
        \?) usage; exit;;
    esac
done

if [ -z ${username} ]; then
    echo "Username required"
    exit
fi

if [ -z ${role} ]; then
    echo "Role required";
    exit
fi

if [ -z ${password} ]; then
    echo -n "User password: "
    read -s password
fi

echo "User: ${username}  -  Password: ${password}  -  Role: ${role}"

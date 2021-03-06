#!/bin/sh
cd $(dirname $0)

if [[ $# -ne 3 ]]; then
    echo "<usage>: mkc <contest> <name> <problem_num>"
    echo "<contest> := abc arc agc cf topcoder other"
    exit 1
fi

contest=$1
name=$2
number=$3
filenames=("A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N" "O" "P" "Q" "R" "S" "T" "U" "V" "W" "X" "Y" "Z")

if [[ ${contest} = "abc" ]]; then
    mkdir -p ./src/abc/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./src/abc/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./src/abc/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(ABC'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./src/abc/${name}/CMakeLists.txt
    done
    exit 0
fi

if [[ ${contest} = "arc" ]]; then
    mkdir -p ./src/arc/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./src/arc/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./src/arc/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(ARC'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./src/arc/${name}/CMakeLists.txt
    done
    exit 0
fi

if [[ ${contest} = "agc" ]]; then
    mkdir -p ./src/agc/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./src/agc/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./src/agc/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(AGC'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./src/agc/${name}/CMakeLists.txt
    done
    exit 0
fi

if [[ ${contest} = "cf" ]]; then
    mkdir -p ./codeforces/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./codeforces/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./codeforces/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(CF'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./codeforces/${name}/CMakeLists.txt
    done
    exit 0
fi

if [[ ${contest} = "topcoder" ]]; then
    mkdir -p ./topcoder/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./topcoder/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./topcoder/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(TC'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./topcoder/${name}/CMakeLists.txt
    done
    exit 0
fi

if [[ ${contest} = "other" ]]; then
    mkdir -p ./src/${name}
    echo 'set(CMAKE_CXX_COMPILER "/usr/local/bin/g++" CACHE string "g++ compiler" FORCE)\nset(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")' > ./src/${name}/CMakeLists.txt
    for i in $(seq 1 ${number})
    do
        cp ./temp.cpp ./src/${name}/${filenames[$((i - 1))]}.cpp
        echo 'add_executable(OTHER'${name}${filenames[$((i - 1))]}' '${filenames[$((i - 1))]}.cpp')' >> ./src/${name}/CMakeLists.txt
    done
    exit 0
fi
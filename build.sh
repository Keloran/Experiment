#!/bin/bash
deleteIt()
{
    keepBuild=$1

    rm -rf `find . -type f -name CMakeCache.txt`
    rm -rf `find . -type d -name CMakeFiles`
    rm -rf `find . -type f -name CPackConfig.cmake`
    rm -rf `find . -type f -name CPackSourceConfig.cmake`
    rm -rf `find . -type f -name Makefile`
    rm -rf `find . -type f -name cmake_install.cmake`

    if [[ $keepBuild == 0 ]]; then
        rm -rf `find . -type f -name Experiments.app`
    fi
}

makeIt()
{
    cmake .
    make
}


runIt()
{
    cd Build
    ./Experiments.app
}

deleteIt 0
makeIt
deleteIt 1
runIt

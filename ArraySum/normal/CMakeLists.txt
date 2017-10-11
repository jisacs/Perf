cmake_minimum_required (VERSION 2.6)


#Génération de la liste des fichiers sources
file(
        GLOB_RECURSE
        source_files
        ${CMAKE_SOURCE_DIR}/ArraySum/*
)

list(APPEND source_files ";${CMAKE_SOURCE_DIR}/Tools/cpuclock.cpp")

#Déclaration de l'exécutable
add_executable(
        normal_array_sum
        ${source_files}
)

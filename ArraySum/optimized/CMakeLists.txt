cmake_minimum_required (VERSION 2.6)


#Génération de la liste des fichiers sources
file(
        GLOB_RECURSE
        source_files
        ${CMAKE_SOURCE_DIR}/ArraySum/*
)

list(APPEND source_files ";${CMAKE_SOURCE_DIR}/Tools/cpuclock.cpp")

SET(GCC_COVERAGE_COMPILE_FLAGS " -O3")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


#Déclaration de l'exécutable
add_executable(
        optimized_array_sum
        ${source_files}
)

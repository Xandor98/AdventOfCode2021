# CMakeList.txt: CMake-Projekt für "AOC2021". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

set(SOURCE_FILES AOC2021.cpp AOC2021.h)

include_directories(Helper)
include_directories(Day01)

link_directories(Helper)
link_directories(Day01)

add_subdirectory(Helper)
add_subdirectory(Day01)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (${PROJECT_NAME} ${SOURCE_FILES})

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
target_link_libraries(${PROJECT_NAME} Days Day01)
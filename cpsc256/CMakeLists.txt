cmake_minimum_required(VERSION 3.25)
project(cpsc256)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

add_executable(HelloWorld Examples/Week1/HelloWorld/main.c)
add_executable(PrimitiveDataTypes Examples/Week1/PrimitiveDataTypes/main.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week2/FileReader)
add_executable(FileReader Examples/Week2/FileReader/main.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week2/CSVFileReader)
add_executable(CSVFileReader Examples/Week2/CSVFileReader/main.c)

add_executable(Declarations Examples/Week3/Declarations/main.c)
add_executable(FormatSpecifiers Examples/Week3/FormatSpecifiers/main.c)
add_executable(FunctionExample Examples/Week3/FunctionExample/main.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week3/FileStatistics)
add_executable(FileStatistics Examples/Week3/FileStatistics/main.c Examples/Week3/FileStatistics/mean.c Examples/Week3/FileStatistics/stdev.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week3/FileStatistics_Headers)
add_executable(FileStatistics_Headers Examples/Week3/FileStatistics_Headers/main.c Examples/Week3/FileStatistics_Headers/mean.c Examples/Week3/FileStatistics_Headers/stdev.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week4/BasicPointers)
add_executable(BasicPointers Examples/Week4/BasicPointers/main.c Examples/Week4/BasicPointers/functions.c)
add_executable(VoidPointers Examples/Week4/VoidPointers/main.c)
add_executable(QuickSort Examples/Week4/QuickSort/main.c)

add_executable(Restaurant_C_Example Examples/Week5/Restaurant_C_Example/main.c)
add_executable(PointerCar Examples/Week5/PointerCar/main.c Examples/Week5/PointerCar/PointerCar.c)
add_executable(SimpleCar Examples/Week5/SimpleCar/main.c Examples/Week5/SimpleCar/SimpleCar.c)

# Other Examples
add_executable(HelloWorldCPP Examples/Week6/HelloWorldCPP/main.cpp)
add_executable(BasicObjects Examples/Week6/BasicObjects/main.cpp Examples/Week6/BasicObjects/Restaurant.cpp)
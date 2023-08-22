cmake_minimum_required(VERSION 3.25)
project(cpsc256)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

add_executable(HelloWorld Examples/HelloWorld/main.c)
add_executable(PrimitiveDataTypes Examples/PrimitiveDataTypes/main.c)
add_executable(HelloWorldCPP Examples/HelloWorldCPP/main.cpp)
add_executable(Declarations Examples/Declarations/main.c)
add_executable(BasicLinkedList Examples/BasicLinkedList/main.cpp Examples/BasicLinkedList/IntNode.cpp)
add_executable(MultipleClasses Examples/MultipleClasses/main.cpp)
add_executable(BasicPointers Examples/BasicPointers/main.c)
add_executable(GitHubCoPilot Examples/GitHubCoPilot/main.cpp)
add_executable(ArtistAndArtwork Examples/ArtistAndArtwork/main.cpp Examples/ArtistAndArtwork/Artist.cpp Examples/ArtistAndArtwork/Artwork.cpp
        Examples/PrimitiveDataTypes/main.c)
add_executable(PointerCar Examples/PointerCar/main.c Examples/PointerCar/PointerCar.c)
add_executable(SimpleCar Examples/SimpleCar/main.c Examples/SimpleCar/SimpleCar.c)
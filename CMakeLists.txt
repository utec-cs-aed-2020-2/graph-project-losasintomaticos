cmake_minimum_required(VERSION 3.17)
project(graph-project-losasintomaticos)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph-project-losasintomaticos main.cpp Graph/DirectedGraph.h Graph/UndirectedGraph.h Graph/graph.h Parser/Data/airports.json Graph/parser.h Parser/Data/pe.json)

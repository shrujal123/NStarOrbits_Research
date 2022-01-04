cmake_minimum_required(VERSION 3.10)

#set the project name
project(Test)
set(my_sourceFiles ${PROJECT_SOURCE_DIR}/source/func.cpp ${PROJECT_SOURCE_DIR}/source/header.cpp ${PROJECT_SOURCE_DIR}/source/helloWorld.cpp ${PROJECT_SOURCE_DIR}/source/test.cpp )
set(GDP_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
#include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(run ${my_sourceFiles})

set_target_properties(
	run
	PROPERTIES
	INCLUDE_DIRECTORIES "${GDP_INCLUDE_DIRS}"
	#COMPILE_DEFINITIONS "${GDP_COMPILE_DEFINITIONS}"
	#COMPILE_FLAGS "${GDP_COMPILE_FLAGS}"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
	OUTPUT_NAME "run"
)

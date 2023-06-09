cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 7: Create a variable USE_MYMATH using option and set default to ON
# option(<variable> "<help_text>" [value]) Provide a boolean option that the user can optionally select/send as build argument
# value can be "ON" or "OFF", If no initial <value> is provided, boolean OFF is the default value.
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 8: Use list() and APPEND to create a list of optional libraries
# called  EXTRA_LIBS and a list of optional include directories called
# EXTRA_INCLUDES. Add the MathFunctions library and source directory to
# the appropriate lists.
#
# Only call add_subdirectory and only add MathFunctions specific values
# to EXTRA_LIBS and EXTRA_INCLUDES if USE_MYMATH is ON.
if(USE_MYMATH)
  add_subdirectory(MathFunctions) # this will build the library based on directory
  list(APPEND EXTRA_LIBS MathFunctions) # just storing the value as "MathFunctions"
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions") # just storing value like above
endif()
# like set() command, the list() command creates new variable values in the current scope
# list( subcommand variable_name variable_value )
# A list in cmake is a ; separated group of strings.
# subcommands can be APPEND, INSERT, FILTER, PREPEND, POP_BACK, POP_FRONT, REMOVE_AT, REMOVE_ITEM, REMOVE_DUPLICATES, REVERSE and SOR
# https://cmake.org/cmake/help/latest/command/list.html#command:list

# TODO 2: Use add_subdirectory() to add MathFunctions to this project
# add_subdirectory(MathFunctions)
# commented to make optional Library Include

# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 9: Use EXTRA_LIBS instead of the MathFunctions specific values
# in target_link_libraries.
# target_link_libraries(Tutorial PUBLIC MathFunctions)
# commented to include library optionally
# if EXTRA_LIBS are set in list, it will return value, otherwise empty
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS}) # this actually link the library

# TODO 3: Use target_link_libraries to link the library to our executable

# TODO 4: Add MathFunctions to Tutorial's target_include_directories()
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!

# TODO 10: Use EXTRA_INCLUDES instead of the MathFunctions specific values
# in target_include_directories.

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# target_include_directories(Tutorial PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            "${PROJECT_SOURCE_DIR}/MathFunctions"
#                            )
# commented to make optional Library Include
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Clank_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Clank_autogen.dir\\ParseCache.txt"
  "Clank_autogen"
  )
endif()

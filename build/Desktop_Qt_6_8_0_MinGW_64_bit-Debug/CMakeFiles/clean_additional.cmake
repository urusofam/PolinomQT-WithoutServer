# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\praktika4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\praktika4_autogen.dir\\ParseCache.txt"
  "praktika4_autogen"
  )
endif()

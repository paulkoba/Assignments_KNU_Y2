# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/explorer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/explorer_autogen.dir/ParseCache.txt"
  "explorer_autogen"
  )
endif()

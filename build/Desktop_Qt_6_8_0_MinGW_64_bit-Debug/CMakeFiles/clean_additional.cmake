# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PngPacker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PngPacker_autogen.dir\\ParseCache.txt"
  "PngPacker_autogen"
  )
endif()

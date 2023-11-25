# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CourseWork_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CourseWork_autogen.dir/ParseCache.txt"
  "CourseWork_autogen"
  )
endif()

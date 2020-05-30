cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# should we use our own math functions?
option (USE_MYMATH
        "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
#
if (USE_MYMATH)
  # 帮助源代码找头文件路径，这样源代码可以直接include ${PROJECT_SOURCE_DIR}/MathFunctions下的头文件
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  # MathFunctions目录下的 CMakeLists.txt 文件和源代码也会被处理
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable (Tutorial tutorial.cc)
target_link_libraries (Tutorial  ${EXTRA_LIBS})


cmake_minimum_required(VERSION 3.2)


find_path(GMP_INCLUDE_DIRS NAMES gmp.h gmpxx.h)
find_library(GMP_LIBRARY NAMES gmp gmpxx)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP 
	DEFAULT_MSG
	GMP_INCLUDE_DIRS
	GMP_LIBRARY
)
# mark_as_advanced(GMP_INCLUDE_DIRS GMP_LIBRARY)

message(${GMP_INCLUDE_DIRS})
message(${GMP_LIBRARY})


add_executable(gmptest gmptest.cpp)

set_target_properties(gmptest PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_include_directories(gmptest PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${GMP_INCLUDE_DIRS}
)

target_link_libraries(gmptest
	gmp
	gmpxx
	)



add_executable(cbntest cbntest.cpp)

set_target_properties(cbntest PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_include_directories(cbntest PRIVATE
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_CURRENT_BINARY_DIR}
)


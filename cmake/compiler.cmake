##======================================================================================================================
##  Kyosu - Complex Math Made Easy
##  Copyright : TTS Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Compiler options
##======================================================================================================================
add_library(kyosu_test INTERFACE)

target_compile_features ( kyosu_test INTERFACE  cxx_std_20 )

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_options( kyosu_test INTERFACE /W3 /EHsc )
  else()
    target_compile_options( kyosu_test INTERFACE -Werror -Wall -Wextra -Wunused-variable -Wdocumentation)
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options( kyosu_test INTERFACE /W3 /EHsc /Zc:preprocessor)
else()
  target_compile_options( kyosu_test INTERFACE -Werror -Wall -Wextra -Wunused-variable)
endif()

target_include_directories( kyosu_test INTERFACE
                            ${PROJECT_SOURCE_DIR}/test
                            ${PROJECT_SOURCE_DIR}/include
                          )

target_link_libraries(kyosu_test INTERFACE eve::eve)

project(DirectXMath_Tests)
cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(../Extensions)
include_directories(../Inc)
include_directories(../SHMath)
include_directories(../XDSP)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  add_compile_options(-Wno-attributes)
  add_compile_options(-Wno-deprecated-declarations)
  add_compile_options(-Wno-format)
endif()

###Extensions/AVX
add_executable(test_ext_avx
        ext/testavx.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_avx PRIVATE "-mavx")
endif()

###Extensions/AVX2
add_executable(test_ext_avx2
        ext/testavx2.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_avx2 PRIVATE "-mavx2")
  target_compile_options(test_ext_avx2 PRIVATE "-mfma")
endif()

###Extensions/BE
add_executable(test_ext_be
 ext/testbe.cpp
)	
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		target_compile_options(test_ext_be PRIVATE "-mssse3")
endif()

###Extensions/F16C
add_executable(test_ext_f16c
        ext/testf16c.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_f16c PRIVATE "-mf16c")
endif()

###Extensions/FMA3
add_executable(test_ext_fma3
        ext/testfma3.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_fma3 PRIVATE "-mfma")
endif()

###Extensions/FMA4
add_executable(test_ext_fma4
        ext/testfma4.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_fma4 PRIVATE "-mfma4")
endif()

###Extensions/SSE3
add_executable(test_ext_sse3
        ext/testsse3.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_sse3 PRIVATE "-msse3")
endif()

###Extensions/SSE4
add_executable(test_ext_sse4
        ext/testsse4.cpp
        )
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_ext_sse4 PRIVATE "-msse4")
endif()

###MATH3
set(MATH3_SRCS
  math3/box.cpp  
  math3/constexpr.cpp
  math3/frustum.cpp
  math3/hdrtest.cpp
  math3/math3.cpp
  math3/math3.h
  math3/math3tests.cpp
  math3/nomovnttest.cpp
  math3/permissive.cpp
  math3/obox.cpp
  math3/shared.cpp
  math3/sphere.cpp
  math3/triangle.cpp
  math3/xmcolor.cpp
  math3/xmmat.cpp
  math3/xmquat.cpp
  math3/xmvec.cpp
  math3/xmvec234.cpp
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  list(APPEND MATH3_SRCS "math3/clangcompat.cpp")
endif()

if(MSVC)
  list(APPEND MATH3_SRCS "math3/cpp17compat.cpp")
endif()

add_executable(test_math3_avx2_f16c_fma3 ${MATH3_SRCS})
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_math3_avx2_f16c_fma3 PRIVATE "-mavx2")
  target_compile_options(test_math3_avx2_f16c_fma3 PRIVATE "-mf16c")
  target_compile_options(test_math3_avx2_f16c_fma3 PRIVATE "-mfma")
endif()

add_executable(test_math3_avx2 ${MATH3_SRCS})
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(test_math3_avx2 PRIVATE "-mavx2")
endif()

###SHMath
add_executable(test_shmath
  shmath/test.cpp
  ../SHMath/DirectXSH.cpp
)

###XDSP
add_executable(test_xdsp
  xdsp/Test.cpp
)

function(target_set_warnings)
  set(oneValueArgs TARGET ENABLE AS_ERRORS)
  cmake_parse_arguments(
    TARGET_SET_WARNINGS
    "${options}"
    "${oneValueArgs}"
    "${multiValueArgs}"
    ${ARGN}
  ) 
  if (NOT ${TARGET_SET_WARNINGS_ENABLE})
    message(STATUS "Warnings disabled for: ${TARGET}")
    return()
  endif()

  set(MSVC_WARNINGS
    /W4
    /permissive-
  )
  
  set(CLANG_WARNINGS
    -Wall
    -Wextra 
    -Wpedantic 
  )

  set(GCC_WARNINGS ${CLANG_WARNINGS})

  if(${TARGET_SET_WARNINGS_AS_ERRORS})
    set(MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
    set(CLANGE_WARNINGS ${CLANG_WARNINGS} -Werror)
    set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
  endif()

  if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(WARNINGS ${MSVC_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
    set(WARNINGS ${CLANG_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(WARNINGS ${GCC_WARNINGS})
  endif()

  target_compile_options(${TARGET_SET_WARNINGS_TARGET} PRIVATE ${WARNINGS})
  message(STATUS ${WARNINGS})
endfunction()
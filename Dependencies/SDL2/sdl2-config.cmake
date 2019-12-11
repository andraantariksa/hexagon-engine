set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

if(WIN32)
  # Support both 32 and 64 bit builds
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
  else ()
    set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
  endif ()
else(WIN32)
  SET(SDL2_SEARCH_PATHS
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
    /sw # Fink
    /opt/local # DarwinPorts
    /opt/csw # Blastwave
    /opt
  )

  FIND_LIBRARY(SDL2_LIBRARIES
    NAMES SDL2
    HINTS
    $ENV{SDL2DIR}
    PATH_SUFFIXES lib64 lib
    PATHS ${SDL2_SEARCH_PATHS}
  )
endif(WIN32)


string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

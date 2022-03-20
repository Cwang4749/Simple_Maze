add_library(Yam SHARED Yam.h YamApp.h YamUtility.h YamApp.cpp)

add_definitions(-DYAM_LIB)
add_definitions(-DYAM_DEBUG)
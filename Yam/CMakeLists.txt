set(HEADER_FILES 
	Yam.h
	YamApp.h
	YamUtility.h
	GmWin.h
	Window.h
	UseGlfw/GlfwWin.h
	)

set(SOURCE_FILES 
	YamApp.cpp
	GmWin.cpp
	UseGlfw/GlfwWin.cpp
	)

add_library(Yam SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DYAM_LIB)
add_definitions(-DYAM_DEBUG)

include_directories(../glfw/include)
include_directories(../Yam)


target_precompile_headers(Yam PRIVATE PrecompH.h)

target_link_libraries(Yam glfw)
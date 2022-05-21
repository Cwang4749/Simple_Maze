set(HEADER_FILES
	Entity.h
	FreeApp.h
)

set(SOURCE_FILES
	Entity.cpp
	FreeApp.cpp
	main.cpp
)

add_executable(Free ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Yam)

target_link_libraries(Free Yam)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Free)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
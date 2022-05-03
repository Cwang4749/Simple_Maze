set(HEADER_FILES 
	Yam.h
	YamApp.h
	YamUtility.h
	GmWin.h
	Window.h
	UseGlfw/GlfwWin.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteType.h
	ShaderImplementation.h
	RendererType.h
	UseOGL/oglSprite.h
	UseOGL/oglShader.h
	UseOGL/oglRenderer.h
	)

set(SOURCE_FILES 
	YamApp.cpp
	GmWin.cpp
	UseGlfw/GlfwWin.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	UseOGL/oglSprite.cpp
	UseOGL/oglShader.cpp
	UseOGL/oglRenderer.cpp
	)

add_library(Yam SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DYAM_LIB)
add_definitions(-DYAM_DEBUG)
add_definitions(-DYAM_OPENGL)

include_directories(../glfw/include)
include_directories(../Yam)
include_directories(../stbi)
include_directories(../glad/include)


target_precompile_headers(Yam PRIVATE PrecompH.h)

target_link_libraries(Yam glfw glad stbi)
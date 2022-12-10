INCLUDE(../CMake/Base.cmake)

SET(SOURCES
	main.cpp
)

SET(HEADERS
)

SET(DEPENDENCIES
	SlangBase64
)

SET(MODULES
	SlangBase64
)

add_include(Extension)
add_external(${BUILD_SLANG_INC})

link_directories( ${BUILD_SLANG_LIB} )

SET(EXECUTABLE_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/spec)
build_app(spec "${MODULES}")


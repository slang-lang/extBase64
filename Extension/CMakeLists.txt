INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    Extension.cpp
    Types.cpp
)

SET(HEADERS
    base64_decode.h
    base64_encode.h
    Defines.h
    Extension.h
    Types.h
)

SET(DEPENDENCIES
    Core
)

SET(MODULES
    slang
)

add_include( Externals/2.rc.09 )

build_shared_lib( SlangBase64 "${MODULES}" )

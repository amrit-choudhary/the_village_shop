set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_MACOSX_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/lib")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include)

add_library(spdlog SHARED IMPORTED)
set_target_properties(spdlog PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/lib/libspdlog.1.15.dylib"
)

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/lib)


file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(TheVillageShop_Client ${SOURCES})

target_link_libraries(TheVillageShop_Client PRIVATE spdlog)

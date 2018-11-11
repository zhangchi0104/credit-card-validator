add_subdirectory(libs)
include_directories(../include)
link_libraries(funcLibs)
add_executable(creditCardValidator main.c)


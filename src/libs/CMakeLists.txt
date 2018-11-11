include_directories(../../include)
aux_source_directory(. libsrc)
add_library(funcLibs ${libsrc})

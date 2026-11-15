add_executable(patrouille
        main.cc
        src/garde.cc
        src/salle.cc)

target_include_directories(patrouille PRIVATE include)
target_link_libraries(patrouille PRIVATE SFML::Graphics)

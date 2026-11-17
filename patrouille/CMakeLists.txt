add_executable(patrouille
        main.cc
        src/garde.cc
        src/salle.cc)

target_include_directories(patrouille PRIVATE include)
target_link_libraries(patrouille PRIVATE SFML::Graphics)

# Les assets voyagent avec le binaire : data/ est copie a cote de l'executable.
copy_data(patrouille)

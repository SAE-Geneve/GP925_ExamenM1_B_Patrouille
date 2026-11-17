add_executable(patrouille
        main.cc
        src/garde.cc
        src/salle.cc)

target_include_directories(patrouille PRIVATE include)
target_link_libraries(patrouille PRIVATE SFML::Graphics)

# Les assets sont livres avec le projet : le chemin est cable ici, pas devine a l'execution.
target_compile_definitions(patrouille PRIVATE
        DOSSIER_DES_ASSETS="${CMAKE_CURRENT_SOURCE_DIR}/assets")

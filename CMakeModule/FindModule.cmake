# GLAD
set(GLAD_HEADER_PATH lib/openGL/glad/include)
set(GLAD_C_PATH lib/openGL/glad/src)

list(APPEND HEADER_PATH ${GLAD_HEADER_PATH})

aux_source_directory(${GLAD_C_PATH} ALL_SRC)

# GLFW
set(GLFW_HEADER_PATH lib/openGL/glfw-3.3.8.bin.WIN64/include)
set(GLFW_LIB_PATH lib/openGL/glfw-3.3.8.bin.WIN64/lib-mingw-w64)

list(APPEND HEADER_PATH ${GLFW_HEADER_PATH})

link_directories(${GLFW_LIB_PATH})

# GLM
set(GLM_HEADER_PATH lib/openGL/glm)

list(APPEND HEADER_PATH ${GLM_HEADER_PATH})

# stb
set(STB_PATH lib/stb)

list(APPEND HEADER_PATH ${STB_PATH})

aux_source_directory(${STB_PATH} ALL_SRC)

# JSON
set(JSON_HEADER_PATH lib/JSON)

list(APPEND HEADER_PATH ${JSON_HEADER_PATH})

# freetype
set(FREETYPE_HEADER_PATH lib/freetype2)
set(FREETYPE_LIB_PATH lib/freetype2/lib)

list(APPEND HEADER_PATH ${FREETYPE_HEADER_PATH})

LINK_DIRECTORIES(${FREETYPE_LIB_PATH})

# ImGui
set(IMGUI_PATH lib/ImGui)

list(APPEND HEADER_PATH ${IMGUI_PATH})

aux_source_directory(${IMGUI_PATH} ALL_SRC)
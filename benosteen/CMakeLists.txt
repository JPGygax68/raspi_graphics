project(RPes2pg)

add_library(${PROJECT_NAME} STATIC esShader.c esShapes.c esTransform.c esUtil.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLES_INC})
target_compile_definitions(${PROJECT_NAME} PRIVATE RPI_NO_X PI_DISPLAY=4)
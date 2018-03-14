cmake_minimum_required(VERSION 3.0)

project(gfxtest)

set(DMX_INC "/opt/vc/include;/opt/vc/include/interface/vmcs_host/;/opt/vc/include/interface/vcos/pthreads;/opt/vc/include/interface/;vmcs_host/linux")
set(DMX_LIBDIRS "/opt/vc/lib/")
set(DMX_LIBS "bcm_host;vcos;vchiq_arm;pthread")

set(EGL_LIBDIRS "/opt/vc/lib/")
set(EGL_LIBS "EGL;GLESv2")

link_directories(${DMX_LIBDIRS} ${EGL_LIBDIRS})

add_executable(gfxtest main.cpp display.cpp)

target_include_directories(gfxtest PRIVATE ${DMX_INC})
target_link_libraries(gfxtest PRIVATE ${DMX_LIBS} ${EGL_LIBS})
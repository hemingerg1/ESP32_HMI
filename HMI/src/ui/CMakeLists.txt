SET(SOURCES components/ui_comp_fullscreen.c
    components/ui_comp.c
    screens/ui_ScrHome.c
    screens/ui_ScrTemp.c
    screens/ui_ScrAQ.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_home_png.c)

add_library(ui ${SOURCES})

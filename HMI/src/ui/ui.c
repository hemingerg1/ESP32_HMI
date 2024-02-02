// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_ScrHome
void ui_ScrHome_screen_init(void);
lv_obj_t * ui_ScrHome;
lv_obj_t * ui_FullScreen;
void ui_event_FullScreen_Sidebar3_butTemp2(lv_event_t * e);
void ui_event_FullScreen_Sidebar3_butAQ2(lv_event_t * e);
lv_obj_t * ui_Label1;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label2;
lv_obj_t * ui_count;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label5;


// SCREEN: ui_ScrCharts
void ui_ScrCharts_screen_init(void);
lv_obj_t * ui_ScrCharts;
lv_obj_t * ui_FullScreen1;
void ui_event_FullScreen1_Sidebar3_butHome2(lv_event_t * e);
void ui_event_FullScreen1_Sidebar3_butAQ2(lv_event_t * e);
lv_obj_t * ui_Chart1;
void ui_event_but2H(lv_event_t * e);
lv_obj_t * ui_but2H;
lv_obj_t * ui_Label3;
void ui_event_but30m(lv_event_t * e);
lv_obj_t * ui_but30m;
lv_obj_t * ui_Label7;
void ui_event_but1H(lv_event_t * e);
lv_obj_t * ui_but1H;
lv_obj_t * ui_Label6;
void ui_event_butTemp(lv_event_t * e);
lv_obj_t * ui_butTemp;
lv_obj_t * ui_Label8;
void ui_event_butAQ(lv_event_t * e);
lv_obj_t * ui_butAQ;
lv_obj_t * ui_Label9;
void ui_event_butPM(lv_event_t * e);
lv_obj_t * ui_butPM;
lv_obj_t * ui_Label10;
void ui_event_butHum(lv_event_t * e);
lv_obj_t * ui_butHum;
lv_obj_t * ui_Label11;


// SCREEN: ui_ScrTBD
void ui_ScrTBD_screen_init(void);
lv_obj_t * ui_ScrTBD;
lv_obj_t * ui_FullScreen2;
void ui_event_FullScreen2_Sidebar3_butHome2(lv_event_t * e);
void ui_event_FullScreen2_Sidebar3_butTemp2(lv_event_t * e);
lv_obj_t * ui_Label4;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_736952691[1] = {&ui_img_2110918543};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_FullScreen_Sidebar3_butTemp2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrCharts, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrCharts_screen_init);
    }
}
void ui_event_FullScreen_Sidebar3_butAQ2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrTBD, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrTBD_screen_init);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        add(e);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        sub(e);
    }
}
void ui_event_FullScreen1_Sidebar3_butHome2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrHome, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrHome_screen_init);
    }
}
void ui_event_FullScreen1_Sidebar3_butAQ2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrTBD, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrTBD_screen_init);
    }
}
void ui_event_but2H(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chart2H(e);
    }
}
void ui_event_but30m(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chart30m(e);
    }
}
void ui_event_but1H(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chart1H(e);
    }
}
void ui_event_butTemp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chartTemp(e);
    }
}
void ui_event_butAQ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chartAQ(e);
    }
}
void ui_event_butPM(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chartPM(e);
    }
}
void ui_event_butHum(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        chartHum(e);
    }
}
void ui_event_FullScreen2_Sidebar3_butHome2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrHome, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrHome_screen_init);
    }
}
void ui_event_FullScreen2_Sidebar3_butTemp2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_ScrCharts, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_ScrCharts_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScrHome_screen_init();
    ui_ScrCharts_screen_init();
    ui_ScrTBD_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScrHome);
}

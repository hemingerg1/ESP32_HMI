// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScrTBD_screen_init(void)
{
    ui_ScrTBD = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScrTBD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_FullScreen2 = ui_FullScreen_create(ui_ScrTBD);
    lv_obj_set_x(ui_FullScreen2, 0);
    lv_obj_set_y(ui_FullScreen2, 0);




    lv_obj_set_style_bg_color(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTAQ2), lv_color_hex(0xA6A6A6),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTAQ2), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Label4 = lv_label_create(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Settings Page");
    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_setTabView = lv_tabview_create(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_CONTENTCONTAINER), LV_DIR_TOP,
                                      50);
    lv_obj_set_width(ui_setTabView, lv_pct(100));
    lv_obj_set_height(ui_setTabView, lv_pct(100));
    lv_obj_set_align(ui_setTabView, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_setTabView, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    ui_setTabPage = lv_tabview_add_tab(ui_setTabView, "Settings");
    lv_obj_set_style_border_color(ui_setTabPage, lv_color_hex(0x204052), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_setTabPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_setTabPage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_logTabPage = lv_tabview_add_tab(ui_setTabView, "Log");
    lv_obj_set_style_border_color(ui_logTabPage, lv_color_hex(0x204052), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_logTabPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_logTabPage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_logLab = lv_label_create(ui_logTabPage);
    lv_obj_set_width(ui_logLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_logLab, LV_SIZE_CONTENT);    /// 1

    lv_obj_add_event_cb(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTHOME2),
                        ui_event_FullScreen2_Sidebar3_butHome2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTTEMP2),
                        ui_event_FullScreen2_Sidebar3_butTemp2, LV_EVENT_ALL, NULL);

}

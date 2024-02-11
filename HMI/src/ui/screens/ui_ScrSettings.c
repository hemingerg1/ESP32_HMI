// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScrSettings_screen_init(void)
{
    ui_ScrSettings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScrSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_FullScreen2 = ui_FullScreen_create(ui_ScrSettings);
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
    lv_obj_set_style_pad_left(ui_setTabPage, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_setTabPage, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_setTabPage, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_setTabPage, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container6 = lv_obj_create(ui_setTabPage);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_height(ui_Container6, 40);
    lv_obj_set_width(ui_Container6, lv_pct(100));
    lv_obj_set_align(ui_Container6, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Container6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_butReboot = lv_btn_create(ui_Container6);
    lv_obj_set_width(ui_butReboot, 100);
    lv_obj_set_height(ui_butReboot, 40);
    lv_obj_set_align(ui_butReboot, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_butReboot, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_butReboot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_butReboot, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butReboot, lv_color_hex(0x3975F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_butReboot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butReboot, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_butReboot, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label15 = lv_label_create(ui_butReboot);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "Reboot");

    ui_butRewifi = lv_btn_create(ui_Container6);
    lv_obj_set_width(ui_butRewifi, 100);
    lv_obj_set_height(ui_butRewifi, 40);
    lv_obj_set_x(ui_butRewifi, 110);
    lv_obj_set_y(ui_butRewifi, 0);
    lv_obj_set_align(ui_butRewifi, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_butRewifi, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_butRewifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_butRewifi, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butRewifi, lv_color_hex(0x3975F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_butRewifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butRewifi, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_butRewifi, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label16 = lv_label_create(ui_butRewifi);
    lv_obj_set_width(ui_Label16, 100);
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "Reconnect to WiFi");
    lv_obj_set_style_text_align(ui_Label16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_butRemqtt = lv_btn_create(ui_Container6);
    lv_obj_set_width(ui_butRemqtt, 100);
    lv_obj_set_height(ui_butRemqtt, 40);
    lv_obj_set_x(ui_butRemqtt, 220);
    lv_obj_set_y(ui_butRemqtt, 0);
    lv_obj_set_align(ui_butRemqtt, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_butRemqtt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_butRemqtt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_butRemqtt, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butRemqtt, lv_color_hex(0x3975F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_butRemqtt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_butRemqtt, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_butRemqtt, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label17 = lv_label_create(ui_butRemqtt);
    lv_obj_set_width(ui_Label17, 100);
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "Reconnect to MQTT");
    lv_obj_set_style_text_align(ui_Label17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_logTabPage = lv_tabview_add_tab(ui_setTabView, "Log");
    lv_obj_set_style_border_color(ui_logTabPage, lv_color_hex(0x204052), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_logTabPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_logTabPage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_logLab = lv_label_create(ui_logTabPage);
    lv_obj_set_width(ui_logLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_logLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_clear_flag(ui_logLab, LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);      /// Flags
    lv_obj_set_scrollbar_mode(ui_logLab, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_logLab, LV_DIR_VER);

    lv_obj_add_event_cb(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTHOME2),
                        ui_event_FullScreen2_Sidebar3_butHome2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_FullScreen2, UI_COMP_FULLSCREEN_SIDEBAR3_BUTTEMP2),
                        ui_event_FullScreen2_Sidebar3_butTemp2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_butReboot, ui_event_butReboot, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_butRewifi, ui_event_butRewifi, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_butRemqtt, ui_event_butRemqtt, LV_EVENT_ALL, NULL);

}
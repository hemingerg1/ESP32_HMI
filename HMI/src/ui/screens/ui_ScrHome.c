// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScrHome_screen_init(void)
{
    ui_ScrHome = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScrHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScrHome, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScrHome, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    ui_HomeScreen = ui_FullScreen_create(ui_ScrHome);
    lv_obj_set_x(ui_HomeScreen, 0);
    lv_obj_set_y(ui_HomeScreen, 0);



    lv_obj_set_style_bg_color(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_SIDEBAR3_BUTHOME2),
                              lv_color_hex(0xA6A6A6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_SIDEBAR3_BUTHOME2), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_timeLab = lv_label_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_width(ui_timeLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_timeLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_timeLab, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_timeLab, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_timeLab, "--:--");
    lv_obj_set_style_text_align(ui_timeLab, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_timeLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AirPanel = lv_obj_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_height(ui_AirPanel, 100);
    lv_obj_set_width(ui_AirPanel, lv_pct(100));
    lv_obj_set_x(ui_AirPanel, 0);
    lv_obj_set_y(ui_AirPanel, 30);
    lv_obj_set_align(ui_AirPanel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_AirPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_AirPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AirPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_AirPanel, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AirPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AirPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_outTempPanel = lv_obj_create(ui_AirPanel);
    lv_obj_set_width(ui_outTempPanel, 140);
    lv_obj_set_height(ui_outTempPanel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_outTempPanel, -240);
    lv_obj_set_y(ui_outTempPanel, -133);
    lv_obj_set_align(ui_outTempPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_outTempPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_outTempPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_outTempPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_outTempPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_outTempPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_outTempPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_outTempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_outTempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_outTempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_outTempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempTitle1 = lv_label_create(ui_outTempPanel);
    lv_obj_set_width(ui_tempTitle1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_tempTitle1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_tempTitle1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_tempTitle1, "Outside Temp (F)");
    lv_obj_set_style_text_color(ui_tempTitle1, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_tempTitle1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_outTempLab = lv_label_create(ui_outTempPanel);
    lv_obj_set_width(ui_outTempLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_outTempLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_outTempLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_outTempLab, "--");
    lv_obj_set_style_text_font(ui_outTempLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempPanel = lv_obj_create(ui_AirPanel);
    lv_obj_set_width(ui_tempPanel, 140);
    lv_obj_set_height(ui_tempPanel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_tempPanel, -240);
    lv_obj_set_y(ui_tempPanel, -133);
    lv_obj_set_align(ui_tempPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_tempPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_tempPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_tempPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_tempPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_tempPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_tempPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_tempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_tempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_tempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_tempPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempTitle = lv_label_create(ui_tempPanel);
    lv_obj_set_width(ui_tempTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_tempTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_tempTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_tempTitle, "Inside Temp (F)");
    lv_obj_set_style_text_color(ui_tempTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_tempTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempLab = lv_label_create(ui_tempPanel);
    lv_obj_set_width(ui_tempLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_tempLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_tempLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_tempLab, "--");
    lv_obj_set_style_text_font(ui_tempLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_hmPanel = lv_obj_create(ui_AirPanel);
    lv_obj_set_width(ui_hmPanel, 140);
    lv_obj_set_height(ui_hmPanel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_hmPanel, -82);
    lv_obj_set_y(ui_hmPanel, -150);
    lv_obj_set_align(ui_hmPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_hmPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_hmPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_hmPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_hmPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_hmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_hmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_hmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_hmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_hmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_humTitle = lv_label_create(ui_hmPanel);
    lv_obj_set_width(ui_humTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_humTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_humTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_humTitle, "Humidity (%)");
    lv_obj_set_style_text_color(ui_humTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_humTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_humLab = lv_label_create(ui_hmPanel);
    lv_obj_set_width(ui_humLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_humLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_humLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_humLab, "--");
    lv_obj_set_style_text_font(ui_humLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aqPanel = lv_obj_create(ui_AirPanel);
    lv_obj_set_width(ui_aqPanel, 140);
    lv_obj_set_height(ui_aqPanel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aqPanel, 59);
    lv_obj_set_y(ui_aqPanel, -145);
    lv_obj_set_align(ui_aqPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_aqPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_aqPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_aqPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_aqPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aqPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aqPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_aqPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_aqPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_aqPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_aqPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aqTitle = lv_label_create(ui_aqPanel);
    lv_obj_set_width(ui_aqTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aqTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aqTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_aqTitle, "AQ (%)");
    lv_obj_set_style_text_color(ui_aqTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aqTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aqLab = lv_label_create(ui_aqPanel);
    lv_obj_set_width(ui_aqLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aqLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aqLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_aqLab, "--");
    lv_obj_set_style_text_font(ui_aqLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pmPanel = lv_obj_create(ui_AirPanel);
    lv_obj_set_width(ui_pmPanel, 140);
    lv_obj_set_height(ui_pmPanel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_pmPanel, 207);
    lv_obj_set_y(ui_pmPanel, -150);
    lv_obj_set_align(ui_pmPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_pmPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_pmPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_pmPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_pmPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_pmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_pmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_pmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_pmPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pmTitle = lv_label_create(ui_pmPanel);
    lv_obj_set_width(ui_pmTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_pmTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_pmTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_pmTitle, "PM 2.5");
    lv_obj_set_style_text_color(ui_pmTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pmTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pmLab = lv_label_create(ui_pmPanel);
    lv_obj_set_width(ui_pmLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_pmLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_pmLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_pmLab, "--");
    lv_obj_set_style_text_font(ui_pmLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DoorsPanel = lv_obj_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_height(ui_DoorsPanel, 90);
    lv_obj_set_width(ui_DoorsPanel, lv_pct(100));
    lv_obj_set_x(ui_DoorsPanel, 0);
    lv_obj_set_y(ui_DoorsPanel, 140);
    lv_obj_set_align(ui_DoorsPanel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_DoorsPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_DoorsPanel, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DoorsPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DoorsPanel, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DoorsPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DoorsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_doubleGdoorPanel = lv_obj_create(ui_DoorsPanel);
    lv_obj_remove_style_all(ui_doubleGdoorPanel);
    lv_obj_set_height(ui_doubleGdoorPanel, 60);
    lv_obj_set_width(ui_doubleGdoorPanel, lv_pct(23));
    lv_obj_set_x(ui_doubleGdoorPanel, -81);
    lv_obj_set_y(ui_doubleGdoorPanel, -35);
    lv_obj_set_align(ui_doubleGdoorPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_doubleGdoorPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_doubleGdoorPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_doubleGdoorPanel, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_clear_flag(ui_doubleGdoorPanel,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_doubleGdoorPanel, 10, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_doubleGdoorPanel, lv_color_hex(0xA71616), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_doubleGdoorPanel, 150, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_doublGdoorTitle = lv_label_create(ui_doubleGdoorPanel);
    lv_obj_set_width(ui_doublGdoorTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_doublGdoorTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_doublGdoorTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_doublGdoorTitle, "Large Garage Door");
    lv_obj_set_style_text_color(ui_doublGdoorTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_doublGdoorTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_doubleGdoorLab = lv_label_create(ui_doubleGdoorPanel);
    lv_obj_set_width(ui_doubleGdoorLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_doubleGdoorLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_doubleGdoorLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_doubleGdoorLab, "--");
    lv_obj_set_style_text_font(ui_doubleGdoorLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_outsidePdoorPanel = lv_obj_create(ui_DoorsPanel);
    lv_obj_remove_style_all(ui_outsidePdoorPanel);
    lv_obj_set_height(ui_outsidePdoorPanel, 60);
    lv_obj_set_width(ui_outsidePdoorPanel, lv_pct(23));
    lv_obj_set_x(ui_outsidePdoorPanel, -81);
    lv_obj_set_y(ui_outsidePdoorPanel, -35);
    lv_obj_set_align(ui_outsidePdoorPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_outsidePdoorPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_outsidePdoorPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_outsidePdoorPanel, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_clear_flag(ui_outsidePdoorPanel,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_outsidePdoorPanel, 10, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_outsidePdoorPanel, lv_color_hex(0xA71616), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_outsidePdoorPanel, 150, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_outsidePdoorTitle = lv_label_create(ui_outsidePdoorPanel);
    lv_obj_set_width(ui_outsidePdoorTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_outsidePdoorTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_outsidePdoorTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_outsidePdoorTitle, "Outside Door");
    lv_obj_set_style_text_color(ui_outsidePdoorTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_outsidePdoorTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_outsidePdoorTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_outsidePdoorLab = lv_label_create(ui_outsidePdoorPanel);
    lv_obj_set_width(ui_outsidePdoorLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_outsidePdoorLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_outsidePdoorLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_outsidePdoorLab, "--");
    lv_obj_set_style_text_font(ui_outsidePdoorLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_shopPdoorPanel = lv_obj_create(ui_DoorsPanel);
    lv_obj_remove_style_all(ui_shopPdoorPanel);
    lv_obj_set_height(ui_shopPdoorPanel, 60);
    lv_obj_set_width(ui_shopPdoorPanel, lv_pct(23));
    lv_obj_set_x(ui_shopPdoorPanel, -81);
    lv_obj_set_y(ui_shopPdoorPanel, -35);
    lv_obj_set_align(ui_shopPdoorPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_shopPdoorPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_shopPdoorPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_shopPdoorPanel, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_clear_flag(ui_shopPdoorPanel,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_shopPdoorPanel, 10, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_shopPdoorPanel, lv_color_hex(0xA71616), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_shopPdoorPanel, 150, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_shopPdoorTitle = lv_label_create(ui_shopPdoorPanel);
    lv_obj_set_width(ui_shopPdoorTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_shopPdoorTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_shopPdoorTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_shopPdoorTitle, "Shop Door");
    lv_obj_set_style_text_color(ui_shopPdoorTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_shopPdoorTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ShopPdoorLab = lv_label_create(ui_shopPdoorPanel);
    lv_obj_set_width(ui_ShopPdoorLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ShopPdoorLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ShopPdoorLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ShopPdoorLab, "--");
    lv_obj_set_style_text_font(ui_ShopPdoorLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_singleGdoorPanel = lv_obj_create(ui_DoorsPanel);
    lv_obj_remove_style_all(ui_singleGdoorPanel);
    lv_obj_set_height(ui_singleGdoorPanel, 60);
    lv_obj_set_width(ui_singleGdoorPanel, lv_pct(23));
    lv_obj_set_x(ui_singleGdoorPanel, -81);
    lv_obj_set_y(ui_singleGdoorPanel, -35);
    lv_obj_set_align(ui_singleGdoorPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_singleGdoorPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_singleGdoorPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_singleGdoorPanel, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_clear_flag(ui_singleGdoorPanel,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_singleGdoorPanel, 10, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_singleGdoorPanel, lv_color_hex(0xA71616), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_singleGdoorPanel, 150, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_singleGdoorTitle = lv_label_create(ui_singleGdoorPanel);
    lv_obj_set_width(ui_singleGdoorTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_singleGdoorTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_singleGdoorTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_singleGdoorTitle, "Small Garage Door");
    lv_obj_set_style_text_color(ui_singleGdoorTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_singleGdoorTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_singleGdoorLab = lv_label_create(ui_singleGdoorPanel);
    lv_obj_set_width(ui_singleGdoorLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_singleGdoorLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_singleGdoorLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_singleGdoorLab, "--");
    lv_obj_set_style_text_font(ui_singleGdoorLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VentPanel = lv_obj_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_width(ui_VentPanel, lv_pct(49));
    lv_obj_set_height(ui_VentPanel, lv_pct(48));
    lv_obj_set_align(ui_VentPanel, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_VentPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_VentPanel, lv_color_hex(0x212025), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VentPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VentPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VentPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VentPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VentPanel, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VentPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ventTitle = lv_label_create(ui_VentPanel);
    lv_obj_set_width(ui_ventTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ventTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ventTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_ventTitle, "Ventilation");
    lv_obj_set_style_text_color(ui_ventTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ventTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ventTitle, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container5 = lv_obj_create(ui_VentPanel);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, lv_pct(100));
    lv_obj_set_height(ui_Container5, lv_pct(80));
    lv_obj_set_align(ui_Container5, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_Container5, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_Container5, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_AROUND);
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ventStatCont = lv_obj_create(ui_Container5);
    lv_obj_remove_style_all(ui_ventStatCont);
    lv_obj_set_height(ui_ventStatCont, 60);
    lv_obj_set_width(ui_ventStatCont, lv_pct(40));
    lv_obj_set_x(ui_ventStatCont, -81);
    lv_obj_set_y(ui_ventStatCont, -35);
    lv_obj_set_align(ui_ventStatCont, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ventStatCont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ventStatCont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ventStatCont, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ventStatCont, 15, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ventStatCont, lv_color_hex(0x11580E), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ventStatCont, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ventStatTitle = lv_label_create(ui_ventStatCont);
    lv_obj_set_width(ui_ventStatTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ventStatTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ventStatTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ventStatTitle, "Status");
    lv_obj_set_style_text_color(ui_ventStatTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ventStatTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ventStatLab = lv_label_create(ui_ventStatCont);
    lv_obj_set_width(ui_ventStatLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ventStatLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ventStatLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ventStatLab, "--");
    lv_obj_set_style_text_font(ui_ventStatLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButVentOff = lv_btn_create(ui_Container5);
    lv_obj_set_width(ui_ButVentOff, 100);
    lv_obj_set_height(ui_ButVentOff, 50);
    lv_obj_set_x(ui_ButVentOff, 65);
    lv_obj_set_y(ui_ButVentOff, 61);
    lv_obj_set_align(ui_ButVentOff, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButVentOff, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButVentOff, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButVentOff, lv_color_hex(0x5A595A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButVentOff, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButVentOff, lv_color_hex(0xC81A1A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButVentOff, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label13 = lv_label_create(ui_ButVentOff);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "OFF");

    ui_ventTimerCont = lv_obj_create(ui_Container5);
    lv_obj_remove_style_all(ui_ventTimerCont);
    lv_obj_set_height(ui_ventTimerCont, 60);
    lv_obj_set_width(ui_ventTimerCont, lv_pct(40));
    lv_obj_set_x(ui_ventTimerCont, -82);
    lv_obj_set_y(ui_ventTimerCont, 33);
    lv_obj_set_align(ui_ventTimerCont, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ventTimerCont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ventTimerCont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ventTimerCont, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ventTimerCont, 15, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ventTimerCont, lv_color_hex(0x11580E), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ventTimerCont, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ventTimerTitle = lv_label_create(ui_ventTimerCont);
    lv_obj_set_width(ui_ventTimerTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ventTimerTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ventTimerTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ventTimerTitle, "Timer");
    lv_obj_set_style_text_color(ui_ventTimerTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ventTimerTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ventTimerLab = lv_label_create(ui_ventTimerCont);
    lv_obj_set_width(ui_ventTimerLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ventTimerLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ventTimerLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ventTimerLab, "--");
    lv_obj_set_style_text_font(ui_ventTimerLab, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButVent5m = lv_btn_create(ui_Container5);
    lv_obj_set_width(ui_ButVent5m, 100);
    lv_obj_set_height(ui_ButVent5m, 50);
    lv_obj_set_x(ui_ButVent5m, -61);
    lv_obj_set_y(ui_ButVent5m, 61);
    lv_obj_set_align(ui_ButVent5m, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButVent5m, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButVent5m, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButVent5m, lv_color_hex(0x5A595A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButVent5m, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButVent5m, lv_color_hex(0x3975F6), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButVent5m, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label5 = lv_label_create(ui_ButVent5m);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "+5 min");

    ui_HeatPanel = lv_obj_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_width(ui_HeatPanel, lv_pct(49));
    lv_obj_set_height(ui_HeatPanel, lv_pct(48));
    lv_obj_set_align(ui_HeatPanel, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_HeatPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_HeatPanel, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HeatPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HeatPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_HeatPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_HeatPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_HeatPanel, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_HeatPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_heatTitle = lv_label_create(ui_HeatPanel);
    lv_obj_set_width(ui_heatTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_heatTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_heatTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_heatTitle, "Heater");
    lv_obj_set_style_text_color(ui_heatTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_heatTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_heatTitle, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButVent5m1 = lv_btn_create(ui_HeatPanel);
    lv_obj_set_width(ui_ButVent5m1, 100);
    lv_obj_set_height(ui_ButVent5m1, 50);
    lv_obj_set_x(ui_ButVent5m1, -45);
    lv_obj_set_y(ui_ButVent5m1, 61);
    lv_obj_set_align(ui_ButVent5m1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButVent5m1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButVent5m1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButVent5m1, lv_color_hex(0x5A595A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButVent5m1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButVent5m1, lv_color_hex(0x3975F6), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButVent5m1, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label1 = lv_label_create(ui_ButVent5m1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "+5 min");

    ui_ButVentOff1 = lv_btn_create(ui_HeatPanel);
    lv_obj_set_width(ui_ButVentOff1, 100);
    lv_obj_set_height(ui_ButVentOff1, 50);
    lv_obj_set_x(ui_ButVentOff1, -48);
    lv_obj_set_y(ui_ButVentOff1, -3);
    lv_obj_set_align(ui_ButVentOff1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButVentOff1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButVentOff1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButVentOff1, lv_color_hex(0x5A595A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButVentOff1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButVentOff1, lv_color_hex(0xC81A1A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButVentOff1, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Label2 = lv_label_create(ui_ButVentOff1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "OFF");

    ui_Container1 = lv_obj_create(ui_HeatPanel);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Container1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Container1, -20);
    lv_obj_set_y(ui_Container1, 20);
    lv_obj_set_align(ui_Container1, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container1, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButHeatUp = lv_imgbtn_create(ui_Container1);
    lv_imgbtn_set_src(ui_ButHeatUp, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_2127381671, NULL);
    lv_imgbtn_set_src(ui_ButHeatUp, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_2127381671, NULL);
    lv_obj_set_width(ui_ButHeatUp, 48);
    lv_obj_set_height(ui_ButHeatUp, 48);
    lv_obj_set_x(ui_ButHeatUp, 362);
    lv_obj_set_y(ui_ButHeatUp, -106);
    lv_obj_set_align(ui_ButHeatUp, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_ButHeatUp, 24, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_ButHeatUp, lv_color_hex(0xC81A1A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButHeatUp, 200, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_heatLab = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_heatLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_heatLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_heatLab, LV_ALIGN_CENTER);
    lv_label_set_text(ui_heatLab, "55");
    lv_obj_set_style_text_font(ui_heatLab, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButHeatDown = lv_imgbtn_create(ui_Container1);
    lv_imgbtn_set_src(ui_ButHeatDown, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_347167274, NULL);
    lv_imgbtn_set_src(ui_ButHeatDown, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_347167274, NULL);
    lv_obj_set_width(ui_ButHeatDown, 48);
    lv_obj_set_height(ui_ButHeatDown, 48);
    lv_obj_set_x(ui_ButHeatDown, 362);
    lv_obj_set_y(ui_ButHeatDown, -106);
    lv_obj_set_align(ui_ButHeatDown, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_ButHeatDown, 24, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_ButHeatDown, lv_color_hex(0x1A64B3), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButHeatDown, 200, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Container2 = lv_obj_create(ui_HeatPanel);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_width(ui_Container2, lv_pct(45));
    lv_obj_set_height(ui_Container2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Container2, -65);
    lv_obj_set_y(ui_Container2, -48);
    lv_obj_set_align(ui_Container2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_heatStatTitle = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_heatStatTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_heatStatTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_heatStatTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_heatStatTitle, "Status:  ");
    lv_obj_set_style_text_color(ui_heatStatTitle, lv_color_hex(0xA4A5A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_heatStatTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_heatStatLab = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_heatStatLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_heatStatLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_heatStatLab, LV_ALIGN_CENTER);

    ui_Panel4 = lv_obj_create(ui_HeatPanel);
    lv_obj_set_width(ui_Panel4, lv_pct(100));
    lv_obj_set_height(ui_Panel4, lv_pct(100));
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Panel4, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "TODO");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StartLog = lv_obj_create(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_CONTENTCONTAINER));
    lv_obj_set_width(ui_StartLog, lv_pct(105));
    lv_obj_set_height(ui_StartLog, lv_pct(105));
    lv_obj_set_align(ui_StartLog, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_StartLog, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_StartLog, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_StartLog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_StartLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_StartLog, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_StartLog, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_StartLog, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_StartLog, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_StartLog, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_startTitle = lv_label_create(ui_StartLog);
    lv_obj_set_width(ui_startTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_startTitle, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_startTitle, "************ Initializing HMI ************");

    ui_startLab = lv_label_create(ui_StartLog);
    lv_obj_set_width(ui_startLab, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_startLab, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_startLab, 1);
    lv_obj_set_y(ui_startLab, 25);
    lv_label_set_text(ui_startLab, "log");

    lv_obj_add_event_cb(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_SIDEBAR3_BUTTEMP2),
                        ui_event_HomeScreen_Sidebar3_butTemp2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_HomeScreen, UI_COMP_FULLSCREEN_SIDEBAR3_BUTAQ2),
                        ui_event_HomeScreen_Sidebar3_butAQ2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButVentOff, ui_event_ButVentOff, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButVent5m, ui_event_ButVent5m, LV_EVENT_ALL, NULL);

}

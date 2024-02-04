// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"
// SCREEN: ui_ScrHome
void ui_ScrHome_screen_init(void);
extern lv_obj_t * ui_ScrHome;
extern lv_obj_t * ui_FullScreen;
void ui_event_FullScreen_Sidebar3_butTemp2(lv_event_t * e);
void ui_event_FullScreen_Sidebar3_butAQ2(lv_event_t * e);
extern lv_obj_t * ui_Label1;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_count;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_StartLog;
extern lv_obj_t * ui_startLab;
extern lv_obj_t * ui_wifiLab;
extern lv_obj_t * ui_ipLab;
extern lv_obj_t * ui_timeLab;
extern lv_obj_t * ui_influxLab;
// SCREEN: ui_ScrCharts
void ui_ScrCharts_screen_init(void);
extern lv_obj_t * ui_ScrCharts;
extern lv_obj_t * ui_FullScreen1;
void ui_event_FullScreen1_Sidebar3_butHome2(lv_event_t * e);
void ui_event_FullScreen1_Sidebar3_butAQ2(lv_event_t * e);
extern lv_obj_t * ui_Chart1;
void ui_event_but6H(lv_event_t * e);
extern lv_obj_t * ui_but6H;
extern lv_obj_t * ui_Label3;
void ui_event_but1H(lv_event_t * e);
extern lv_obj_t * ui_but1H;
extern lv_obj_t * ui_Label7;
void ui_event_but3H(lv_event_t * e);
extern lv_obj_t * ui_but3H;
extern lv_obj_t * ui_Label6;
void ui_event_butTemp(lv_event_t * e);
extern lv_obj_t * ui_butTemp;
extern lv_obj_t * ui_Label8;
void ui_event_butAQ(lv_event_t * e);
extern lv_obj_t * ui_butAQ;
extern lv_obj_t * ui_Label9;
void ui_event_butPM(lv_event_t * e);
extern lv_obj_t * ui_butPM;
extern lv_obj_t * ui_Label10;
void ui_event_butHum(lv_event_t * e);
extern lv_obj_t * ui_butHum;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_LoadingPanel;
extern lv_obj_t * ui_loadingLab;
extern lv_obj_t * ui_Label12;
// SCREEN: ui_ScrTBD
void ui_ScrTBD_screen_init(void);
extern lv_obj_t * ui_ScrTBD;
extern lv_obj_t * ui_FullScreen2;
void ui_event_FullScreen2_Sidebar3_butHome2(lv_event_t * e);
void ui_event_FullScreen2_Sidebar3_butTemp2(lv_event_t * e);
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_home_png);    // assets\home.png
LV_IMG_DECLARE(ui_img_2110918543);    // assets\chart-48.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

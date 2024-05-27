// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"
    // SCREEN: ui_ScrHome
    void ui_ScrHome_screen_init(void);
    extern lv_obj_t *ui_ScrHome;
    extern lv_obj_t *ui_HomeScreen;
    void ui_event_HomeScreen_Sidebar3_butTemp2(lv_event_t *e);
    void ui_event_HomeScreen_Sidebar3_butAQ2(lv_event_t *e);
    extern lv_obj_t *ui_timeLab;
    extern lv_obj_t *ui_AirPanel;
    extern lv_obj_t *ui_outTempPanel;
    extern lv_obj_t *ui_tempTitle1;
    extern lv_obj_t *ui_outTempLab;
    extern lv_obj_t *ui_tempPanel;
    extern lv_obj_t *ui_tempTitle;
    extern lv_obj_t *ui_tempLab;
    extern lv_obj_t *ui_hmPanel;
    extern lv_obj_t *ui_humTitle;
    extern lv_obj_t *ui_humLab;
    extern lv_obj_t *ui_aqPanel;
    extern lv_obj_t *ui_aqTitle;
    extern lv_obj_t *ui_aqLab;
    extern lv_obj_t *ui_pmPanel;
    extern lv_obj_t *ui_pmTitle;
    extern lv_obj_t *ui_pmLab;
    extern lv_obj_t *ui_DoorsPanel;
    extern lv_obj_t *ui_doubleGdoorPanel;
    extern lv_obj_t *ui_doublGdoorTitle;
    extern lv_obj_t *ui_doubleGdoorLab;
    extern lv_obj_t *ui_outsidePdoorPanel;
    extern lv_obj_t *ui_outsidePdoorTitle;
    extern lv_obj_t *ui_outsidePdoorLab;
    extern lv_obj_t *ui_shopPdoorPanel;
    extern lv_obj_t *ui_shopPdoorTitle;
    extern lv_obj_t *ui_ShopPdoorLab;
    extern lv_obj_t *ui_singleGdoorPanel;
    extern lv_obj_t *ui_singleGdoorTitle;
    extern lv_obj_t *ui_singleGdoorLab;
    extern lv_obj_t *ui_VentPanel;
    extern lv_obj_t *ui_ventTitle;
    extern lv_obj_t *ui_Container5;
    extern lv_obj_t *ui_ventReqCont;
    extern lv_obj_t *ui_ventReqTitle;
    extern lv_obj_t *ui_ventReqLab;
    extern lv_obj_t *ui_ventStatCont;
    extern lv_obj_t *ui_ventStatTitle;
    extern lv_obj_t *ui_ventStatLab;
    void ui_event_ButVentOff(lv_event_t *e);
    extern lv_obj_t *ui_ButVentOff;
    extern lv_obj_t *ui_Label13;
    extern lv_obj_t *ui_ventTimerCont;
    extern lv_obj_t *ui_ventTimerTitle;
    extern lv_obj_t *ui_ventTimerLab;
    void ui_event_ButVent5m(lv_event_t *e);
    extern lv_obj_t *ui_ButVent5m;
    extern lv_obj_t *ui_Label5;
    extern lv_obj_t *ui_ventOffPanel;
    void ui_event_venfFanSwitch(lv_event_t *e);
    extern lv_obj_t *ui_venfFanSwitch;
    extern lv_obj_t *ui_HeatPanel;
    extern lv_obj_t *ui_heatTitle;
    extern lv_obj_t *ui_manualHeater;
    extern lv_obj_t *ui_heatTempCont;
    void ui_event_ButHeatUp(lv_event_t *e);
    extern lv_obj_t *ui_ButHeatUp;
    extern lv_obj_t *ui_heatTempLab;
    void ui_event_ButHeatDown(lv_event_t *e);
    extern lv_obj_t *ui_ButHeatDown;
    void ui_event_butHeat15m(lv_event_t *e);
    extern lv_obj_t *ui_butHeat15m;
    extern lv_obj_t *ui_Label1;
    extern lv_obj_t *ui_heatTimerCont;
    extern lv_obj_t *ui_heatTimerTitle;
    extern lv_obj_t *ui_heatTimerLab;
    extern lv_obj_t *ui_manualLab;
    extern lv_obj_t *ui_heatReqCont;
    extern lv_obj_t *ui_heatReqTitle;
    extern lv_obj_t *ui_heatReqLab;
    extern lv_obj_t *ui_heatStatCont;
    extern lv_obj_t *ui_heatStatTitle;
    extern lv_obj_t *ui_heatStatLab;
    extern lv_obj_t *ui_heaterOffPanel;
    void ui_event_heaterSwitch(lv_event_t *e);
    extern lv_obj_t *ui_heaterSwitch;
    extern lv_obj_t *ui_StartLog;
    extern lv_obj_t *ui_startTitle;
    extern lv_obj_t *ui_startLab;
    // SCREEN: ui_ScrCharts
    void ui_ScrCharts_screen_init(void);
    extern lv_obj_t *ui_ScrCharts;
    extern lv_obj_t *ui_FullScreen1;
    void ui_event_FullScreen1_Sidebar3_butHome2(lv_event_t *e);
    void ui_event_FullScreen1_Sidebar3_butAQ2(lv_event_t *e);
    extern lv_obj_t *ui_Chart1;
    void ui_event_but6H(lv_event_t *e);
    extern lv_obj_t *ui_but6H;
    extern lv_obj_t *ui_Label3;
    void ui_event_but1H(lv_event_t *e);
    extern lv_obj_t *ui_but1H;
    extern lv_obj_t *ui_Label7;
    void ui_event_but3H(lv_event_t *e);
    extern lv_obj_t *ui_but3H;
    extern lv_obj_t *ui_Label6;
    void ui_event_butTemp(lv_event_t *e);
    extern lv_obj_t *ui_butTemp;
    extern lv_obj_t *ui_Label8;
    void ui_event_butAQ(lv_event_t *e);
    extern lv_obj_t *ui_butAQ;
    extern lv_obj_t *ui_Label9;
    void ui_event_butPM(lv_event_t *e);
    extern lv_obj_t *ui_butPM;
    extern lv_obj_t *ui_Label10;
    void ui_event_butHum(lv_event_t *e);
    extern lv_obj_t *ui_butHum;
    extern lv_obj_t *ui_Label11;
    extern lv_obj_t *ui_LoadingPanel;
    extern lv_obj_t *ui_loadingLab;
    extern lv_obj_t *ui_Label12;
    // SCREEN: ui_ScrSettings
    void ui_ScrSettings_screen_init(void);
    extern lv_obj_t *ui_ScrSettings;
    extern lv_obj_t *ui_FullScreen2;
    void ui_event_FullScreen2_Sidebar3_butHome2(lv_event_t *e);
    void ui_event_FullScreen2_Sidebar3_butTemp2(lv_event_t *e);
    extern lv_obj_t *ui_Label4;
    extern lv_obj_t *ui_setTabView;
    extern lv_obj_t *ui_ventTabPage;
    void ui_event_KeyboardVent(lv_event_t *e);
    extern lv_obj_t *ui_KeyboardVent;
    extern lv_obj_t *ui_tempSettPanel;
    extern lv_obj_t *ui_Container30;
    extern lv_obj_t *ui_Label111;
    void ui_event_targTempMaxTA(lv_event_t *e);
    extern lv_obj_t *ui_targTempMaxTA;
    extern lv_obj_t *ui_Container10;
    extern lv_obj_t *ui_Label21;
    void ui_event_targTempMinTA(lv_event_t *e);
    extern lv_obj_t *ui_targTempMinTA;
    extern lv_obj_t *ui_Container11;
    extern lv_obj_t *ui_Label22;
    void ui_event_absTempMinTA(lv_event_t *e);
    extern lv_obj_t *ui_absTempMinTA;
    extern lv_obj_t *ui_Container7;
    extern lv_obj_t *ui_Label25;
    void ui_event_fanOnTempTA(lv_event_t *e);
    extern lv_obj_t *ui_fanOnTempTA;
    extern lv_obj_t *ui_Container8;
    extern lv_obj_t *ui_Label26;
    void ui_event_fanOffTempTA(lv_event_t *e);
    extern lv_obj_t *ui_fanOffTempTA;
    extern lv_obj_t *ui_tempSettLab;
    extern lv_obj_t *ui_aqSettPanel;
    extern lv_obj_t *ui_Container4;
    extern lv_obj_t *ui_Label19;
    void ui_event_aqMinTA(lv_event_t *e);
    extern lv_obj_t *ui_aqMinTA;
    extern lv_obj_t *ui_Container12;
    extern lv_obj_t *ui_Label23;
    void ui_event_fanOnAqTA(lv_event_t *e);
    extern lv_obj_t *ui_fanOnAqTA;
    extern lv_obj_t *ui_Container13;
    extern lv_obj_t *ui_Label24;
    void ui_event_fanOffAqTA(lv_event_t *e);
    extern lv_obj_t *ui_fanOffAqTA;
    extern lv_obj_t *ui_aqSettLab;
    extern lv_obj_t *ui_setTabPage;
    extern lv_obj_t *ui_Container9;
    extern lv_obj_t *ui_Label18;
    void ui_event_screenTimeDrop(lv_event_t *e);
    extern lv_obj_t *ui_screenTimeDrop;
    void ui_event_butRewifi(lv_event_t *e);
    extern lv_obj_t *ui_butRewifi;
    extern lv_obj_t *ui_Label16;
    void ui_event_butRemqtt(lv_event_t *e);
    extern lv_obj_t *ui_butRemqtt;
    extern lv_obj_t *ui_Label17;
    void ui_event_butReboot(lv_event_t *e);
    extern lv_obj_t *ui_butReboot;
    extern lv_obj_t *ui_Label15;
    extern lv_obj_t *ui_logTabPage;
    extern lv_obj_t *ui_logLab;
    // SCREEN: ui_ScrSleep
    void ui_ScrSleep_screen_init(void);
    extern lv_obj_t *ui_ScrSleep;
    extern lv_obj_t *ui_sleepTimeLab;
    extern lv_obj_t *ui____initial_actions0;

    LV_IMG_DECLARE(ui_img_home_png);   // assets\home.png
    LV_IMG_DECLARE(ui_img_2110918543); // assets\chart-48.png
    LV_IMG_DECLARE(ui_img_267769087);  // assets\icons8-settings-48.png
    LV_IMG_DECLARE(ui_img_2127381671); // assets\icons8-chevron-up-48.png
    LV_IMG_DECLARE(ui_img_347167274);  // assets\icons8-chevron-down-48.png

    void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

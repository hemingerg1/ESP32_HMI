
// void updateChart(lv_event_t *e);

void chartDataInt()
{
    lv_chart_series_t *ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x808080),
                                                                LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, data_array);
    // updateChart(NULL);
}

// Update chart
void updateChart(lv_event_t *e)
{
    // show data loading screen
    lv_obj_clear_flag(ui_LoadingPanel, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_loadingLab, "Loading Data...");
    lv_refr_now(NULL);

    // get data from influxdb
    int len = influxQuery(meas, String(chartLen));
    Serial.println("Influx return length: " + String(len));

    if (len != 0)
    {
        // adjust X axis for the data length
        lv_chart_set_point_count(ui_Chart1, len);
        lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_X, 10, 5, len / 20, 6, true, 30);
        lv_chart_set_div_line_count(ui_Chart1, 10, len / 20);

        // adjust Y axis range
        short int *data_min = std::min_element(data_array, data_array + len - 1) - 2;
        short int *data_max = std::max_element(data_array, data_array + len - 1) + 2;
        uint cmax = max(*data_max, soft_max);
        uint cmin = min(*data_min, soft_min);
        lv_chart_set_range(ui_Chart1, LV_CHART_AXIS_PRIMARY_Y, cmin, cmax);

        Serial.println("data_min: " + String(*data_min) + ",  soft_min: " + String(soft_min));
        Serial.println("data_max: " + String(*data_max) + ",  soft_max: " + String(soft_max));

        lv_chart_refresh(ui_Chart1);
        lv_obj_add_flag(ui_LoadingPanel, LV_OBJ_FLAG_HIDDEN);
    }
}

// Set chart length
void chart6H(lv_event_t *e)
{
    lv_obj_add_state(ui_but6H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but3H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but1H, LV_STATE_CHECKED);
    chartLen = 6;
    updateChart(e);
}
void chart3H(lv_event_t *e)
{
    lv_obj_add_state(ui_but3H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but6H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but1H, LV_STATE_CHECKED);
    chartLen = 3;
    updateChart(e);
}
void chart1H(lv_event_t *e)
{
    lv_obj_add_state(ui_but1H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but3H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but6H, LV_STATE_CHECKED);
    chartLen = 1;
    updateChart(e);
}

// Set chart data
void chartTemp(lv_event_t *e)
{
    lv_obj_add_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
    meas = "Temperature";
    soft_max = 75;
    soft_min = 40;
    updateChart(e);
}
void chartAQ(lv_event_t *e)
{
    lv_obj_add_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
    meas = "AQ";
    soft_max = 100;
    soft_min = 60;
    updateChart(e);
}
void chartPM(lv_event_t *e)
{
    lv_obj_add_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
    meas = "PM25";
    soft_max = 50;
    soft_min = 0;
    updateChart(e);
}
void chartHum(lv_event_t *e)
{
    lv_obj_add_state(ui_butHum, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
    meas = "Humidity";
    soft_max = 75;
    soft_min = 25;
    updateChart(e);
}

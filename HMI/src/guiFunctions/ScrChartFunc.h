
int chartLen = 120;
/*static lv_coord_t data_array[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; */

lv_coord_t data_array[240];
void chartDataInt()
{
    lv_chart_series_t *ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x808080),
                                                                LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, data_array);
}

// Update chart
void updateChart(lv_event_t *e)
{
    lv_chart_set_point_count(ui_Chart1, chartLen);

    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_X, 10, 5, chartLen / 10, 5, true, 30);
    lv_chart_set_div_line_count(ui_Chart1, 10, chartLen / 10);

    lv_chart_series_t *ser = lv_chart_get_series_next(ui_Chart1, NULL);
    uint i;
    Serial.println("data_array:");
    for (i = 0; i < chartLen; i++)
    {
        /*Set the next points on 'ser1'*/
        // lv_chart_set_value_by_id(ui_Chart1, ser, i, rand() % 100);
        data_array[i] = i;
        Serial.print(i); Serial.print(" = "); Serial.println(data_array[i]);
    }

    short int *data_min = std::min_element(data_array, data_array + chartLen);
    short int *data_max = std::max_element(data_array, data_array + chartLen);
    lv_chart_set_range(ui_Chart1, LV_CHART_AXIS_PRIMARY_Y, *data_min, *data_max);

    Serial.print("data_min: ");
    Serial.print(*data_min);
    Serial.print(",   data_max: ");
    Serial.println(*data_max);

    lv_chart_refresh(ui_Chart1);
}

// Set chart length
void chart2H(lv_event_t *e)
{
    lv_obj_add_state(ui_but2H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but1H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but30m, LV_STATE_CHECKED);
    chartLen = 240;
    updateChart(e);
}
void chart1H(lv_event_t *e)
{
    lv_obj_add_state(ui_but1H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but2H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but30m, LV_STATE_CHECKED);
    chartLen = 120;
    updateChart(e);
}
void chart30m(lv_event_t *e)
{
    lv_obj_add_state(ui_but30m, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but1H, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_but2H, LV_STATE_CHECKED);
    chartLen = 60;
    updateChart(e);
}

// Set chart data
void chartTemp(lv_event_t *e)
{
    lv_obj_add_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
}
void chartAQ(lv_event_t *e)
{
    lv_obj_add_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
}
void chartPM(lv_event_t *e)
{
    lv_obj_add_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butHum, LV_STATE_CHECKED);
}
void chartHum(lv_event_t *e)
{
    lv_obj_add_state(ui_butHum, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butAQ, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butPM, LV_STATE_CHECKED);
    lv_obj_clear_state(ui_butTemp, LV_STATE_CHECKED);
}

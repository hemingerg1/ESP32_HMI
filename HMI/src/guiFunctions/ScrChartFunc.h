
void chart2H(lv_event_t *e)
{
}
void chart1H(lv_event_t *e)
{
}
void chart30m(lv_event_t *e)
{
}

void updateChart(lv_event_t *e)
{
    uint32_t i;
    for (i = 0; i < 10; i++)
    {
        /*Set the next points on 'ser1'*/
        lv_chart_set_next_value(ui_Chart1, lv_chart_get_series_next(ui_Chart1, NULL), lv_rand(10, 50));
    }
    lv_chart_refresh(ui_Chart1);
}

void updateTime()
{
    lv_label_set_text_fmt(ui_timeLab, "%s", rtc.getTime("%I:%M"));
}
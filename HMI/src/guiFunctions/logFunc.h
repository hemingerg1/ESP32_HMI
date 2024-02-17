
void logAdd(bool time, String text)
{
    mylog += F("\n");
    if (time)
    {
        mylog += F("[");
        mylog += rtc.getTime("%D %T");
        mylog += F("]  ");
    }
    mylog += text;
    if (start)
    {
        lv_label_set_text(ui_startLab, mylog.c_str());
        lv_refr_now(NULL);
    }
    lv_label_set_text(ui_logLab, mylog.c_str());
}
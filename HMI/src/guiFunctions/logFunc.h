
void logAdd(bool time, String text)
{
    mylog += "\n";
    if (time)
    {
        mylog += "[";
        mylog += rtc.getTime("%D %T");
        mylog += "]  ";
    }
    mylog += text;
    lv_label_set_text(ui_startLab, mylog.c_str());
    lv_refr_now(NULL);
    lv_label_set_text(ui_logLab, mylog.c_str());
}
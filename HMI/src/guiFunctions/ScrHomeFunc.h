int cnt = 0;

void add(lv_event_t *e)
{
    cnt++;
    lv_label_set_text_fmt(ui_count, "%d", cnt);
}

void sub(lv_event_t *e)
{
    cnt--;
    lv_label_set_text_fmt(ui_count, "%d", cnt);
}
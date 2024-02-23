
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN);

void influxConnect()
{
    if (client.validateConnection())
    {
        Serial.print(F("Connected to InfluxDB: "));
        Serial.println(client.getServerUrl());
        logAdd(true, "Successfully connected to InfluxDB at: " + client.getServerUrl());
    }
    else
    {
        Serial.print(F("InfluxDB connection failed: "));
        Serial.println(client.getLastErrorMessage());
        logAdd(true, F("Was unable to connect to InfluxDB. Reason..."));
        logAdd(false, client.getLastErrorMessage());
    }
}

int influxQuery(String measurement, String time)
{
    String query = "from(bucket: \"" INFLUXDB_BUCKET "\") |> range(start: -" + time + "h) |> filter(fn: (r) => r._measurement == \"Air\" and r._field == \"" + measurement + "\") |> keep(columns: [\"_time\",\"_value\"])";

    // Serial.print("Querying with: ");
    // Serial.println(query);

    FluxQueryResult result = client.query(query);
    delay(20);

    uint i = 0;
    while (result.next())
    {
        // FluxDateTime time = result.getValueByName("_time").getDateTime();
        // String timeStr = time.format("%F %T");
        data_array[i] = result.getValueByName("_value").getDouble();
        i++;
    }

    /*
    // serial print data_array
    for (int j = 0; j < 500; j += 10)
    {
        Serial.print(data_array[j]);
        Serial.print(", ");
        Serial.print(data_array[j + 1]);
        Serial.print(", ");
        Serial.print(data_array[j + 2]);
        Serial.print(", ");
        Serial.print(data_array[j + 3]);
        Serial.print(", ");
        Serial.print(data_array[j + 4]);
        Serial.print(", ");
        Serial.print(data_array[j + 5]);
        Serial.print(", ");
        Serial.print(data_array[j + 6]);
        Serial.print(", ");
        Serial.print(data_array[j + 7]);
        Serial.print(", ");
        Serial.print(data_array[j + 8]);
        Serial.print(", ");
        Serial.print(data_array[j + 9]);
        Serial.println();
    }
    */

    // Check if there was an error
    if (result.getError().length() > 0)
    {
        Serial.print(F("Query result error: "));
        Serial.println(result.getError());

        logAdd(true, "Query result error: " + result.getError());

        lv_label_set_text_fmt(ui_loadingLab, "Query result error: %s", String(result.getError())); //.c_str()
        lv_refr_now(NULL);
        result.close();
        return 0;
    }

    if (i == 0)
    {
        lv_label_set_text_fmt(ui_loadingLab, "Query returned no data.");
        lv_refr_now(NULL);
    }

    // Close the result
    result.close();
    return i;
}
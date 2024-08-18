import pandas as pd
import datetime

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    res = {'id': []}

    if not weather.empty:
        weather.insert(len(weather.columns), 'lastDate', weather['recordDate'] - datetime.timedelta(days=1))

        df = weather.merge(weather, how='left', left_on='lastDate', right_on='recordDate')
        res['id'] = df[df['temperature_x'] > df['temperature_y']]['id_x']


    return pd.DataFrame(res)

if __name__ == '__main__':
    data = [[1, '2015-01-01', 10], [3, '2015-01-03', 20], [4, '2015-01-04', 30],  [2, '2015-01-02', 25]]
    weather = pd.DataFrame(data, columns=['id', 'recordDate', 'temperature']).astype({'id':'Int64', 'recordDate':'datetime64[ns]', 'temperature':'Int64'})

    r = rising_temperature(weather)
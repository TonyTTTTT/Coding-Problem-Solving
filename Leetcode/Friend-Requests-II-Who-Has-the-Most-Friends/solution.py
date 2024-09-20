import pandas as pd

def merge_id(row):
    return row['requester_id'] if pd.notnull(row['requester_id']) else row['accepter_id']

def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:
    requester_cnt = request_accepted['requester_id'].value_counts().reset_index('requester_id')
    accepter_cnt = request_accepted['accepter_id'].value_counts().reset_index('accepter_id')

    combined = requester_cnt.merge(accepter_cnt, how='outer', left_on='requester_id', right_on='accepter_id')
    combined['id'] = combined.apply(merge_id, axis=1)
    combined = combined.fillna(0)
    combined['num'] = combined['count_x'] + combined['count_y']
    
    ans = combined.iloc[[combined['num'].idxmax()]][['id', 'num']]

    return ans


if __name__ == '__main__':
    data = [[1, 2, '2016/06/03'], [1, 3, '2016/06/08'], [2, 3, '2016/06/08'], [3, 4, '2016/06/09']]
    request_accepted = pd.DataFrame(data, columns=['requester_id', 'accepter_id', 'accept_date']).astype({'requester_id':'Int64', 'accepter_id':'Int64', 'accept_date':'datetime64[ns]'})

    ans = most_friends(request_accepted)
import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    df = tree.merge(tree, how='left', left_on='id', right_on='p_id')
    df = df.drop_duplicates(subset='id_x')
    type_list = [] 

    for idx, row in df.iterrows():
        if pd.isnull(row['p_id_x']):
            type_list.append('Root')
        elif pd.isnull(row['id_y']):
            type_list.append('Leaf')
        else:
            type_list.append('Inner')

    res = pd.DataFrame({'id': df['id_x'], 'type': type_list})

    return res

if __name__ == '__main__':
    data = [[1, None], [2, 1], [3, 1], [4, 2], [5, 2]]
    tree = pd.DataFrame(data, columns=['id', 'p_id']).astype({'id':'Int64', 'p_id':'Int64'})

    r = tree_node(tree)
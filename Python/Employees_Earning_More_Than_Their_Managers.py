import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(right = employee, how = 'left', left_on = 'managerId', right_on = 'id')
    emp = df[df['salary_x'] > df['salary_y']]['name_x']

    return pd.DataFrame({'Employee': emp})


if __name__ == '__main__':
    employee = {
                'id': [1, 2, 3, 4],
                'name': ['Joe', 'Henry', 'Sam', 'Max'],
                'salary': [70000, 80000, 60000, 90000],
                'managerId': [3, 4, None, None]
                }
    employee = pd.DataFrame(employee)

    r = find_employees(employee)

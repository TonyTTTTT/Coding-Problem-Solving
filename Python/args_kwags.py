def sample(x, y, *args, **kwargs):
    print(x, y)
    for arg in args:
        print(arg)
    for kwarg in kwargs:
        print(kwarg, kwargs[kwarg])
sample(1, 2, 3, 4, 5, a=6, b=7)
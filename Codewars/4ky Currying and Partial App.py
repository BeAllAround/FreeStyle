from functools import partial;

def chain(f, *args): # classic chain
    if type(f) == partial:
        return f(*args);
    elif not callable(f):
        return f;
    try:
        arr = [];
        for arg in args:
            arr.append(arg);
            try:
                return f(*arr);
            except TypeError:
                pass;
        return f();
    except TypeError:
        pass;
    return partial(chain, f, *args);

def curry_partial(f, *args):
    return chain(f, *args);

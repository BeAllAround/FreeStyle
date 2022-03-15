def compose(f,g): # easy peasy
    return lambda *args: f(g(*args));

def alphanumeric(password):
    data = {'alpha': 0}
    for item in password:
        if item.isalpha():
            data['alpha'] += 1
        elif item.isdigit():
            pass
        else:
            return False
    if data['alpha'] == 0:
        return False
    return True

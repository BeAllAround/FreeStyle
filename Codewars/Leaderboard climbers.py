def leaderboard_sort(leaderboard, changes):
    for user in changes:
        u, n = user.split(' ')
        n = int(n)
        inx = leaderboard.index(u)
        i = leaderboard[inx]
        del leaderboard[inx]
        leaderboard.insert(inx-n, i)
    return leaderboard
  
'''
    # Codewars
    def leaderboard_sort(leaderboard, changes):
        for change in changes:
            name, delta = change.split()
            idx = leaderboard.index(name)
            leaderboard.insert(idx - int(delta), leaderboard.pop(idx))
        return leaderboard
'''

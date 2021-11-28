def max_sum_path(l1, l2):
    _max = [sum(l1), sum(l2)];
    index = -1;
    index2 = -1;
    pos = [];
    for i in range(len(l1)):
        for j in range(len(l2)):
            if(l1[i] == l2[j]):
                pos.append([i, j]);
                break;
    if(pos == []):
        return (max(_max));
    for item in pos:
        _max.append(sum(l1[:item[0]] +  l2[item[1]:]));
        _max.append(sum(l2[:item[1]] + l1[item[0]:]));
    return max(_max);

def max_sum_path(l1, l2):
    _max = [sum(l1), sum(l2)];
    index = -1;
    index2 = -1;
    for i in range(len(l1)):
        for j in range(len(l2)):
            if(l1[i] == l2[j]):
                index = i;
                index2 = j;
                break;
        if(index!=-1):
            break
    if(index == -1):
        return (max(_max));
    _max.append(sum(l1[:index] +  l2[index2::]));
    _max.append(sum(l2[:index2] + l1[index::]));
    return max(_max);

for i in range(101):
    aNum=pow(i,3)
    for j in range(2,i):
        bNum=pow(j,3)
        for k in range(j,i):
            cNum=pow(k,3)
            for n in range(k,i):
                dNum=pow(n,3)
                if aNum==(bNum+cNum+dNum):
                    print('Cube = {0}, Triple = ({1},{2},{3})'.format(i,j,k,n))
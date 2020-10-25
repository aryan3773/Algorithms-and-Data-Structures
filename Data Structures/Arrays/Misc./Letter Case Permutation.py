l = []

def subset(x, y):
    if(len(x) == 0):
        l.append(y)
        return ;
    
    if(x[0].isalpha()):
        subset(x[1:], y+x[0])
        subset(x[1:], y+x[0].upper())
        
    else:
        subset(x[1:], y+x[0])
    
x = input()
subset(x, "")

print(l)
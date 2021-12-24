
def Model(dic, VM):
    if VM in dic.keys() :    
        return dic[VM]
    else:
        return -1

def Change(dic, VM):
    if VM in dic.keys():
        if dic[VM] > 5:
            dic[VM] = dic[VM]-2
        else:
            del dic[VM]

# swap the values of Tuple1 and Tuple2.
def swapTuples(tup1,tup2):
    tup1,tup2 = tup2,tup1
        
def Div3and5(tup10):
    if len(tup10) == 10:
        three=0
        five=0
        threeN5=0
        for i in tup10:
            if i%3 == 0:
                three = three+i
            if i%5==0:
                five = five+i
            if i%3==0 and i%5==0:
                threeN5 = threeN5+i
        return (three,five,threeN5)
        

def main():
    Dict1 = {'BMW' :5, 'Mercedes': 10, 'Volkswagen': 10, 'Jaguar': 4, 'Landrover':15}
    Tuple1 = (11,22,33)
    Tuple2 = (99,88,77)
    Tuple3 = (11,22,33,90,88,77,54,27,40, 30)
    
    print(Model(Dict1,'BMW'))
    print(Model(Dict1,'BM'))
    
    Change(Dict1,'Mercedes')
    Change(Dict1,'BMW')
    print(Dict1)
    
    print(Tuple1,Tuple2)
    swapTuples(Tuple1,Tuple2)
    # Tuple1, Tuple2 = Tuple2, Tuple1
    print(Tuple1,Tuple2)
    
    print(Div3and5(Tuple3))

main()
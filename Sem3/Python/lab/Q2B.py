def monthlysale(weeklysale) :
    assert weeklysale > 0 
    return 4 * weeklysale

def commission(monthlysale) : 
    assert monthlysale > 0
    return monthlysale * 0.5

def remark(monthlysale) : 
    if monthlysale >= 80000 : return 'Excellent'
    elif monthlysale >= 60000 and monthlysale < 80000 : return 'Good'
    elif monthlysale >= 40000 and monthlysale < 60000 : return 'Average'
    else : return 'Work Hard'

def empEval(weeklysale) : 
    return (
    monthlysale(weeklysale), 
    commission(monthlysale(weeklysale)),
    remark(monthlysale(weeklysale))
    )

if __name__ == '__main__' :
    weeklysale = float(input('Enter weekly sale of Employee : '))
    empData = empEval(weeklysale)
    print('Monthy Sale = ', empData[0],
          '\nCommission = ', empData[1],
          '\nRemark = ', empData[2])
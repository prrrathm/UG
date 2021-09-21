def evaluate(empno, weeklysale) :
    monthlysale = weeklysale * 4

    if monthlysale >= 80000 :
        remark = 'Excellent'
    elif monthlysale >= 60000 and monthlysale < 80000 :
        remark = 'Good'
    elif monthlysale >= 40000 and monthlysale < 60000 :
        remark = 'Average'
    elif monthlysale < 40000 :
        remark = 'Work Hard'

    commission = 0.0    
    if monthlysale > 50000 :
        commission = 0.05 * monthlysale

    evaluation = [
        'Employee No. : ' + str(empno),
        'sale in month : ' + str(monthlysale),
        'remark : ' + remark,
        'commission : ' + str(commission)
    ]

    return evaluation

#MAIN CODE

# n = int(input('\nNo of Salesmen : '))

# empdata = []
# for i in range(1, n+1) :
sale = float(input('Weekly sale : '))
empdata = evaluate(1, sale)

print(
    'Evaluation of Employee \n', 
    empdata,
    end='\n\n'
    )

# 'Employee No. : ' + str(empno),
# 'sale in month : ' + str(monthlysale),
# 'remark : ' + remark,
# 'commission : ' + str(commission)
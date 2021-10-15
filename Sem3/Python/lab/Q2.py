def monthlysale(weeklysale) : 
    return 4 * weeklysale

def commission(monthlysale) : return monthlysale * 0.5

def remark(monthlysale) : 
    if monthlysale >= 80000 : return 'Excellent'
    elif monthlysale >= 60000 and monthlysale < 80000 : return 'Good'
    elif monthlysale >= 40000 and monthlysale < 60000 : return 'Average'
    else : return 'Work Hard'

weeklysale = float(input('Enter weekly sale of Employee : '))

employeeEvaluation = [
    monthlysale(weeklysale), 
    commission(monthlysale(weeklysale)),
    remark(monthlysale(weeklysale))
    ]

print('Evaluation of Employee = ', employeeEvaluation)
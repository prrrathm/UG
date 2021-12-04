# create a class Account where you can store account number, balance, annual Interest Rate. 
# Instantiate all these fields to 0. 
# You can ComputeMonthlyInterest() for the account holder by balance * monthlyInterestRate.
# Create deposit() and withdraw() from an account. 
# monthlyInterestRate = annualInterestRate/12. 
# Note interest is stored in %, i.e. if annualInterestRate is 3, it means 3%. 
# Save interest earned every month in a dictionary. 
# Write other functions as required. 
# Display monthly interest and final balance for an account holder. 
# Throw exceptions if annualInterstRate<=2% or account number is -ve.

class Account:
    account_number = 0
    balance = 0
    annual_interestRate = 0

    def __init__(self, account_number, balance, annual_interestRate):
        assert annual_interestRate <= 2
        self.account_number = account_number
        self.balance = balance
        self.annual_interestRate = annual_interestRate

    # Function to compute monthly interest
    def ComputeMonthlyInterest(self):
        interest = dict()
        monthly_interestRate = self.annual_interestRate / 12
        amount = 0
        tempBal = self.balance
        for i in range(12) :
            tempBal = tempBal + tempBal * monthly_interestRate
            amount = tempBal - self.balance
            interest[i+1] = round(amount,3)
        self.balance = self.balance + interest[12]
        return interest

    # Function to withdraw the amount
    def withdraw(self):
        amount = float(input("Enter amount to be withdrawn: "))
        if self.balance >= amount:
            self.balance -= amount
            print("\n You Withdrew:", amount)
        else:
            print("\n Insufficient balance  ")

    # Function to withdraw the amount
    def deposit(self):
        amount = float(input("Enter amount to be deposited: "))
        self.balance += amount
        print(f"\n Amount Deposited: {amount}")

    # Function to show left balanc
    def final_balance(self):
        return self.balance

    def display(self, final_balance):
        print(f"Monthly Interest: {self.ComputeMonthlyInterest()}\n"
          f"Final Balance of Account no. {self.account_number}: {self.final_balance}")


def main():
    account_number = int(input("Enter the Account Number(16 digits): "))
    balance = int(input("Enter the balance in the account: "))
    annual_interestRate = int(input("Enter the interest rate (in %): "))/100

    if account_number < 0 and annual_interestRate <= 2:
        raise Exception("Invalid Input")
    
    raman = Account(account_number, balance, annual_interestRate)
    
    while True:
        choice = int(input("Select the option:\n1. Withdraw\n2. Deposit\n3. Balance\n4.Monthly Interest and Final Balance\n5.Exit"))

        if choice == 1:
            raman.withdraw()

        elif choice == 2:
            raman.deposit()

        elif choice == 3:
            print(raman.final_balance())

        elif choice == 4:
            interest = raman.ComputeMonthlyInterest()
            print(
                "\nInterest over 12 months : ", 
                interest,
                "\nFinal Balance : ", raman.balance + interest[12], "\n" )
            
        elif choice == 5 :
            exit()
        else:
            print("Invalid Input!")


if __name__ == '__main__':
    main()
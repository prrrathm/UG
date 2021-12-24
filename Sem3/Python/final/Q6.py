class Product():
    count = 0
    def __init__(self,name,material,price):
        self.name = name
        self.material = material

        assert price > 25 and price < 250, "Price Should be between 25 and 250"
        self.costPrice = price

        if(material == "Metal"):
            self.discount = (self.costPrice*20)/100
        else:
            self.discount = (self.costPrice*10)/100

        assert Product.count >= 0, "Count should be greater than or equal to zero"
        Product.count += 1

    def sellingPrice(self):
        self.sellingPrice=self.costPrice-self.discount
        print("Selling Price is ", self.sellingPrice)
    
    def display(self):
        print("Name =>" + self.name)
        print("Material =>"+self.material)
        print("Cost Price =>"+str(self.costPrice))
        print("Discount =>"+str(self.discount))
        print("Selling price =>"+str(self.sellingPrice)) 

def main():
    plate = Product("Plate", "Metal", 170)
    plate.sellingPrice()
    plate.display()
    print("Value of count is ", Product.count)

    spoon = Product("Spoon", "Plastic", 26)
    print("Value of count is ", Product.count)
    
main()
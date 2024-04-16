def discount_percentage(packages):
    if packages >= 100:
        discount = 0.5
    elif packages >= 50:
        discount = 0.4
    elif packages >= 20:
        discount = 0.3
    elif packages >= 10:
        discount = 0.2
    elif packages >= 0:
        discount = 0
    else:
        discount = 'Error'

    return discount
def main():
    try:
        packages = int(input('Please enter the number of packages: '))

        percentage = discount_percentage(packages) * 100
        print('The discount percentage is {:.2f}'.format(percentage), '%')

        discount_amount = percentage * 99 * packages / 100
        print('The discount amount is ${:.2f}'.format(discount_amount))
        
        total_amount = (99 * packages) - (discount_amount)
        print('The total amount is ${:.2f}'.format(total_amount))



    except ValueError as err:
        print('Please try again using a positive number.')

    
        
